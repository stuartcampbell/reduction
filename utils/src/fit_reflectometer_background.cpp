/**
 * $Id$
 *
 * \file utils/src/fit_reflectometer_background.cpp
 */
#include "fit_reflectometer_background.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.42.
   *
   * \see fit_reflectometer_background()
   */
  template std::string
  fit_reflectometer_background<float>(std::vector<float> const & axis_in,
				      std::vector<float> const & input,
				      std::vector<float> const & input_err2,
				      std::vector<float> const & params_in,
				      std::vector<float> & output,
				      std::vector<float> & output_err2,
				      std::vector<float> & params_out,
				      std::vector<float> & params_out_err2,
				      void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.42.
   *
   * \see fit_reflectometer_background()
   */
  template std::string
  fit_reflectometer_background<double>(std::vector<double> const & axis_in,
				       std::vector<double> const & input,
				       std::vector<double> const & input_err2,
				       std::vector<double> const & params_in,
				       std::vector<double> & output,
				       std::vector<double> & output_err2,
				       std::vector<double> & params_out,
				       std::vector<double> & params_out_err2,
				       void *temp);
} // Utils
