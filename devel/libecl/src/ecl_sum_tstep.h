 /*
   Copyright (C) 2012  Statoil ASA, Norway. 
    
   The file 'ecl_sum_tstep.h' is part of ERT - Ensemble based Reservoir Tool. 
    
   ERT is free software: you can redistribute it and/or modify 
   it under the terms of the GNU General Public License as published by 
   the Free Software Foundation, either version 3 of the License, or 
   (at your option) any later version. 
    
   ERT is distributed in the hope that it will be useful, but WITHOUT ANY 
   WARRANTY; without even the implied warranty of MERCHANTABILITY or 
   FITNESS FOR A PARTICULAR PURPOSE.   
    
   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
   for more details. 
*/

#ifndef __ECL_SUM_TSTEP_H__
#define __ECL_SUM_TSTEP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <ecl_smspec.h>
#include <ecl_kw.h>

typedef struct ecl_sum_tstep_struct ecl_sum_tstep_type;


  void ecl_sum_tstep_free( ecl_sum_tstep_type * ministep );
  void ecl_sum_tstep_free__( void * __ministep);
  ecl_sum_tstep_type * ecl_sum_tstep_alloc( int ministep_nr            ,
                                                  int report_step    ,
                                                  const ecl_kw_type * params_kw , 
                                                  const char * src_file , 
                                                  const ecl_smspec_type * smspec);
  
  double ecl_sum_tstep_iget(const ecl_sum_tstep_type * ministep , int index);
  time_t ecl_sum_tstep_get_sim_time(const ecl_sum_tstep_type * ministep);
  double ecl_sum_tstep_get_sim_days(const ecl_sum_tstep_type * ministep);
  int  ecl_sum_tstep_get_report(const ecl_sum_tstep_type * ministep);
  int  ecl_sum_tstep_get_ministep(const ecl_sum_tstep_type * ministep);

  void ecl_sum_tstep_fwrite( const ecl_sum_tstep_type * ministep , fortio_type * fortio);
  
  UTIL_SAFE_CAST_HEADER( ecl_sum_tstep );
  UTIL_SAFE_CAST_HEADER_CONST( ecl_sum_tstep );



#ifdef __cplusplus
}
#endif
#endif
