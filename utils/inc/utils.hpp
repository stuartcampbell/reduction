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
 * \file utils/inc/utils.hpp
 */
#ifndef _UTILS_HPP
#define _UTILS_HPP 1

#include "nessi.hpp"
#include <string>

/**
 * \namespace Utils
 *
 * \brief This sub-library contains various functions that do not
 * specifically reside in any of the other sub-libraries.
 *
 * All of these functions are written in reference to SNS
 * 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications."
 */
namespace Utils
{
  /**
   * \defgroup bisect_helper Utils::bisect_helper
   * \{
   */

  /**
   * \brief This function is currently not described in the document
   * 
   * This function takes an axis array and a given value and searches that 
   * axis for the corresponding bin location. However, this helper is used in 
   * the context of locating a bin index within an associated data array 
   * (which is always one less than the axis array) based on the axis array 
   * value. The found index may need to be adjusted based on its value with 
   * respect to the size of the data array. <b>NOTE:</b> If the search value 
   * is outside the axis range, the result of the function will be to return 
   * the closest edge bin. This means for a search value smaller than the 
   * smallest axis value, the index returned will be 0. If the search value is 
   * greater than the largest axis value, the index returned will be the last 
   * bin in the data array (axis size minus 1).
   *
   * \param axis (INPUT) is an array of independent axis values to search
   * \param value (INPUT) is the value to search axis for
   * \param index (OUTPUT) is the corresponding index for the value 
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  bisect_helper(const Nessi::Vector<NumT> & axis,
                const NumT value,
                std::size_t & index,
                void *temp=NULL);

  /**
   * \} // end of bisect_helper group
   */

  /**
   * \defgroup calc_bin_centers Utils::calc_bin_centers
   * \{
   */

  /**
   * \brief This function is described in section 3.52
   * 
   * This function takes in an axis array and its associated squared 
   * uncertainties and calculates the bin centers via the following formula:
   *
   * \f[
   * bin\_center[i] = \frac{1}{2}\left(axis[i] + axis[i+1]\right)
   * \f]
   *
   * where \f$bin\_center[i]\f$ is the \f$i^{th}\f$ bin center, \f$axis[i]\f$ 
   * is the \f$i^{th}\f$ axis element and \f$axis[i+1]\f$ is the 
   * \f$(i+1)^{th}\f$ axis element. The resulting array for the bin centers 
   * will be one element shorter than the incoming axis. 
   *
   * Assuming that the uncertainties are uncorrelated, the squared 
   * uncertainties are calculated by:
   *
   * \f[
   * \sigma^2_{bin\_center}[i] = \frac{1}{4}\left(\sigma^2_{axis}[i] + 
   * \sigma^2_{axis}[i+1]\right)
   * \f]
   *
   * where \f$\sigma^2_{bin\_center}[i]\f$ is the \f$i^{th}\f$ squared 
   * uncertainty of the bin center, \f$\sigma^2_{axis}[i]\f$ is the 
   * \f$i^{th}\f$ squared uncertainty of the axis and 
   * \f$\sigma^2_{axis}[i+1]\f$ is the \f$(i+1)^{th}\f$ squared uncertainty of 
   * the axis.
   *
   * \param axis (INPUT) is an array of independent axis values
   * \param axis_err2 (INPUT) is an array of the squares of the uncertainties 
   * associated with the independent axis
   * \param bin_centers (OUTPUT) is an array of bin centers of the independent 
   * axis
   * \param bin_centers_err2 (OUTPUT) is an array of the squares of the 
   * uncertainties associated with the bin centers
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  calc_bin_centers(const Nessi::Vector<NumT> & axis,
                   const Nessi::Vector<NumT> & axis_err2,
                   Nessi::Vector<NumT> & bin_centers,
                   Nessi::Vector<NumT> & bin_centers_err2,
                   void *temp=NULL);
 
  /**
   * \} // end of calc_bin_centers group
   */

  /**
   * \defgroup calc_bin_widths Utils::calc_bin_widths
   * \{
   */

  /**
   * \brief This function is described in section 3.54
   * 
   * This function takes in an axis array and its associated squared 
   * uncertainties and calculates the bin widths via the following formula:
   *
   * \f[
   * bin\_width[i] = axis[i+1] - axis[i]
   * \f]
   *
   * where \f$bin\_width[i]\f$ is the \f$i^{th}\f$ bin width, \f$axis[i]\f$ 
   * is the \f$i^{th}\f$ axis element and \f$axis[i+1]\f$ is the 
   * \f$(i+1)^{th}\f$ axis element. The resulting array for the bin widths 
   * will be one element shorter than the incoming axis. 
   *
   * Assuming that the uncertainties are uncorrelated, the squared 
   * uncertainties are calculated by:
   *
   * \f[
   * \sigma^2_{bin\_width}[i] = \sigma^2_{axis}[i+1] + \sigma^2_{axis}[i]
   * \f]
   *
   * where \f$\sigma^2_{bin\_width}[i]\f$ is the \f$i^{th}\f$ squared 
   * uncertainty of the bin width, \f$\sigma^2_{axis}[i]\f$ is the 
   * \f$i^{th}\f$ squared uncertainty of the axis and 
   * \f$\sigma^2_{axis}[i+1]\f$ is the \f$(i+1)^{th}\f$ squared uncertainty of 
   * the axis.
   *
   * \param axis (INPUT) is an array of independent axis values
   * \param axis_err2 (INPUT) is an array of the squares of the uncertainties 
   * associated with the independent axis
   * \param bin_widths (OUTPUT) is an array of bin widths of the independent 
   * axis
   * \param bin_widths_err2 (OUTPUT) is an array of the squares of the 
   * uncertainties associated with the bin widths
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  calc_bin_widths(const Nessi::Vector<NumT> & axis,
                  const Nessi::Vector<NumT> & axis_err2,
                  Nessi::Vector<NumT> & bin_widths,
                  Nessi::Vector<NumT> & bin_widths_err2,
                  void *temp=NULL);
 
  /**
   * \} // end of calc_bin_widths group
   */

  /**
   * \defgroup eval_linear_fit Utils::eval_linear_fit
   * \{
   */

  /**
   * \brief This function is described in section 3.56.
   *
   * This function takes an independent axis and the associated uncertainties 
   * and the fit parameters of a line (slope and intercept) and calculates the 
   * values associated with the independent axis based on the fit parameters.
   *
   * The calculation of the new values from the input independent axis should 
   * be done by the following
   *
   * \f[
   * data_o[i] = slope \times axis_i[i] + intercept
   * \f]
   * 
   * where \f$axis_i[i]\f$ is the \f$i^{th}\f$ element of the independent 
   * axis, \f$slope\f$ is the slope of the linear fit, \f$intercept\f$ is the 
   * intercept of the linear fit and \f$data_o[i]\f$ is the \f$i^{th}\f$ 
   * element of the calculated linear equation.
   *
   * Assuming that the uncertainties are uncorrelated, the uncertainty on a 
   * given element of the calculated linear equation is
   *
   * \f[
   * \sigma^2_o[i] = axis^2_i[i] \sigma^2_{slope} + 
   * slope^2 \sigma^2_{axis_i}[i] + \sigma^2_{intercept}
   * \f]
   *
   * where \f$\sigma^2_{axis_i}[i]\f$ is the \f$i^{th}\f$ element of the 
   * square uncertainty of the independent axis, \f$\sigma^2_{slope}\f$ is the 
   * square uncertainty of the slope of the linear fit, 
   * \f$\sigma^2_{intercept}\f$ is the square uncertainty of the intercept of 
   * the linear fit and \f$\sigma^2_o[i]\f$ is the \f$i^{th}\f$ element of the 
   * square uncertainty of the calculated linear equation value.
   *
   * \param axis_in (INPUT) is an array of independent axis values
   * \param axis_in_err2 (INPUT) is an array of the squares of the 
   * uncertainties associated with the independent axis values
   * \param slope (INPUT) is the slope of the line from the fit
   * \param slope_err2 (INPUT) is the square of the uncertainties associated 
   * with the slope
   * \param intercept (INPUT) is the intercept of the line from the fit
   * \param intercept_err2 (INPUT) is the square of the uncertainties 
   * associated with the intercept
   * \param output (OUTPUT) is an array of values calculated from the 
   * independent axis with the fit parameters
   * \param output_err2 (OUTPUT) is an array of the squares of the 
   * uncertainties associated with the values calculated from the independent 
   * axis with the fit parameters
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  eval_linear_fit(const Nessi::Vector<NumT> & axis_in,
                  const Nessi::Vector<NumT> & axis_in_err2,
                  const NumT slope,
                  const NumT slope_err2,
                  const NumT intercept,
                  const NumT intercept_err2,
                  Nessi::Vector<NumT> & output,
                  Nessi::Vector<NumT> & output_err2,
                  void *temp=NULL);

  /**
   * \}
   */ // end of eval_linear_fit group

  /**
   * \defgroup fit_linear_background Utils::fit_linear_background
   * \{
   */

  /**
   * \brief This function is described in section 3.43.
   *
   * This function takes an independent axis and the associated values and 
   * errors and fits a linear function to those points. An optional range 
   * can be specified that will restrict the fit region. That range is 
   * specified via array elements (bins). If the maximum range bin is set to 
   * zero then the ending bin is assumed to be the full length of the array 
   * (length-1). The function uses the method of determinants which is 
   * described in detail in Chapter 6 of <em>Data Reduction and Error Analysis 
   * for the Physical Sciences</em> by Bevington and Robinson. 
   * 
   * The necessary formulas for the parameters from the method of determinants 
   * are given by the following.
   *
   * \f[
   * \Delta = \left(\sum\frac{1}{\sigma^2_i[i]}\right) 
   * \left(\sum\frac{axis^2_i[i]}{\sigma^2_i[i]}\right)
   * - \left(\sum\frac{axis_i[i]}{\sigma^2_i[i]} \right)^2
   * \f]
   * \f[
   * slope = \frac{1}{\Delta} \left(\left(\sum\frac{1}{\sigma^2_i[i]}\right)
   * \left(\sum\frac{axis_i[i]\:data_i[i]}{\sigma^2_i[i]}\right) - 
   * \left(\sum\frac{axis_i[i]}{\sigma^2_i[i]}\right) 
   * \left(\sum\frac{data_i[i]}{\sigma^2_i[i]}\right)\right)
   * \f]
   * \f[
   * intercept = \frac{1}{\Delta} 
   * \left(\left(\sum\frac{axis^2_i[i]}{\sigma^2_i[i]}\right)
   * \left(\sum\frac{data_i[i]}{\sigma^2_i[i]}\right) - 
   * \left(\sum\frac{axis_i[i]}{\sigma^2_i[i]}\right)
   * \left(\sum\frac{axis_i[i]\:data_i[i]}{\sigma^2_i[i]}\right)\right)
   * \f]
   * \f[
   * \sigma^2_{slope} = \frac{1}{\Delta} \sum\frac{1}{\sigma^2_i[i]}
   * \f]
   * \f[
   * \sigma^2_{intercept} = \frac{1}{\Delta} 
   * \sum\frac{axis^2_i[i]}{\sigma^2_i[i]}
   * \f]
   *
   * where \f$axis_i[i]\f$ is the \f$i^{th}\f$ element of the independent 
   * axis, \f$data_i[i]\f$ is the \f$i^{th}\f$ element of the input data array
   * and \f$\sigma^2_i[i]\f$ is the \f$i^{th}\f$ element of the square 
   * uncertainty in the input data array.
   *
   * \param axis_in (INPUT) is an array of independent axis values
   * \param input (INPUT) is an array of values associated with the 
   * independent axis
   * \param input_err2 (INPUT) is an array of the squares of the uncertainties 
   * associated with the values
   * \param min_bin (INPUT) is the minimum axis bin for the fit range
   * \param max_bin (INPUT) is the maximum axis bin for the fit range
   * \param slope (OUTPUT) is the slope of the line from the fit
   * \param slope_err2 (OUTPUT) is the square of the uncertainties associated 
   * with the slope
   * \param intercept (OUTPUT) is the intercept of the line from the fit
   * \param intercept_err2 (OUTPUT) is the square of the uncertainties 
   * associated with the intercept
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  fit_linear_background(const Nessi::Vector<NumT> & axis_in,
                        const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        const std::size_t min_bin,
                        const std::size_t max_bin,
                        NumT & slope,
                        NumT & slope_err2,
                        NumT & intercept,
                        NumT & intercept_err2,
                        void *temp=NULL);

  /**
   * \}
   */ // end of fit_linear_background group

  /**
   * \defgroup fit_reflectometer_background Utils::fit_reflectometer_background
   * \{
   */

  /**
   * \brief This function is described in section 3.42.
   *
   * THIS FUNCTION NEEDS TO BE DOCUMENTED
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  fit_reflectometer_background(const Nessi::Vector<NumT> & axis_in,
                               const Nessi::Vector<NumT> & input,
                               const Nessi::Vector<NumT> & input_err2,
                               const Nessi::Vector<NumT> & params_in,
                               Nessi::Vector<NumT> & output,
                               Nessi::Vector<NumT> & output_err2,
                               Nessi::Vector<NumT> & params_out,
                               Nessi::Vector<NumT> & params_out_err2,
                               void *temp=NULL);

  /**
   * \}
   */ // end of fit_reflectometer_background group

  /**
   * \defgroup fix_index Utils::__fix_index
   * \{
   */

  /**
   * \brief This function fixes indicies for AxisManip::rebin_diagonal
   *
   * This function fixes indices for AxisManip::rebin_diagonal. If the index 
   * is equal to the largest std::size_t, then the returned index is 0. If the 
   * index is equal to end_index plus 1, then the returned index is one less 
   * than original index. If not either of the above two cases, return the 
   * original index. <b>NOTE: This is a private function and will not be 
   * exported.</b>
   * 
   * \param index (INPUT) is the index to check and fix
   * \param end_index (INPUT) is the last index of the array associated with 
   * index
   * 
   * \return The corrected index
   */
  std::size_t __fix_index(const std::size_t index, 
                          const std::size_t end_index);

  /**
   * \} // end of fix_index group
   */

  /**
   * \ingroup bisect_helper
   */

  /**
   * \brief This function fixes indicies for Utils::bisect_helper
   *
   * This function fixes indices for Utils::bisect_helper. If the index is 
   * equal to the largest std::size_t, then the returned index is 0. If the 
   * index is equal to end_index, then the returned index is one less than 
   * original index. If not either of the above two cases, return the original 
   * index. <b>NOTE: This is a private function and will not be exported.</b>
   * 
   * \param index (INPUT) is the index to check and fix
   * \param end_index (INPUT) is the last index of the array associated with 
   * index
   * 
   * \return The corrected index
   */
  std::size_t __fix_index2(const std::size_t index, 
                           const std::size_t end_index);

  /**
   * \defgroup integrate_1D_hist Utils::integrate_1D_hist
   * \{
   */

  /**
   * \brief This function is documented in section 3.65
   *
   * This function integrates 1D <b>histogram</b> data according to the 
   * following formalism.
   *
   * \f[
   * data_{out} = \sum^{N}_{i=0} data_{in}[i]
   * \f]
   * \f[
   * \sigma^2_{out} = \sum^{N}_{i=0} \sigma^2_{in}[i]
   * \f]
   * 
   * There is also the option to remove the bin width from the integrations. 
   * If this is desired, the integration takes the following form.
   * 
   * \f[
   * data_{out} = \sum^{N}_{i=min} axis_{bw\_in}[i] \times data_{in}[i]
   * \f]
   * \f[
   * \sigma^2_{out} = \sum^{N}_{i=min} axis^2_{bw\_in}[i] \times 
   * \sigma^2_{in}[i]
   * \f]
   * 
   * \param input (INPUT) is the histogram data to integrate
   * \param input_err2 (INPUT) is the square uncertainty associated with the 
   * data to integrate
   * \param width (INPUT) is a flag to remove the bin width from the integrated
   * values
   * \param axis_bw_in (INPUT) is the bin widths that will be used to when the 
   * width option is used
   * \param output (OUTPUT) is the value of the integration of the data
   * \param output_err2 (OUTPUT) is the squared uncertainty of the data 
   * integration
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  integrate_1D_hist(const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const bool width,
                    const Nessi::Vector<NumT> & axis_bw_in,
                    NumT & output,
                    NumT & output_err2,
                    void *temp=NULL);

  /**
   * \brief This function is documented in section 3.65
   *
   * This function integrates 1D <b>histogram</b> data according to the 
   * following formalism.
   *
   * \f[
   * data_{out} = \sum^{max}_{i=min} data_{in}[i]
   * \f]
   * \f[
   * \sigma^2_{out} = \sum^{max}_{i=min} \sigma^2_{in}[i]
   * \f]
   * 
   * where \f$min\f$ and \f$max\f$ are the bin indicies in the data that are 
   * determined from the associated independent-axis. There is also the option 
   * to remove the bin width from the integrations. If this is desired, the 
   * integration takes the following form.
   * 
   * \f[
   * data_{out} = \sum^{max}_{i=min} axis_{bw\_in}[i] \times data_{in}[i]
   * \f]
   * \f[
   * \sigma^2_{out} = \sum^{max}_{i=min} axis^2_{bw\_in}[i] \times 
   * \sigma^2_{in}[i]
   * \f]
   * 
   * \param input (INPUT) is the histogram data to integrate
   * \param input_err2 (INPUT) is the square uncertainty associated with the 
   * data to integrate
   * \param axis_in (INPUT) is the independent-axis associated with the data
   * \param min_int (INPUT) is the minimum independent-axis value to integrate 
   * from
   * \param max_int (INPUT) is the maximum independent-axis value to integrate 
   * to
   * \param width (INPUT) is a flag to remove the bin width from the integrated
   * values
   * \param axis_bw_in (INPUT) is the bin widths that will be used to when the 
   * width option is used
   * \param output (OUTPUT) is the value of the integration of the data
   * \param output_err2 (OUTPUT) is the squared uncertainty of the data 
   * integration
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  integrate_1D_hist(const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const Nessi::Vector<NumT> & axis_in,
                    const NumT min_int,
                    const NumT max_int, 
                    const bool width,
                    const Nessi::Vector<NumT> & axis_bw_in,
                    NumT & output,
                    NumT & output_err2,
                    void *temp=NULL);

  /**
   * \}
   */ // end of integrate_1D_hist group

  /**
   * \defgroup linear_order_jacobian Utils::linear_order_jacobian
   * \{
   */

  /**
   * \brief This function is documented in section 3.49
   *
   * This function corrects the input based on the ratio of differences 
   * between bin boundaries from the associated orignal and transformed axes.
   * This correction only applies to <b>histogram</b> data. <b>The incoming 
   * axes and counts arrays should be in their original form (no reversing), 
   * otherwise the calculation of the Jacobians will be done incorrectly</b>. 
   * The calculation of the linear order Jacobian is accomplished by:
   *
   * \f[
   * I'[k] = I[k] \times \left|\frac{x[k+1] - x[k]}{x'[k+1] - x'[k]}\right|
   * \f]
   *
   * where \f$I'[k]\f$ is the \f$k^{th}\f$ element of the corrected counts, 
   * \f$I[k]\f$ is the \f$k^{th}\f$ element of the counts associated with a 
   * particular histogram bin \f$k\f$, \f$x[k+1]\f$ is the high bin boundary 
   * and \f$x[k]\f$ is the low bin boundary from the original axis and 
   * \f$x'[k+1]\f$ is the high bin boundary and \f$x'[k]\f$ is the low bin 
   * boundary from the transformed axis. 
   *
   * The square of the uncertainty is calculated via:
   * 
   * \f[
   * \sigma^2_{I'}[k] = \sigma^2_I[k] \times \left(\frac{x[k+1] - x[k]}
   * {x'[k+1] - x'[k]}\right)^2
   * \f]
   *
   * where \f$\sigma^2_{I'}[k]\f$ is the \f$k^{th}\f$ element of the square of 
   * the uncertainty of the corrected counts, \f$\sigma^2_I[k]\f$ is the 
   * \f$k^{th}\f$ element of the square of the uncertainty in the counts 
   * associated with a particular histogram bin \f$k\f$, \f$x[k+1]\f$ is the 
   * high bin boundary and \f$x[k]\f$ is the low bin boundary from the 
   * original axis and \f$x'[k+1]\f$ is the high bin boundary and \f$x'[k]\f$ 
   * is the low bin boundary from the transformed axis.
   *
   * \param orig_axis (INPUT) is the original histogram axis associated with 
   * the data
   * \param transform_axis (INPUT) is the transformed histogram axis 
   * associated with the data
   * \param input (INPUT) is the counts data
   * \param input_err2 (INPUT) is the square of the uncertainty in the counts 
   * data
   * \param output (OUTPUT) is the corrected counts array
   * \param output_err2 (OUTPUT) is the corrected square of the uncertainty 
   * in the counts array
   * \param temp holds temporary memory to be passed to the funtion
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string 
  linear_order_jacobian(const Nessi::Vector<NumT> & orig_axis,
                        const Nessi::Vector<NumT> & transform_axis,
                        const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        Nessi::Vector<NumT> & output,
                        Nessi::Vector<NumT> & output_err2,
                        void *temp=NULL);

  /**
   * \brief This function is documented in section 3.49
   *
   * This function corrects the input based on the ratio of differences 
   * between bin boundaries from the associated orignal and transformed axes.
   * This correction only applies to <b>histogram</b> data. <b>The bin 
   * boundaries should be in their original order (no reversing) with respect 
   * to the counts, otherwise the calculation of the Jacobian will be 
   * incorrect</b>. The calculation of the linear order Jacobian is 
   * accomplished by:
   *
   * \f[
   * I' = I \times \left|\frac{x_{hi} - x_{lo}}{x'_{hi} - x'_{lo}}\right|
   * \f]
   *
   * where \f$I'\f$ is the corrected counts, \f$I\f$ is the counts associated 
   * with a particular histogram bin, \f$x_{hi}\f$ is the high bin boundary 
   * and \f$x_{lo}\f$ is the low bin boundary from the original axis and 
   * \f$x'_{hi}\f$ is the high bin boundary and \f$x'_{lo}\f$ is the low bin 
   * boundary from the transformed axis.
   *
   * The square of the uncertainty is calculated via:
   * 
   * \f[
   * \sigma^2_{I'} = \sigma^2_I \times \left(\frac{x_{hi} - x_{lo}}
   * {x'_{hi} - x'_{lo}}\right)^2
   * \f]
   *
   * where \f$\sigma^2_{I'}\f$ is the square of the uncertainty of the 
   * corrected counts, \f$\sigma^2_I\f$ is the square of the uncertainty in 
   * the counts associated with a particular histogram bin, \f$x_{hi}\f$ is 
   * the high bin boundary and \f$x_{lo}\f$ is the low bin boundary from the 
   * original axis and \f$x'_{hi}\f$ is the high bin boundary and 
   * \f$x'_{lo}\f$ is the low bin boundary from the transformed axis.
   *
   * \param orig_axis_lo (INPUT) is the low bin boundary of the original 
   * histogram axis associated with the data
   * \param orig_axis_hi (INPUT) is the high bin boundary of the original 
   * histogram axis associated with the data
   * \param transform_axis_lo (INPUT) is the low bin boundary of the 
   * transformed histogram axis associated with the data
   * \param transform_axis_hi (INPUT) is the high bin boundary of the 
   * transformed histogram axis associated with the data
   * \param input (INPUT) is the counts data
   * \param input_err2 (INPUT) is the square of the uncertainty in the counts 
   * data
   * \param output (OUTPUT) is the corrected counts
   * \param output_err2 (OUTPUT) is the corrected square of the uncertainty 
   * in the counts
   * \param temp holds temporary memory to be passed to the funtion
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string 
  linear_order_jacobian(const NumT orig_axis_lo,
                        const NumT orig_axis_hi,
                        const NumT transform_axis_lo,
                        const NumT transform_axis_hi,
                        const NumT input,
                        const NumT input_err2,
                        NumT & output,
                        NumT & output_err2,
                        void *temp=NULL);

  /**
   * \}
   */ // end of linear_order_jacobian group

  /**
   * \defgroup matrix_multiplication Utils::matrix_multiplication
   * \{
   */

  /**
   * \brief This function is described in section 3.37.
   *
   * THIS FUNCTION NEEDS TO BE DOCUMENTED
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  matrix_multiplication(const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        Nessi::Vector<NumT> & output,
                        Nessi::Vector<NumT> & output_err2,
                        void *temp=NULL);

  /**
   * \}
   */ // end of matrix_multiplication group

  /**
   * \defgroup peak_integration Utils::peak_integration
   * \{
   */

  /**
   * \brief This function is described in section 3.35.
   *
   * Starting with the \f$x_0\f$ bin, sum the values of the function and
   * associated uncertainty from adjecent bins using a box-type
   * method, an amoeba method (nearest neighbors), or other summation
   * method. Calculate the signal-to-noise ration via
   * \f[
   * \frac{\sum_i^{bins} F(x)}{\sum_i^{bins} \sigma_F(x)}
   * \f]
   * and continue summation from adjacent bins until a maximum in the
   * ratio is found. Determine quality of peak finding procedure and
   * return the outputs listed below.
   *
   * \param input (INPUT) is the function, \f$f(x)\f$, to be
   * integrated
   * \param input_err2 (INPUT) is the square of the uncertainty in the
   * function to be integrated
   * \param start_bin (INPUT) is the starting bin, \f$x_0\f$, to
   * integrate the function around
   * \param output (OUTPUT) is the value of the integrated function
   * \param output_err2 (OUTPUT) is the square of the uncertainty of
   * the integral
   * \param tag (OUTPUT) is a flag providing information on the
   * quality of the peak
   * \param num_bins (OUTPUT) is the number of histogram bins used in
   * the integration
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  peak_integration(const Nessi::Vector<NumT> & input,
                   const Nessi::Vector<NumT> & input_err2,
                   const Nessi::Vector<NumT> & start_bin,
                   NumT & output,
                   NumT & output_err2,
                   unsigned int & tag,
                   NumT & num_bins,
                   void *temp=NULL);

  /**
   * \}
   */ // end of peak_integration group

  /**
   * \defgroup shift_spectrum Utils::shift_spectrum
   * \{
   */

  /**
   * \brief This function is described in section 3.64
   *
   * This function takes the input data and shifts it about the given shift 
   * point. The values from \f$axis\_bc\_in\f$ (\f$x\f$) are iterated through 
   * and the output data is built by the following mechanism.
   *
   * \f[
   * \mathrm{if}\: x \leq x_{shift}:
   * \f]
   * \f[
   * data_{out}(x) = data_{in}\left(x + \left(x_{max} - x_{shift}\right)
   * \right)
   * \f]
   * \f[
   * \sigma^2_{out}(x) = \sigma^2_{in}\left(x + \left(x_{max} - x_{shift}
   * \right)\right)
   * \f]
   * \f[
   * \mathrm{if}\: x > x_{shift}:
   * \f]
   * \f[
   * data_{out}(x) = data_{in}\left(x - \left(x_{shift} - x_{min}\right)
   * \right)
   * \f]
   * \f[
   * \sigma^2_{out}(x) = \sigma^2_{in}\left(x - \left(x_{shift} - x_{min}
   * \right)\right)
   * \f]
   *
   * \param input (INPUT) is the data to shift
   * \param input_err2 (INPUT) is the square uncertainty in the data being 
   * shifted
   * \param axis_in (INPUT) is the independent axis associated with the input 
   * data
   * \param axis_bc_in (INPUT) is the bin centers of the independent axis
   * \param xshift (INPUT) the point on the independent axis about 
   * which to shift the data
   * \param xmin (INPUT) is the minimum axis point from which to retrieve
   * data
   * \param xmax (INPUT) is the maximum axis point from which to retrieve
   * data
   * \param output (OUTPUT) is the data after being shifted
   * \param output_err2 (OUTPUT) is the square uncertainty associated with the 
   * shifted data
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string
  shift_spectrum(const Nessi::Vector<NumT> & input,
                 const Nessi::Vector<NumT> & input_err2,
                 const Nessi::Vector<NumT> & axis_in,
                 const Nessi::Vector<NumT> & axis_bc_in,
                 const NumT xshift,
                 const NumT xmin,
                 const NumT xmax,
                 Nessi::Vector<NumT> & output,
                 Nessi::Vector<NumT> & output_err2,
                 void *temp=NULL);

  /**
   * \}
   */ // end of shift_spectrum group

  /**
   * \defgroup weighted_average Utils::weighted_average
   * \{
   */

  /**
   * \brief This function is described in section 3.46
   *
   * This function takes a slice of an array and calculates the weighted
   * average of that slice. The weighted average is calculated according to
   * the function
   *
   * \f[
   * \mu = \frac{\sum^{bin_{end}}_{i=bin_{start}} \frac{x_i}{\sigma_i^2}}
   * {\sum^{bin_{end}}_{i=bin_{start}} \frac{1}{\sigma_i^2}}
   * \f]
   *
   *  where \f$x_i\f$ is the \f$i^{th}\f$ element in the input array,
   * \f$\sigma_i^2\f$ is the square of the uncertainty associated with the
   * input array, \f$bin_{start}\f$ is the starting bin of the array from
   * which to calculate the weighted average, \f$bin_{end}\f$ is the ending
   * bin of the array where to stop the calculation, and \f$\mu\f$ is the
   * weighted average.
   *
   * The square of the uncertainty is calculated according to the following
   * function
   *
   * \f[
   * \sigma_{\mu}^2 = \frac{1}{\sum^{bin_{end}}_{i=bin_{start}} \frac{1}
   * {\sigma_i^2}}
   * \f]
   *
   *  where the other symbols are exactly as those mentioned above and
   * \f$\sigma_{\mu}^2\f$ is the square of the uncertainty in the weighted
   * average.
   *
   * \param input (INPUT) the array from which to calculate the weighted
   * average
   * \param input_err2 (INPUT) the square of the uncertainty in the associated
   * array from which calculate the weighted average
   * \param bin_start (INPUT) the bin of the array from which to start the
   * calculation
   * \param bin_end (INPUT) the bin of the array at which to end the
   * calculation
   * \param weighted_ave (OUTPUT) the weighted average of the array slice
   * \param weighted_ave_err2 (OUTPUT) the square of the uncertainty of the
   * weighted average of the array slice
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   *
   * \exception std::invalid_argument is thrown if the size of input is
   * not identical to the size of input_err2.
   */
  template <typename NumT>
  std::string
  weighted_average(const Nessi::Vector<NumT> & input,
                   const Nessi::Vector<NumT> & input_err2,
                   const std::size_t bin_start,
                   const std::size_t bin_end,
                   NumT & weighted_ave,
                   NumT & weighted_ave_err2,
                   void *temp=NULL);

  /**
   * \}
   */ // end of weighted_average group

} // Utils

#endif // _UTILS_HPP
