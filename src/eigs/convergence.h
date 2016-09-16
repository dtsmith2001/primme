/*******************************************************************************
 * Copyright (c) 2016, College of William & Mary
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the College of William & Mary nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COLLEGE OF WILLIAM & MARY BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * PRIMME: https://github.com/primme/primme
 * Contact: Andreas Stathopoulos, a n d r e a s _at_ c s . w m . e d u
 *******************************************************************************
 *   NOTE: THIS FILE IS AUTOMATICALLY GENERATED. PLEASE DON'T MODIFY
 ******************************************************************************/


#ifndef convergence_H
#define convergence_H
#if !defined(CHECK_TEMPLATE) && !defined(check_convergence_Sprimme)
#  define check_convergence_Sprimme CONCAT(check_convergence_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(check_convergence_Rprimme)
#  define check_convergence_Rprimme CONCAT(check_convergence_,REAL_SUF)
#endif
int check_convergence_dprimme(double *X, int64_t nLocal, int64_t ldX,
      double *R, int64_t ldR, double *evecs, int numLocked,
      int64_t ldevecs, int left, int right, int *flags, double *blockNorms,
      double *hVals, int *reset, double machEps, double *rwork,
      size_t *rworkSize, int *iwork, int iworkSize, primme_params *primme);
int check_convergence_zprimme(PRIMME_COMPLEX_DOUBLE *X, int64_t nLocal, int64_t ldX,
      PRIMME_COMPLEX_DOUBLE *R, int64_t ldR, PRIMME_COMPLEX_DOUBLE *evecs, int numLocked,
      int64_t ldevecs, int left, int right, int *flags, double *blockNorms,
      double *hVals, int *reset, double machEps, PRIMME_COMPLEX_DOUBLE *rwork,
      size_t *rworkSize, int *iwork, int iworkSize, primme_params *primme);
int check_convergence_sprimme(float *X, int64_t nLocal, int64_t ldX,
      float *R, int64_t ldR, float *evecs, int numLocked,
      int64_t ldevecs, int left, int right, int *flags, float *blockNorms,
      float *hVals, int *reset, double machEps, float *rwork,
      size_t *rworkSize, int *iwork, int iworkSize, primme_params *primme);
int check_convergence_cprimme(PRIMME_COMPLEX_FLOAT *X, int64_t nLocal, int64_t ldX,
      PRIMME_COMPLEX_FLOAT *R, int64_t ldR, PRIMME_COMPLEX_FLOAT *evecs, int numLocked,
      int64_t ldevecs, int left, int right, int *flags, float *blockNorms,
      float *hVals, int *reset, double machEps, PRIMME_COMPLEX_FLOAT *rwork,
      size_t *rworkSize, int *iwork, int iworkSize, primme_params *primme);
#endif