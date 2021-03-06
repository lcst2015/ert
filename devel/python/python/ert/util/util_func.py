#  Copyright (C) 2011  Statoil ASA, Norway. 
#   
#  The file 'util_func.py' is part of ERT - Ensemble based Reservoir Tool. 
#   
#  ERT is free software: you can redistribute it and/or modify 
#  it under the terms of the GNU General Public License as published by 
#  the Free Software Foundation, either version 3 of the License, or 
#  (at your option) any later version. 
#   
#  ERT is distributed in the hope that it will be useful, but WITHOUT ANY 
#  WARRANTY; without even the implied warranty of MERCHANTABILITY or 
#  FITNESS FOR A PARTICULAR PURPOSE.   
#   
#  See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
#  for more details. 
"""
Module with utility functions from util.c
"""

from ert.util import UTIL_LIB
from ert.cwrap import CWrapper, CWrapperNameSpace


def strcmp_int( s1, s2):
    """
    Function to compare strings with embedded integers. 

    Will use proper numeric comparison when comparing strings with
    embedded numbers, i.e. "CASE-9" will follow after "CASE-10" when
    sorting:
    
       >> l = ["CASE-9" , "CASE-10"]
       >> l.sort()
       >> print l  
          ["CASE-10" , "CASE-9"]
       >> l.sort( strcmp_int )
       >> print l
          ["CASE-9" , "CASE-10"]   

    When the standard strcmp() function is used for comparing strings
    the '1' will compare as less than the '9' and the order will be
    the reverse. Observe that the '-' is not interpreted as a sign
    prefix. The strcmp_int function will interpret '.' as separating
    character, wheras the strcmp_float() function will interpret '.'
    as a descimal point.
    """
    return cfunc.strcmp_int(s1, s2)


def strcmp_float( s1, s2):
    """
    Function to compare strings with embedded numbers.

    See documentation of strcmp_int() for further details.
    """
    return cfunc.strcmp_float(s1, s2)


cwrapper = CWrapper(UTIL_LIB)
cfunc = CWrapperNameSpace("util_func")

cfunc.strcmp_int = cwrapper.prototype("int util_strcmp_int( char* , char* )")
cfunc.strcmp_float = cwrapper.prototype("int util_strcmp_float( char* , char* )")
