/**
 * $Id$
 *
 * \file array_manip/src/mult_scalar_vec_ncerr.cpp
 */
#include "mult_scalar_vec_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_scalar_vec_ncerr<float>(Nessi::Vector<float> const & array_in, 
			       Nessi::Vector<float> const & array_in_err2, 
			       Nessi::Vector<float> & array_out,
			       Nessi::Vector<float> & array_out_err2,
			       float scalar, float scalar_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_scalar_vec_ncerr<double>(Nessi::Vector<double> const & array_in, 
				Nessi::Vector<double> const & array_in_err2, 
				Nessi::Vector<double> & array_out,
				Nessi::Vector<double> & array_out_err2,
				double scalar, double scalar_err2,
				void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_scalar_vec_ncerr<int>(Nessi::Vector<int> const & array_in, 
			     Nessi::Vector<int> const & array_in_err2, 
			     Nessi::Vector<int> & array_out,
			     Nessi::Vector<int> & array_out_err2,
			     int scalar, int scalar_err2,
			     void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_scalar_vec_ncerr<unsigned int>(
                            Nessi::Vector<unsigned int> const & array_in, 
                            Nessi::Vector<unsigned int> const & array_in_err2, 
                            Nessi::Vector<unsigned int> & array_out,
                            Nessi::Vector<unsigned int> & array_out_err2,
                            unsigned int scalar, 
                            unsigned int scalar_err2,
                            void *temp);
  
} // ArrayManip 

