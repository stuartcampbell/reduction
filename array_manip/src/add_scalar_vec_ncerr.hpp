/**
 * $Id$
 *
 * \file array_manip/src/add_scalar_vec_ncerr.hpp
 */
#ifndef _ADD_SCALAR_VEC_NCERR_H
#define _ADD_SCALAR_VEC_NCERR_H 1

#include "vec_scalar_arith.hpp"
#include <string>

namespace ArrayManip
{
  // 3.1
  template <typename NumT>
  std::string 
  add_scalar_vec_ncerr(Nessi::Vector<NumT> const & array_in, 
		       Nessi::Vector<NumT> const & array_in_err2, 
		       Nessi::Vector<NumT> & array_out,
		       Nessi::Vector<NumT> & array_out_err2,
		       NumT scalar, NumT scalar_err2,
		       void *temp=NULL)
  {
    std::string errstr("");

    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
	array_out[i] = array_in[i] + scalar;
	array_out_err2[i] = array_in_err2[i] + scalar_err2;
      }
    return errstr;
  }  
} // ArrayManip 

#endif // _ADD_SCALAR_VEC_NCERR_H