/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_tof.hpp
 */
#include "constants.hpp"
#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(Nessi::Vector<NumT> const & wavelength,
		    Nessi::Vector<NumT> const & wavelength_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    Nessi::Vector<NumT> & tof,
		    Nessi::Vector<NumT> & tof_err2,
		    void *temp=NULL)
  {
    // VARIABLES WITH BAD NAMES: a, a2, b, c

    NumT a = static_cast<NumT>(1 / (PhysConst::H_OVER_MNEUT));
    NumT a2 = a * a;
    a = a * pathlength;
    
    NumT b = pathlength * pathlength;
    
    NumT c = pathlength_err2 * pathlength_err2;
    
    size_t size_wavelength = wavelength.size();
    for (size_t i = 0; i < size_wavelength ; ++i)
      {
	tof[i] = a * wavelength[i];
	tof_err2[i] = wavelength[i] * wavelength[i] * c;
	tof_err2[i] += b * (wavelength_err2[i] * wavelength_err2[i]);
        tof_err2[i] *= a2;
      }
    
    std::string retstr("");
    return retstr;
  }
} // AxisManip
