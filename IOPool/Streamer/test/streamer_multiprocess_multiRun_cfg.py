# Configuration file for EmptySource

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.load("FWCore.Framework.test.cmsExceptionsFatal_cff")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(40)
)

process.options = cms.untracked.PSet(multiProcesses=cms.untracked.PSet(
        maxChildProcesses=cms.untracked.int32(3),
        maxSequentialEventsPerChild=cms.untracked.uint32(2)))


process.source = cms.Source("NewEventStreamFileReader", fileNames = cms.untracked.vstring("file:multiprocess_oneLumi_test.dat","file:multiprocess_oneLumi2_test.dat"))

ids = cms.VEventID()
numberOfEventsInRun = 0
numberOfEventsPerRun = 20
run = 101
event=0
for i in xrange(40):
   numberOfEventsInRun +=1
   event += 1
   if numberOfEventsInRun > numberOfEventsPerRun:
      numberOfEventsInRun=1
      run += 1
      event = 1
   ids.append(cms.EventID(run,event))
process.check = cms.EDAnalyzer("EventIDChecker", 
                                eventSequence = cms.untracked(ids),
                                multiProcessSequentialEvents = process.options.multiProcesses.maxSequentialEventsPerChild)
process.print1 = cms.OutputModule("AsciiOutputModule")

process.p = cms.EndPath(process.check+process.print1)
