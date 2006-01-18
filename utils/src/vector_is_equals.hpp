/**
 * $Id$
 *
 * \file utils/src/vector_is_equals.hpp
 */
#ifndef _VECTOR_IS_EQUALS_HPP
#define _VECTOR_IS_EQUALS_HPP 1

#include "num_comparison.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

namespace Utils
{
  // vector_is_equals function
  template <typename NumT>
  bool
  vector_is_equals (const Nessi::Vector<NumT> & value,
  	    const Nessi::Vector<NumT> & true_value)
  {
    size_t n_max = true_value.size();
    for (size_t i = 0 ; i < n_max ; i++)
      {
        if (compare(value[i], true_value[i]) != 0)
          {
            __vector_is_equals_static(i, value[i], true_value[i]);
            return false;
          }
      }
    return true;
  }

  /**
   * \ingroup vector_is_equals
   *
   * This is a PRIVATE helper function for printing debugging information if
   * the equality check fails.
   *
   * \param index (INPUT) is the current index of the vector
   * \param value (INPUT) is the value of the calculated vector at the
   * current index
   * \param true_value (INPUT) is the value of the truth vector at the
   * current index
   */
  template <typename NumT>
  void
  __vector_is_equals_static(const size_t index,
                            const NumT value,
                            const NumT true_value)
  {
    std::cout << "At index #" << index << ": ";
    std::cout << "Value expected was ";
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(std::numeric_limits<NumT>::digits10+1);
    std::cout << true_value;
    std::cout << ", Value returned was " << value << std::endl;
    std::cout << "Difference (Returned - Expected): ";
    std::cout.setf(std::ios::scientific);
    std::cout << value - true_value << std::endl;

    return;
  }



} // Utils

#endif // _VECTOR_IS_EQUALS_HPP