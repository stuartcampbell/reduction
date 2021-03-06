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
 * \file utils/test/cpp/bisect_helper_test.cpp
 */

#include "utils.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;

/**
 * \defgroup bisect_helper_test bisect_helper_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>bisect_helper</i> with the true output data (\f$true\_output\f$)
 * manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notations used:</b>
 * - ss : scalar-scalar
 * - SS : "s,s"
 * - ERROR = "error "
 */

/**
 *
 * This function initializes the values of the \f$input\f$ array 
 *
 * \param input (OUTPUT) is the array to search for values to find a bin index
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & input)
{
  for( int i = 0 ; i < NUM_VAL ; i++ )
    {
      input.push_back(static_cast<NumT>(i)); // 0,1,2,3,4
    }
}

/**
 * Function that sets the true outputs based on searched values contained in
 * \f$input\f$.
 *
 * \param true_output1 (OUTPUT) is the true value of the found index for test 1
 * \param true_output2 (OUTPUT) is the true value of the found index for test 2
 * \param true_output3 (OUTPUT) is the true value of the found index for test 3
 * \param true_output4 (OUTPUT) is the true value of the found index for test 4
 */
void initialize_true_outputs(size_t & true_output1,
                             size_t & true_output2,
                             size_t & true_output3,
                             size_t & true_output4)
{
  // initialize the correct outputs
  true_output1 = static_cast<size_t>(0);
  true_output2 = static_cast<size_t>(1);
  true_output3 = static_cast<size_t>(2);
  true_output4 = static_cast<size_t>(3);
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>bisect_helper</i> function. The function returns
 * TRUE if the two values compared \f$output\f$ and \f$true\_output\f$ match,
 * and returns FALSE if they do not match.
 *
 * \param output1 (INPUT) is the value created by <i>bisect_helper</i> for 
 * test 1
 * \param output2 (INPUT) is the value created by <i>bisect_helper</i> for 
 * test 2
 * \param output3 (INPUT) is the value created by <i>bisect_helper</i> for 
 * test 3
 * \param output4 (INPUT) is the value created by <i>bisect_helper</i> for 
 * test 4
 * \param true_output1 (INPUT) is the true value of the found index for test 1
 * \param true_output2 (INPUT) is the true value of the found index for test 2
 * \param true_output3 (INPUT) is the true value of the found index for test 3
 * \param true_output4 (INPUT) is the true value of the found index for test 4
 */
bool test_okay(size_t & output1,
               size_t & output2,
               size_t & output3,
               size_t & output4,
               size_t & true_output1,
               size_t & true_output2,
               size_t & true_output3,
               size_t & true_output4)
{
  bool value = true;

  // scalar scalar comparison
  if(!test_okay(output1, true_output1, SS))
    {
      value = false;
    }
  if(!test_okay(output2, true_output2, SS))
    {
      value = false;
    }
  if(!test_okay(output3, true_output3, SS))
    {
      value = false;
    }
  if(!test_okay(output4, true_output4, SS))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>bisect_helper</i> function
 * (as described in the documentation of the <i>bisect_helper</i> function)
 * and launches the comparison of the data. Returns the result
 * of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test 
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 */
template <typename NumT>
bool test_func(NumT key, string debug) { 
  // allocate arrays and values
  Nessi::Vector<NumT> input;

  NumT value1 = static_cast<NumT>(-1.3);
  NumT value2 = static_cast<NumT>(1.4);
  NumT value3 = static_cast<NumT>(2.0);
  NumT value4 = static_cast<NumT>(5.7);

  size_t output1;
  size_t output2;
  size_t output3;
  size_t output4;
  size_t true_output1;
  size_t true_output2;
  size_t true_output3;
  size_t true_output4;

  // fill in values as appropriate
  initialize_inputs(input);
  initialize_true_outputs(true_output1, true_output2, true_output3, 
                          true_output4);

  // run the code being tested
  Utils::bisect_helper(input, value1, output1);
  Utils::bisect_helper(input, value2, output2);
  Utils::bisect_helper(input, value3, output3);
  Utils::bisect_helper(input, value4, output4);

  if(!debug.empty())
    {
      cout << endl;
      print(output1, true_output1, SS, debug);
      print(output2, true_output2, SS, debug);
      print(output3, true_output3, SS, debug);
      print(output4, true_output4, SS, debug);
    }

  return test_okay(output1, output2, output3, output4, true_output1, 
                   true_output2, true_output3, true_output4);
}

/**
 * Main function that tests <i>bisect_helper</i> for float and double
 * 
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "bisect_helper_test.cpp..........";

  string debug;
  if(argc > 1)
    {
      debug = argv[1];
    }

  int value = 0;

  if(!test_func(static_cast<float>(1), debug))
    {
      value = -1;
    }

  if(!test_func(static_cast<double>(1), debug))
    {
      value = -1;
    }

  if(value == 0)
    {
      cout << "Functionality OK" << endl;
    }

  return value;
}

/**
 * \}
 */   //end of bisect_helper_test group
