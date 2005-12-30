/**
 * $Id$
 *
 * \file axis_manip/src/frequency_to_angular_frequency.cpp
 */
#include "frequency_to_angular_frequency.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.31.
   *
   * \see frequency_to_angular_frequency()
   */
  template std::string
  frequency_to_angular_frequency<float>(
                                 Nessi::Vector<float> const & frequency,
                                 Nessi::Vector<float> const & frequency_err2,
                                 Nessi::Vector<float> & angular_frequency,
                                 Nessi::Vector<float> & angular_frequency_err2,
                                 void *temp);
  
  /**
   * This is the float declaration of the function defined in 3.31.
   *
   * \see frequency_to_angular_frequency()
   */
  template std::string
  frequency_to_angular_frequency<float>(const float frequency,
                                        const float frequency_err2,
                                        float & angular_frequency,
                                        float & angular_frequency_err2,
                                        void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.31.
   *
   * \see frequency_to_angular_frequency()
   */
  template std::string
  frequency_to_angular_frequency<double>(
                                Nessi::Vector<double> const & frequency,
                                Nessi::Vector<double> const & frequency_err2,
                                Nessi::Vector<double> & angular_frequency,
                                Nessi::Vector<double> & angular_frequency_err2,
                                void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.31.
   *
   * \see frequency_to_angular_frequency()
   */
  template std::string
  frequency_to_angular_frequency<double>(const double frequency,
                                         const double frequency_err2,
                                         double & angular_frequency,
                                         double & angular_frequency_err2,
                                         void *temp);
} // AxisManip
