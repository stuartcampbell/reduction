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
 * \file utils/src/compare.cpp
 */
#include "compare.hpp"
#include <cmath>
#include <limits>

namespace Utils
{
  // specialized function for float

  /**
   * This is the float declaration of the compare function.
   *
   * \ingroup compare
   */
  int compare(const float & value1,
              const float & value2)
  {
    if(!(fabs(value1 - value2) > std::numeric_limits<float>::epsilon()))
      {
        return 0;
      }

    if(value1 > value2)
      {
        return 1;
      }
    else
      {
        return -1;
      }
  }

  // specialized function for double

  /**
   * This is the double declaration of the compare function.
   *
   * \ingroup compare
   */
  int compare(const double & value1,
              const double & value2)
  {
    if(!(fabs(value1 - value2) > std::numeric_limits<double>::epsilon()))
      {
        return 0;
      }

    if(value1 > value2)
      {
        return 1;
      }
    else
      {
        return -1;
      }
  }

  // explicit instantiations

  /**
   * This is the integer declaration of the compare function.
   *
   * \ingroup compare
   */
  template int
  compare<int>(const int & value1,
               const int & value2);

  /**
   * This is the unsigned integer declaration of the compare function.
   *
   * \ingroup compare
   */
  template int
  compare<unsigned int>(const unsigned int & value1,
                        const unsigned int & value2);

  /**
   * This is the std::size_t declaration of the compare function.
   *
   * \ingroup compare
   */
  template int
  compare<std::size_t>(const std::size_t & value1,
                       const std::size_t & value2);

} // Utils
