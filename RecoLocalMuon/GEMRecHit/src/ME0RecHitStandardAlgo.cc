/*
 *  See header file for a description of this class.
 *
 *  $Date: 2014/02/04 10:16:35 $
 *  $Revision: 1.1 $
 *  \author M. Maggi -- INFN
 */

#include "RecoLocalMuon/GEMRecHit/src/ME0RecHitStandardAlgo.h"
#include "DataFormats/MuonDetId/interface/ME0DetId.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Utilities/interface/Exception.h"


ME0RecHitStandardAlgo::ME0RecHitStandardAlgo(const edm::ParameterSet& config) :
  ME0RecHitBaseAlgo(config) 
{
}

ME0RecHitStandardAlgo::~ME0RecHitStandardAlgo() 
{
}

void ME0RecHitStandardAlgo::setES(const edm::EventSetup& setup) 
{
}

// First Step
bool ME0RecHitStandardAlgo::compute(const ME0DigiPreReco& digi,
				    LocalPoint& Point,
				    LocalError& error)  const
{
  LocalPoint loctemp2(digi.x(),digi.y(),0.);
  Point = loctemp2;
  float erx = 0.0001;
  if (digi.ex() > erx) erx = digi.ex();
  float ery = 0.0001;
  if (digi.ey() > ery) ery = digi.ey();
  LocalError loerr2(erx*erx,digi.corr()*erx*ery,ery*ery);
  error = loerr2;
  return true;
}

