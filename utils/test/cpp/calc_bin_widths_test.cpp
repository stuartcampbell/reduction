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
 * \file utils/test/cpp/calc_bin_widths_test.cpp
 */

#include "utils.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;

/**
 * \defgroup calc_bin_widths_test calc_bin_widths_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>calc_bin_widths</i> and described in section 3.54 of the
 * <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications"</i> with the true output data (\f$true\_output\f$)
 * manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notations used:</b>
 * - vv : vector-vector
 * - VV : "v,v"
 * - ERROR = "error "
 */

/**
 *
 * This function initializes the values of arrays, \f$axis\f$ and 
 * \f$axis\_err2\f$.
 *
 * \param axis (OUTPUT) is the independent axis
 * \param axis_err2 (OUTPUT) is the square uncertainties of the independent 
 * axis
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & axis,
                       Nessi::Vector<NumT> & axis_err2)
{
  for( int i=0 ; i<NUM_VAL ; i++ )
    {
      axis.push_back(static_cast<NumT>(i+1.)); // 1,2,3,4,5
      axis_err2.push_back(static_cast<NumT>(1.1*(i+1))); // 1.1,2.2,3.3,4.4,5.5
    }
  axis.push_back(static_cast<NumT>(NUM_VAL+1.)); // 6
  axis_err2.push_back(static_cast<NumT>(1.1*(NUM_VAL+1))); // 6.6
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$input1\f$ and \f$input1\_err2\f$.
 *
 * \param true_output (OUTPUT) is the true value of the calculate bin widths
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * calculate bin widths
 */
void initialize_true_outputs(Nessi::Vector<float> & true_output,
                             Nessi::Vector<float> & true_output_err2)
{
  // initialize the correct outputs

  // vector-vector
  true_output.push_back(static_cast<float>(1.0));
  true_output_err2.push_back(static_cast<float>(3.3000002));
  true_output.push_back(static_cast<float>(1.0));
  true_output_err2.push_back(static_cast<float>(5.5));
  true_output.push_back(static_cast<float>(1.0));
  true_output_err2.push_back(static_cast<float>(7.7));
  true_output.push_back(static_cast<float>(1.0));
  true_output_err2.push_back(static_cast<float>(9.9));
  true_output.push_back(static_cast<float>(1.0));
  true_output_err2.push_back(static_cast<float>(12.1));
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$input1\f$ and \f$input1\_err2\f$.
 *
 * \param true_output (OUTPUT) is the true value of the calculate bin widths
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * calculate bin widths
 */
void initialize_true_outputs(Nessi::Vector<double> & true_output,
                             Nessi::Vector<double> & true_output_err2)
{
  // initialize the correct outputs

  // vector-vector
  true_output.push_back(static_cast<double>(1.0));
  true_output_err2.push_back(static_cast<double>(3.30000000000000027));
  true_output.push_back(static_cast<double>(1.0));
  true_output_err2.push_back(static_cast<double>(5.5));
  true_output.push_back(static_cast<double>(1.0));
  true_output_err2.push_back(static_cast<double>(7.70000000000000107));
  true_output.push_back(static_cast<double>(1.0));
  true_output_err2.push_back(static_cast<double>(9.9));
  true_output.push_back(static_cast<double>(1.0));
  true_output_err2.push_back(static_cast<double>(12.1000000000000014));
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>calc_bin_widths</i> function. The function returns
 * TRUE if the two values compared \f$output\f$ and \f$true\_output\f$ match,
 * and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the value created by <i>calc_bin_widths</i>
 * \param output_err2 (INPUT) is the square of the uncertainty in the
 * value created by <i>calc_bin_widths</i>
 * \param true_output (INPUT) is the true value of the calculate bin widths
 * \param true_output_err2 (INPUT) is the square of the uncertainty in the
 * true value of the calculate bin widths
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & output_err2,
               Nessi::Vector<NumT> & true_output,
               Nessi::Vector<NumT> & true_output_err2)
{
  bool value = true;

  // vector vector comparison
  if(!test_okay(output,true_output,VV))
    {
      value = false;
    }
  if(!test_okay(output_err2,true_output_err2,VV,ERROR))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>calc_bin_widths</i> 
 * function (as described in the documentation of the 
 * <i>calc_bin_widths</i> function) and launches the comparison of the 
 * data. Returns the result of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 */
template <typename NumT>
bool test_func(NumT key, string debug){ // key forces correct test to happen
  // allocate arrays and values
  Nessi::Vector<NumT> axis;
  Nessi::Vector<NumT> axis_err2;
  Nessi::Vector<NumT> output(NUM_VAL);
  Nessi::Vector<NumT> output_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output;
  Nessi::Vector<NumT> true_output_err2;

  // fill in values as appropriate
  initialize_inputs(axis, axis_err2);
  initialize_true_outputs(true_output, true_output_err2);

  // run the code being tested
  Utils::calc_bin_widths(axis, axis_err2,
                         output, output_err2);
  
  if(!debug.empty())
    {
      cout << endl;
      print(output, true_output, VV, debug);
      print(output_err2, true_output_err2, ERROR+VV, debug); 
    }

  return test_okay(output, output_err2, 
                   true_output, true_output_err2);
}

/**
 * Main function that tests <i>calc_bin_widths</i> for float and double
 *
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "calc_bin_widths_test.cpp..........";

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
 */   //end of calc_bin_widths_test group
