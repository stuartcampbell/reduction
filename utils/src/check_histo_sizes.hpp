/**
 * $Id$
 *
 * \file utils/src/check_histo_sizes.hpp
 */
#ifndef _CHECK_HISTO_SIZES_HPP
#define _CHECK_HISTO_SIZES_HPP 1

#include "size_checks.hpp"
#include <stdexcept>

namespace Utils
{
  template <typename NumT>
  void 
  check_histo_sizes(std::string & errstr,
		    const Nessi::Vector<NumT> & input,
		    const Nessi::Vector<NumT> & input_err2,
		    const Nessi::Vector<NumT> & axis)
  {
    size_t size = input.size();
    size_t size_err2 = input_err2.size();
    size_t size_axis = axis.size();

    if (size != size_err2)
      {
	errstr += "input and input_err2 are not the same size";
	throw std::invalid_argument(errstr);
      }

    if(size_axis != size+1)
      {
	errstr += "axis size is not input size + 1";
	throw std::invalid_argument(errstr);
      }

    if(size_axis != size_err2+1)
      {
	errstr += "axis size is not input_err2 size + 1";
	throw std::invalid_argument(errstr);
      }

    return;
  }
} // Utils

#endif // _CHECK_HISTO_SIZES_HPP