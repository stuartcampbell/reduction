##
#                     SNS Common Libraries
#            A part of the SNS Analysis Software Suite.
#
#                   Spallation Neutron Source
#           Oak Ridge National Laboratory, Oak Ridge TN.
#
#
#                              NOTICE
#
#  For this software and its associated documentation, permission is granted
#  to reproduce, prepare derivative works, and distribute copies to the public
#  for any purpose and without fee.
#
#  This material was prepared as an account of work sponsored by an agency of
#  the United States Government.  Neither the United States Government nor the
#  United States Department of Energy, nor any of their employees, makes any
#  warranty, express or implied, or assumes any legal liability or
#  responsibility for the accuracy, completeness, or usefulness of any
#  information, apparatus, product, or process disclosed, or represents that
#  its use would not infringe privately owned rights.
#
#

##
# $Id$
#
# \file bindings/test/PAL/calc_bin_widths_test.py
#

import nessi_list
import test_common
import utils

NUM_VAL = 5

##
# \defgroup calc_bin_widths_test pal::calc_bin_widths_test
# \{
#
# This test compares the output data ($output\_vv\f$)
# calculated by the binding module <i>calc_bin_widths.py</i> of the
# Python Abstration Layer (PAL) <i>utils.py</i> with the true output data
# calculated (\f$true\_output\_vv\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - VV = "v,v"
# - ERROR = "error "
# - EMPTY = ""

##
#
# This function initializes the values of arrays, \f$axis\f$ and
# \f$axis\_err2\f$.
#
# \returns
# - axis is the independent axis
# - axis_err2 is the square uncertainties of the independent axis
#
def initialize_inputs(key):
    if (key == "double"):
        axis=nessi_list.NessiList(type="double")
        axis_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            axis.append(float(i+1))
            axis_err2.append(float((i+1)*1.1))

        axis.append(float(NUM_VAL+1))
        axis_err2.append(float(1.1*(NUM_VAL+1)))
    else:
        raise TypeError

    return axis, axis_err2

##
# Function that sets the true output based on values contained in
# \f$axis\f$, and \f$axis\_err2\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case
# - The square of the uncertainty in the true NessiList for the vv case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv=nessi_list.NessiList()
        true_output_vv_err2=nessi_list.NessiList()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(1.0))
        true_output_vv_err2.append(float(3.30000000000000027))
        true_output_vv.append(float(1.0))
        true_output_vv_err2.append(float(5.5))
        true_output_vv.append(float(1.0))
        true_output_vv_err2.append(float(7.70000000000000107))
        true_output_vv.append(float(1.0))
        true_output_vv_err2.append(float(9.9))
        true_output_vv.append(float(1.0))
        true_output_vv_err2.append(float(12.1000000000000014))

    else:

        raise TypeError

    return true_output_vv, true_output_vv_err2

if __name__ == "__main__":

    mess =""

    print "#########################################################"
    print "#   Checking calc_bin_widths Python Abstraction layer   #"
    print "#########################################################"
    print

    true_output_vv_d, true_output_vv_err2_d = initialize_true_outputs("double")

    axis, axis_err2 = initialize_inputs("double")

    # vv case
    output_vv, output_vv_err2 = utils.calc_bin_widths(axis, axis_err2)
    
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess
