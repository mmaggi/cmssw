#include "CondFormats/OptAlignObjects/interface/OpticalAlignments.h"
#include "CondFormats/OptAlignObjects/interface/OpticalAlignInfo.h"

#include "FWCore/EDProduct/interface/Wrapper.h"

#include <string>
#include <vector>

template std::vector<OpticalAlignInfo>::iterator;
template std::vector<OpticalAlignParam>::iterator;
template std::vector< int >::iterator;
template std::vector< int >::const_iterator;
//template edm::Wrapper<OpticalAlignments>;
namespace {
  namespace {
    edm::Wrapper<OpticalAlignments> tw;
  }
}
