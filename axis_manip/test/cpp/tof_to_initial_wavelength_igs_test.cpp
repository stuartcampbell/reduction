/*
 *         SNS Common Libraries
 *     A part of the SNS Analysis Software Suite.
 *
 *      Spallation Neutron Source
 *    Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *           NOTICE
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
 * \file axis_manip/test/cpp/tof_to_initial_wavelength_igs_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup tof_to_initial_wavelength_igs_test \
 * tof_to_initial_wavelength_igs_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>tof_to_initial_wavelength_igs</i> and described in 3.29
 * of the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software
 * Requirements and Specifications"</i> with the true output data
 * \f$true\_output\_ss\f$, and \f$true\_output\_vv\f$ manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notation used:</b>
 * - ss : scalar-scalar
 * - vv : vector-vector
 * - SS : "s,s"
 * - VV = "v,v"
 * - ERROR = "Error"
 * - EMPTY = ""
 */

/**
 * This function initializes the value of arrays, \f$tof\f$, \f$tof\_err2\f$.
 *
 * \param tof (OUTPUT) is the time-of-flight axis in units of micro-seconds
 * \param tof_err2 (OUTPUT) is the square of the uncertainty in the
 * time-of-flight axis
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & tof,
                       Nessi::Vector<NumT> & tof_err2)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      tof.push_back(static_cast<NumT>(1+i));
      tof_err2.push_back(static_cast<NumT>(i+0.5));
    }
}

/**
 * This function sets the true outputs based on values contained in
 * \f$tof\f$ and \f$tof\_err2\f$ for the float case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * (\f$tof[0]\f$ and \f$tof\_err2[0]\f$)
 *
 * \param true_output_ss (OUTPUT) is the true output for the ss case
 * \param true_output_ss_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the ss case
 * \param true_output_vv (OUTPUT) is the true array for the vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the vv case
 */
void initialize_true_outputs(float    & true_output_ss,
                             float    & true_output_ss_err2,
                             Nessi::Vector<float> & true_output_vv,
                             Nessi::Vector<float> & true_output_vv_err2)
{
  // scalar scalar
  true_output_ss=static_cast<float>(-0.58583915);
  true_output_ss_err2=static_cast<float>(0.14668619);

  // vector vector
  true_output_vv.push_back(static_cast<float>(-0.58583915));
  true_output_vv_err2.push_back(static_cast<float>(0.14668619));
  true_output_vv.push_back(static_cast<float>(-0.58224272));
  true_output_vv_err2.push_back(static_cast<float>(0.14635196));
  true_output_vv.push_back(static_cast<float>(-0.57864636));
  true_output_vv_err2.push_back(static_cast<float>(0.14601984));
  true_output_vv.push_back(static_cast<float>(-0.57504993));
  true_output_vv_err2.push_back(static_cast<float>(0.14568985));
  true_output_vv.push_back(static_cast<float>(-0.57145357));
  true_output_vv_err2.push_back(static_cast<float>(0.14536203));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$tof\f$ and \f$tof\_err2\f$ for the double case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * (\f$tof[0]\f$ and \f$tof\_err2[0]\f$)
 *
 * \param true_output_ss (OUTPUT) is the true output for the ss case
 * \param true_output_ss_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the ss case
 * \param true_output_vv (OUTPUT) is the true array for the vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the vv case
 */
void initialize_true_outputs(double    & true_output_ss,
                             double    & true_output_ss_err2,
                             Nessi::Vector<double> & true_output_vv,
                             Nessi::Vector<double> & true_output_vv_err2)
{
  // scalar scalar
  true_output_ss=static_cast<double>(-0.58583914499999989);
  true_output_ss_err2=static_cast<double>(0.14668620920470620);

  // vector vector
  true_output_vv.push_back(static_cast<double>(-0.58583914499999989));
  true_output_vv_err2.push_back(static_cast<double>(0.14668620920470620));
  true_output_vv.push_back(static_cast<double>(-0.58224275045454543));
  true_output_vv_err2.push_back(static_cast<double>(0.14635196281566775));
  true_output_vv.push_back(static_cast<double>(-0.57864635590909085));
  true_output_vv_err2.push_back(static_cast<double>(0.14601985428674937));
  true_output_vv.push_back(static_cast<double>(-0.57504996136363628));
  true_output_vv_err2.push_back(static_cast<double>(0.14568988361795109));
  true_output_vv.push_back(static_cast<double>(-0.57145356681818171));
  true_output_vv_err2.push_back(static_cast<double>(0.14536205080927291));
}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>tof_to_initial_wavelength_igs</i> function
 * for the ss and vv cases.
 *
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_ss (INPUT) is the value created by
 * <i>tof_to_initial_wavelength_igs</i> for the ss case
 * \param output_ss_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>tof_to_initial_wavelength_igs</i> for the ss case
 * \param true_output_ss (INPUT)) is the true value for the ss case
 * \param true_output_ss_err2 (INPUT) is the square of the uncertainty of the
 * true value for the ss case
 * \param output_vv (INPUT) is the value created by
 * <i>tof_to_initial_wavelength_igs</i> for the vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>tof_to_initial_wavelength_igs</i> for the vv case
 * \param true_output_vv (INPUT)) is the true value for the vv case
 * \param true_output_vv_err2 (INPUT) is the square of the uncertainty of the
 * true value for the vv case
 */
template <typename NumT>
bool test_okay(NumT    & output_ss,
               NumT    & output_ss_err2,
               NumT    & true_output_ss,
               NumT    & true_output_ss_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2)
{
  bool value = true;

  // scalar scalar
  if(!test_okay(output_ss,true_output_ss))
    {
      value = false;
    }
  if(!test_okay(output_ss_err2,true_output_ss_err2))
    {
      value = false;
    }

  // vector vector
  if(!test_okay(output_vv,true_output_vv,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_err2,true_output_vv_err2,VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the
 * <i>tof_to_initial_wavelength_igs</i> function (as described in the
 * documentation of the <i>tof_to_initial_wavelength_igs</i> function)
 * and launches the comparison of the data.
 *
 * \param key (INPUT) is a key that permits to launch the correct test
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 *
 * \return Result of the function (TRUE/FALSE)
 */
template <typename NumT>
bool test_func(NumT key, string debug) // key forces correct test to happen
{
  // allocate arrays
  Nessi::Vector<NumT>   tof;
  Nessi::Vector<NumT>   tof_err2;
  NumT                  final_wavelength=static_cast<NumT>(1.25);
  NumT                  final_wavelength_err2=static_cast<NumT>(0.25);
  NumT                  time_offset=static_cast<NumT>(2.75);
  NumT                  time_offset_err2=static_cast<NumT>(0.75);
  NumT                  dist_source_sample=static_cast<NumT>(1.1);
  NumT                  dist_source_sample_err2=static_cast<NumT>(0.1);
  NumT                  dist_sample_detector=static_cast<NumT>(0.51);
  NumT                  dist_sample_detector_err2=static_cast<NumT>(0.05);
  NumT                  output_ss;
  NumT                  output_ss_err2;
  NumT                  true_output_ss;
  NumT                  true_output_ss_err2;
  Nessi::Vector<NumT>   output_vv(NUM_VAL);
  Nessi::Vector<NumT>   output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT>   true_output_vv;
  Nessi::Vector<NumT>   true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(tof,tof_err2);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_vv, true_output_vv_err2);

  // run the code being tested
  AxisManip::tof_to_initial_wavelength_igs(tof[0], tof_err2[0],
                                           final_wavelength,
                                           final_wavelength_err2,
                                           time_offset, time_offset_err2,
                                           dist_source_sample,
                                           dist_source_sample_err2,
                                           dist_sample_detector,
                                           dist_sample_detector_err2,
                                           output_ss,
                                           output_ss_err2);

  AxisManip::tof_to_initial_wavelength_igs(tof, tof_err2,
                                           final_wavelength,
                                           final_wavelength_err2,
                                           time_offset, time_offset_err2,
                                           dist_source_sample,
                                           dist_source_sample_err2,
                                           dist_sample_detector,
                                           dist_sample_detector_err2,
                                           output_vv,
                                           output_vv_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_vv, true_output_vv, VV, debug);
      print(output_vv_err2, true_output_vv_err2, ERROR+VV, debug);
      print(output_ss, true_output_ss, SS, debug);
      print(output_ss_err2, true_output_ss_err2, ERROR+SS, debug);
    }

  return test_okay(output_ss, output_ss_err2,
                   true_output_ss, true_output_ss_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

/**
 * Main function that test tof_to_initial_wavelength_igs for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "tof_to_initial_wavelength_igs_test.cpp..........";

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
 */  // end of tof_to_initial_wavelength_igs_test group
