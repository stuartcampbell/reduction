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
 * \file axis_manip/src/wavelength_to_tof.cpp
 */
#include "wavelength_to_tof.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.16.
   *
   * \ingroup wavelength_to_tof
   */
  template std::string
  wavelength_to_tof<float>(const Nessi::Vector<float> & wavelength,
                           const Nessi::Vector<float> & wavelength_err2,
                           const float pathlength,
                           const float pathlength_err2,
                           Nessi::Vector<float> & tof,
                           Nessi::Vector<float> & tof_err2,
                           void *temp);

  /**
   * This is the float declaration of the function defined in 3.16.
   *
   * \ingroup wavelength_to_tof
   */
  template std::string
  wavelength_to_tof<float>(const float wavelength,
                           const float wavelength_err2,
                           const float pathlength,
                           const float pathlength_err2,
                           float & tof,
                           float & tof_err2,
                           void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.16.
   *
   * \ingroup wavelength_to_tof
   */
  template std::string
  wavelength_to_tof<double>(const Nessi::Vector<double> & wavelength,
                            const Nessi::Vector<double> & wavelength_err2,
                            const double pathlength,
                            const double pathlength_err2,
                            Nessi::Vector<double> & tof,
                            Nessi::Vector<double> & tof_err2,
                            void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.16.
   *
   * \ingroup wavelength_to_tof
   */
  template std::string
  wavelength_to_tof<double>(const double wavelength,
                            const double wavelength_err2,
                            const double pathlength,
                            const double pathlength_err2,
                            double & tof,
                            double & tof_err2,
                            void *temp);
} // AxisManip
