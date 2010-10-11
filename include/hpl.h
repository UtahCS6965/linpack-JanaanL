/* 
 * This is a modified version of the High Performance Computing Linpack
 * Benchmark (HPL). All code not contained in the original HPL version
 * 2.0 is property of the Frankfurt Institute for Advanced Studies
 * (FIAS). None of the material may be copied, reproduced, distributed,
 * republished, downloaded, displayed, posted or transmitted in any form
 * or by any means, including, but not limited to, electronic,
 * mechanical, photocopying, recording, or otherwise, without the prior
 * written permission of FIAS. For those parts contained in the
 * unmodified version of the HPL the below copyright notice applies.
 * 
 * Authors:
 * David Rohr (drohr@jwdt.org)
 * Matthias Bach (bach@compeng.uni-frankfurt.de)
 * Matthias Kretz (kretz@compeng.uni-frankfurt.de)
 * 
 * -- High Performance Computing Linpack Benchmark (HPL)                
 *    HPL - 2.0 - September 10, 2008                          
 *    Antoine P. Petitet                                                
 *    University of Tennessee, Knoxville                                
 *    Innovative Computing Laboratory                                 
 *    (C) Copyright 2000-2008 All Rights Reserved                       
 *                                                                      
 * -- Copyright notice and Licensing terms:                             
 *                                                                      
 * Redistribution  and  use in  source and binary forms, with or without
 * modification, are  permitted provided  that the following  conditions
 * are met:                                                             
 *                                                                      
 * 1. Redistributions  of  source  code  must retain the above copyright
 * notice, this list of conditions and the following disclaimer.        
 *                                                                      
 * 2. Redistributions in binary form must reproduce  the above copyright
 * notice, this list of conditions,  and the following disclaimer in the
 * documentation and/or other materials provided with the distribution. 
 *                                                                      
 * 3. All  advertising  materials  mentioning  features  or  use of this
 * software must display the following acknowledgement:                 
 * This  product  includes  software  developed  at  the  University  of
 * Tennessee, Knoxville, Innovative Computing Laboratory.             
 *                                                                      
 * 4. The name of the  University,  the name of the  Laboratory,  or the
 * names  of  its  contributors  may  not  be used to endorse or promote
 * products  derived   from   this  software  without  specific  written
 * permission.                                                          
 *                                                                      
 * -- Disclaimer:                                                       
 *                                                                      
 * THIS  SOFTWARE  IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE UNIVERSITY
 * OR  CONTRIBUTORS  BE  LIABLE FOR ANY  DIRECT,  INDIRECT,  INCIDENTAL,
 * SPECIAL,  EXEMPLARY,  OR  CONSEQUENTIAL DAMAGES  (INCLUDING,  BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA OR PROFITS; OR BUSINESS INTERRUPTION)  HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT,  STRICT LIABILITY,  OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */ 
#ifndef HPL_H
#define HPL_H
/*
 * ---------------------------------------------------------------------
 * HPL default compile options that can overridden in the Make.<arch>
 * ---------------------------------------------------------------------
 */
#ifndef HPL_NO_MPI_DATATYPE         /* Use MPI user-defined data type */
#define HPL_USE_MPI_DATATYPE
#endif
 
#ifndef HPL_COPY_L  /* do not copy L, use MPI user-defined data types */
#define HPL_NO_COPY_L
#endif
 
#ifndef HPL_DETAILED_TIMING         /* Do not enable detailed timings */
#define HPL_NO_DETAILED_TIMING
#endif
 
#ifndef TRACE_CALLS                  /* Don't trace on function level */
#define NO_TRACE_CALLS
#endif
 
#ifndef HPL_CALL_CBLAS                       /* there can be only one */
#define HPL_CALL_FBLAS
#endif

#ifdef HPL_CALL_CALBLAS                     /* CALBLAS requires CBLAS */
#ifndef HPL_CALL_CBLAS
#define HPL_CALL_CBLAS
#endif
#endif
 
#ifndef HPL_CALL_CBLAS                    /* Dont use cblas interface */
#define HPL_NO_CALL_CBLAS
#endif

/*
 * ---------------------------------------------------------------------
 * Include files
 * ---------------------------------------------------------------------
 */
#include "hpl_misc.h"
#include "hpl_blas.h"
#include "hpl_auxil.h"
#include "hpl_gesv.h"

#include "hpl_pmisc.h"
#include "hpl_pauxil.h"
#include "hpl_panel.h"
#include "hpl_pfact.h"
#include "hpl_pgesv.h"

#include "hpl_timer.h"
#include "hpl_matgen.h"
#include "hpl_test.h"

#include "hpl_ptimer.h"
#include "hpl_pmatgen.h"
#include "hpl_ptest.h"

#ifdef HPL_DETAILED_TIMING
#define HPL_ptimer_detail(arg) HPL_ptimer(arg)
#else
#define HPL_ptimer_detail(arg)
#endif

#ifdef CALDGEMM_TEST
#define fprintfct fprintf
#else
#define fprintfct(...)
#endif

#endif
/*
 * End of hpl.h
 */
