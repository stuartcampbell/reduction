/**
 * $Id$
 *
 * \file array_manip/src/sumw_ncerr.hpp
 */
#ifndef _SUMW_NCERR_HPP
#define _SUMW_NCERR_HPP 1

#include "arith.hpp"
#include "check_inputs.hpp"
#include <cmath>
#include <stdexcept>

namespace ArrayManip
{
  // 3.10
  template <typename NumT>
  std::string 
  sumw_ncerr(const Nessi::Vector<NumT> & input1, 
             const Nessi::Vector<NumT> & input1_err2, 
             const Nessi::Vector<NumT> & input2, 
             const Nessi::Vector<NumT> & input2_err2, 
             Nessi::Vector<NumT> & output,
             Nessi::Vector<NumT> & output_err2,
             void *temp=NULL)
  {
    std::string retstr("");

    try 
      {
	std::string errstr("ArrayManip::sumw_vec_vec_ncerr: data ");
	check_sizes_2in1out(errstr, input1, input2, output);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    try 
      {
	std::string errstr("ArrayManip::sumw_vec_vec_ncerr: error ");
	check_sizes_2in1out(errstr, input1_err2, input2_err2, output_err2);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    size_t sz = input1.size();
    for (size_t i = 0; i < sz; ++i)
      {
	NumT input1_err =
          static_cast<NumT>(std::sqrt(static_cast<double>(input1_err2[i])));
	NumT input2_err =
          static_cast<NumT>(std::sqrt(static_cast<double>(input2_err2[i])));
	NumT sum_err = input1_err + input2_err;
	output[i] = (input1[i] / input1_err) + (input2[i] / input2_err);
	output[i] *= sum_err;
	output_err2[i] = input1_err2[i] + input2_err2[i];
      }

    return retstr;
  }
} // ArrayManip

#endif // _SUMW_NCERR_HPP