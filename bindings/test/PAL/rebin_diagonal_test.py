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
# \file bindings/test/PAL/rebin_diagonal_test.py
#

import axis_manip
import nessi_list
import test_common

NUM_VAL = 4

##
# \defgroup rebin_diagonal_test rebin_diagonal_test
# \{
#
# This test compares the output data (\f$output\_vv\f$) calculated by the
# binding module <i>rebin_diagonal.py</i> of the Python Abstration Layer (PAL)
# <i>axis_manip.py</i> with the true output data calculated
# (\f$true\_output\_vv\f$) manually calculated.
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
# This function initializes the values of arrays, \f$axis\_in\_1\f$,
# \f$axis\_in\_1\f$, \f$axis\_out\_1\f$, \f$axis\_out\_2\f$, \f$input\f$, and
# \f$input\_err2\f$.
#
# \returns
# - axis_in_1 is the 1st initial data axis
# - axis_in_2 is the 2nd initial data axis
# - axis_out_1 is the 1st target axis for rebinning
# - axis_out_2 is the 2nd target axis for rebinning
# - input is the data associated with the initial axis
# - input_err2 is the square of the uncertainty associated with the data
#
def initialize_inputs(key):
    if (key == "double"):
        axis_in_1 = nessi_list.NessiList(type="double")
        axis_in_2 = nessi_list.NessiList(type="double")
        axis_out_1 = nessi_list.NessiList(type="double")
        axis_out_2 = nessi_list.NessiList(type="double")
        input = nessi_list.NessiList(type="double")
        input_err2 = nessi_list.NessiList(type="double")

        axis_in_1.append(0.)
        axis_in_1.append(1.)
        axis_in_1.append(2.)
        axis_in_1.append(3.)
        axis_in_1.append(4.)

        axis_in_2.append(0.)
        axis_in_2.append(1.)
        axis_in_2.append(2.)
        axis_in_2.append(3.)
        axis_in_2.append(4.)

        axis_out_1.append(0.)
        axis_out_1.append(1.33333)
        axis_out_1.append(2.66666)
        axis_out_1.append(4.)

        axis_out_2.append(0.)
        axis_out_2.append(2.)
        axis_out_2.append(4.)

        input.append(10.)
        input.append(10.)
        input.append(10.)
        input.append(10.)

        input_err2.append(1.)
        input_err2.append(1.)
        input_err2.append(1.)
        input_err2.append(1.)

    else:
        raise TypeError

    return axis_in_1, axis_in_2, axis_out_1, axis_out_2, input, input_err2

##
# Function that sets the true output based on values contained in
# \f$axis\_in\_1\f$, \f$axis\_in\_2\f$, \f$axis\_out\_1\f$,
# \f$axis\_out\_2\f$, \f$input\f$, and \f$input\_err2\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case
# - The square of the uncertainty in the true NessiList for the vv case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv = nessi_list.NessiList()
        true_output_vv_err2 = nessi_list.NessiList()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(13.3333))
        true_output_vv.append(float(0.0))
        true_output_vv.append(float(6.66670000000000051))
        true_output_vv.append(float(6.66659999999999808))
        true_output_vv.append(float(0.0))
        true_output_vv.append(float(13.3334000000000010))

        true_output_vv_err2.append(float(1.1111088889))
        true_output_vv_err2.append(float(0.0))
        true_output_vv_err2.append(float(0.4444488889000001))
        true_output_vv_err2.append(float(0.4444355555999998))
        true_output_vv_err2.append(float(0.0))
        true_output_vv_err2.append(float(1.1111155556))

    else:

        raise TypeError

    return true_output_vv, true_output_vv_err2

if __name__ == "__main__":

    mess =""

    print "###################################################"
    print "# Checking rebin_diagonal Python Abstraction layer #"
    print "###################################################"
    print

    # generate true_outputs
    true_output_vv_d, true_output_vv_err2_d = initialize_true_outputs("double")

    # vv case
    axis_in_1,axis_in_2,axis_out_1,axis_out_2,input,input_err2=initialize_inputs("double")

    output_vv, output_vv_err2 = axis_manip.rebin_diagonal(axis_in_1,\
                                                          axis_in_2,\
                                                          input,\
                                                          input_err2,\
                                                          axis_out_1,\
                                                          axis_out_2)
    # Check values
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess

