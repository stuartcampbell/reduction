/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 *
 * For this software and its associated documentation, permission is granted
 * to reproduce, prepare derivative works, and distribute copies to the public
 * for any purpose and without fee.
 *
 * This material was prepared as an account of work sponsored by an agency of
 * the United States Government.  Neither the United States Government nor the
 * United States Department of Energy, nor any of their employees, makes any
 * warranty, express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or represents that
 * its use would not infringe privately owned rights.
 *
 */

/**
 * $Id$
 *
 * \file array_manip/src/add_ncerr.hpp
 */
#ifndef _ADD_NCERR_HPP
#define _ADD_NCERR_HPP 1

#include "arith.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <algorithm>
#include <stdexcept>

namespace ArrayManip
{
  /// String for holding the addition function name
  const std::string add_func_str = "ArrayManip::add_ncerr";

  // 3.1
  template <typename NumT>
  std::string
  add_ncerr(const Nessi::Vector<NumT> & array_in,
            const Nessi::Vector<NumT> & array_in_err2,
            const NumT scalar,
            const NumT scalar_err2,
            Nessi::Vector<NumT> & array_out,
            Nessi::Vector<NumT> & array_out_err2,
            void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(array_in,array_out);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (v,s): data "+e.what());
      }
    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(array_in_err2,array_out_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (v,s): err2 "+e.what());
      }
    // check that the input arrays are of proper size
    try
      {
        Utils::check_sizes_square(array_in,array_in_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (v,s): input "+e.what());
      }

    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
        array_out[i] = array_in[i] + scalar;
        array_out_err2[i] = array_in_err2[i] + scalar_err2;
      }
    return Nessi::EMPTY_WARN;
  }

  // 3.6
  template <typename NumT>
  std::string
  add_ncerr(const Nessi::Vector<NumT> & input1,
            const Nessi::Vector<NumT> & input1_err2,
            const Nessi::Vector<NumT> & input2,
            const Nessi::Vector<NumT> & input2_err2,
            Nessi::Vector<NumT> & output,
            Nessi::Vector<NumT> & output_err2,
            void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(input1,input2,output);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (v,v): data "+e.what());
      }
    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(input1_err2,input2_err2,output_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (v,v): err2 "+e.what());
      }
    // check that the input1 arrays are of proper size
    try
      {
        Utils::check_sizes_square(input1,input1_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (v,v): input1 "+e.what());
      }

    std::transform(input1.begin(), input1.end(), input2.begin(),
                   output.begin(), std::plus<NumT>());
    std::transform(input1_err2.begin(), input1_err2.end(),
                   input2_err2.begin(), output_err2.begin(),
                   std::plus<NumT>());

    return Nessi::EMPTY_WARN;
  }

  // 3.6
  template <typename NumT>
  std::string
  add_ncerr(const NumT input1,
            const NumT input1_err2,
            const NumT input2,
            const NumT input2_err2,
            NumT & output,
            NumT & output_err2,
            void *temp=NULL)
  {
    output = input1 + input2;
    output_err2 = input1_err2 + input2_err2;

    return Nessi::EMPTY_WARN;
  }

  // 3.6 for multi-dimensional as 1D
  template <typename NumT>
  std::string
  add_ncerr(const Nessi::Vector<NumT> & input1,
            const Nessi::Vector<NumT> & input1_err2,
            const size_t i1_start,
            const size_t i1_span,
            const Nessi::Vector<NumT> & input2,
            const Nessi::Vector<NumT> & input2_err2,
            const size_t i2_start,
            const size_t i2_span,
            const size_t size,
            Nessi::Vector<NumT> & output,
            Nessi::Vector<NumT> & output_err2,
            const size_t o_start,
            const size_t o_span,
            void *temp=NULL)
  {
    // check that the input1 arrays are of proper size
    try
      {
        Utils::check_sizes_square(input1,input1_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (m:v,v): input1 "+e.what());
      }
    // check that the input2 arrays are of proper size
    try
      {
        Utils::check_sizes_square(input2,input2_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (m:v,v): input2 "+e.what());
      }
    // check that the output arrays are of proper size
    try
      {
        Utils::check_sizes_square(output,output_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(add_func_str+" (m:v,v): output "+e.what());
      }

    if((i1_start + size * i1_span) > input1.size()) 
      {
        throw std::invalid_argument(add_func_str+" i1_start + size will "+\
                                    "overrun input1");
      }

    if((i2_start + size * i2_span) > input2.size()) 
      {
        throw std::invalid_argument(add_func_str+" i2_start + size will "+\
                                    "overrun input2");
      }

    if((o_start + size * o_span) > output.size()) 
      {
        throw std::invalid_argument(add_func_str+" o_start + size will "+\
                                    "overrun output");
      }

    size_t i;
    size_t j;
    size_t k;

    std::size_t stopping_criteria = i2_start + i2_span * size;

    for(i = i1_start, j = i2_start, k = o_start; j < stopping_criteria;
        i += i1_span, j += i2_span, k += o_span)
      {
        output[k] = input1[i] + input2[j];
        output_err2[k] = input1_err2[i] + input2_err2[j];
      }

    return Nessi::EMPTY_WARN;
  }
} // ArrayManip

#endif // _ADD_NCERR_HPP
