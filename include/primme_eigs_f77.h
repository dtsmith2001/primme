C*******************************************************************************
C    PRIMME PReconditioned Iterative MultiMethod Eigensolver
C    Copyright (C) 2015 College of William & Mary,
C    James R. McCombs, Eloy Romero Alcalde, Andreas Stathopoulos, Lingfei Wu
C 
C    This file is part of PRIMME.
C 
C    PRIMME is free software; you can redistribute it and/or
C    modify it under the terms of the GNU Lesser General Public
C    License as published by the Free Software Foundation; either
C    version 2.1 of the License, or (at your option) any later version.
C 
C    PRIMME is distributed in the hope that it will be useful,
C    but WITHOUT ANY WARRANTY; without even the implied warranty of
C    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
C    Lesser General Public License for more details.
C 
C    You should have received a copy of the GNU Lesser General Public
C    License along with this library; if not, write to the Free Software
C    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
C 
C*******************************************************************************
C  File: primme_eigs_f77.h
C  
C  Purpose - Main header with the PRIMME EIGS F77 interface functions.
C  
C******************************************************************************

C-------------------------------------------------------
C     Defining easy to remember labels for setting the 
C     method in primme_set_method from Fortran
C-------------------------------------------------------
      integer
     : PRIMMEF77_DEFAULT_METHOD,
     : PRIMMEF77_DYNAMIC,
     : PRIMMEF77_DEFAULT_MIN_TIME,
     : PRIMMEF77_DEFAULT_MIN_MATVECS,
     : PRIMMEF77_Arnoldi,
     : PRIMMEF77_GD,
     : PRIMMEF77_GD_plusK,
     : PRIMMEF77_GD_Olsen_plusK,
     : PRIMMEF77_JD_Olsen_plusK,
     : PRIMMEF77_RQI,
     : PRIMMEF77_JDQR,
     : PRIMMEF77_JDQMR,
     : PRIMMEF77_JDQMR_ETol,
     : PRIMMEF77_SUBSPACE_ITERATION,
     : PRIMMEF77_LOBPCG_OrthoBasis,
     : PRIMMEF77_LOBPCG_OrthoBasis_Window

      parameter(
     : PRIMMEF77_DEFAULT_METHOD = 0,
     : PRIMMEF77_DYNAMIC = 1,
     : PRIMMEF77_DEFAULT_MIN_TIME = 2,
     : PRIMMEF77_DEFAULT_MIN_MATVECS = 3,
     : PRIMMEF77_Arnoldi = 4,
     : PRIMMEF77_GD = 5,
     : PRIMMEF77_GD_plusK = 6,
     : PRIMMEF77_GD_Olsen_plusK = 7,
     : PRIMMEF77_JD_Olsen_plusK = 8,
     : PRIMMEF77_RQI = 9,
     : PRIMMEF77_JDQR = 10,
     : PRIMMEF77_JDQMR = 11,
     : PRIMMEF77_JDQMR_ETol = 12,
     : PRIMMEF77_SUBSPACE_ITERATION = 13,
     : PRIMMEF77_LOBPCG_OrthoBasis = 14,
     : PRIMMEF77_LOBPCG_OrthoBasis_Window = 15
     :)

C-------------------------------------------------------
C     Defining easy to remember labels for setting the 
C     members of the primme structure from Fortran
C-------------------------------------------------------
      INTEGER
     : PRIMMEF77_n,
     : PRIMMEF77_matrixMatvec,
     : PRIMMEF77_applyPreconditioner,
     : PRIMMEF77_numProcs,
     : PRIMMEF77_procID,
     : PRIMMEF77_commInfo,
     : PRIMMEF77_nLocal,
     : PRIMMEF77_globalSumReal,
     : PRIMMEF77_numEvals,
     : PRIMMEF77_target,
     : PRIMMEF77_numTargetShifts,
     : PRIMMEF77_targetShifts,
     : PRIMMEF77_locking,
     : PRIMMEF77_initSize,
     : PRIMMEF77_numOrthoConst,
     : PRIMMEF77_maxBasisSize,
     : PRIMMEF77_minRestartSize,
     : PRIMMEF77_maxBlockSize,
     : PRIMMEF77_maxMatvecs,
     : PRIMMEF77_maxOuterIterations,
     : PRIMMEF77_intWorkSize,
     : PRIMMEF77_realWorkSize,
     : PRIMMEF77_iseed,
     : PRIMMEF77_intWork,
     : PRIMMEF77_realWork,
     : PRIMMEF77_aNorm,
     : PRIMMEF77_eps,
     : PRIMMEF77_printLevel,
     : PRIMMEF77_outputFile,
     : PRIMMEF77_matrix,
     : PRIMMEF77_preconditioner,
     : PRIMMEF77_initBasisMode,
     : PRIMMEF77_projectionParams_projection,
     : PRIMMEF77_restartingParams_scheme,
     : PRIMMEF77_restartingParams_maxPrevRetain,
     : PRIMMEF77_correctionParams_precondition,
     : PRIMMEF77_correctionParams_robustShifts,
     : PRIMMEF77_correctionParams_maxInnerIterations,
     : PRIMMEF77_correctionParams_projectors_LeftQ,
     : PRIMMEF77_correctionParams_projectors_LeftX,
     : PRIMMEF77_correctionParams_projectors_RightQ,
     : PRIMMEF77_correctionParams_projectors_RightX,
     : PRIMMEF77_correctionParams_projectors_SkewQ,
     : PRIMMEF77_correctionParams_projectors_SkewX,
     : PRIMMEF77_correctionParams_convTest,
     : PRIMMEF77_correctionParams_relTolBase,
     : PRIMMEF77_stats_numOuterIterations,
     : PRIMMEF77_stats_numRestarts,
     : PRIMMEF77_stats_numMatvecs,
     : PRIMMEF77_stats_numPreconds,
     : PRIMMEF77_stats_elapsedTime,
     : PRIMMEF77_stats_estimateMinEVal,
     : PRIMMEF77_stats_estimateMaxEVal,
     : PRIMMEF77_stats_estimateLargestSVal,
     : PRIMMEF77_stats_maxConvTol,
     : PRIMMEF77_dynamicMethodSwitch,
     : PRIMMEF77_massMatrixMatvec,
     : PRIMMEF77_convTestFun

      parameter(
     : PRIMMEF77_n = 0,
     : PRIMMEF77_matrixMatvec = 1, 
     : PRIMMEF77_applyPreconditioner = 2,
     : PRIMMEF77_numProcs = 3,
     : PRIMMEF77_procID = 4,
     : PRIMMEF77_commInfo = 5,
     : PRIMMEF77_nLocal = 6,
     : PRIMMEF77_globalSumReal = 7,
     : PRIMMEF77_numEvals = 8,
     : PRIMMEF77_target = 9,
     : PRIMMEF77_numTargetShifts = 10,
     : PRIMMEF77_targetShifts = 11,
     : PRIMMEF77_locking = 12,
     : PRIMMEF77_initSize = 13,
     : PRIMMEF77_numOrthoConst = 14,
     : PRIMMEF77_maxBasisSize = 15,
     : PRIMMEF77_minRestartSize = 16,
     : PRIMMEF77_maxBlockSize = 17,
     : PRIMMEF77_maxMatvecs = 18,
     : PRIMMEF77_maxOuterIterations = 19,
     : PRIMMEF77_intWorkSize = 20,
     : PRIMMEF77_realWorkSize = 21,
     : PRIMMEF77_iseed = 22,
     : PRIMMEF77_intWork = 23,
     : PRIMMEF77_realWork = 24,
     : PRIMMEF77_aNorm = 25,
     : PRIMMEF77_eps = 26,
     : PRIMMEF77_printLevel = 27,
     : PRIMMEF77_outputFile = 28,
     : PRIMMEF77_matrix = 29,
     : PRIMMEF77_preconditioner = 30,
     : PRIMMEF77_initBasisMode = 301,
     : PRIMMEF77_projectionParams_projection = 302,
     : PRIMMEF77_restartingParams_scheme = 31,
     : PRIMMEF77_restartingParams_maxPrevRetain = 32,
     : PRIMMEF77_correctionParams_precondition = 33,
     : PRIMMEF77_correctionParams_robustShifts = 34,
     : PRIMMEF77_correctionParams_maxInnerIterations = 35,
     : PRIMMEF77_correctionParams_projectors_LeftQ = 36,
     : PRIMMEF77_correctionParams_projectors_LeftX = 37,
     : PRIMMEF77_correctionParams_projectors_RightQ = 38,
     : PRIMMEF77_correctionParams_projectors_RightX = 39,
     : PRIMMEF77_correctionParams_projectors_SkewQ = 40,
     : PRIMMEF77_correctionParams_projectors_SkewX = 41,
     : PRIMMEF77_correctionParams_convTest = 42,
     : PRIMMEF77_correctionParams_relTolBase = 43,
     : PRIMMEF77_stats_numOuterIterations = 44,
     : PRIMMEF77_stats_numRestarts = 45,
     : PRIMMEF77_stats_numMatvecs = 46,
     : PRIMMEF77_stats_numPreconds = 47,
     : PRIMMEF77_stats_elapsedTime = 48,
     : PRIMMEF77_stats_estimateMinEVal = 481,
     : PRIMMEF77_stats_estimateMaxEVal = 482,
     : PRIMMEF77_stats_estimateLargestSVal = 483,
     : PRIMMEF77_stats_maxConvTol = 484,
     : PRIMMEF77_dynamicMethodSwitch = 49,
     : PRIMMEF77_massMatrixMatvec = 50,
     : PRIMMEF77_convTestFun = 51
     : )

C-------------------------------------------------------
C    Defining easy to remember labels for setting the 
C    enum members for targeting, restarting and innertest
C-------------------------------------------------------

      integer 
     : PRIMMEF77_smallest,
     : PRIMMEF77_largest,
     : PRIMMEF77_closest_geq,
     : PRIMMEF77_closest_leq,
     : PRIMMEF77_closest_abs,
     : PRIMMEF77_largest_abs,
     : PRIMMEF77_proj_default,
     : PRIMMEF77_proj_RR,
     : PRIMMEF77_proj_harmonic,
     : PRIMMEF77_proj_refined,
     : PRIMMEF77_init_default,
     : PRIMMEF77_init_krylov,
     : PRIMMEF77_init_random,
     : PRIMMEF77_init_user,
     : PRIMMEF77_thick,
     : PRIMMEF77_dtr,
     : PRIMMEF77_full_LTolerance,
     : PRIMMEF77_decreasing_LTolerance,
     : PRIMMEF77_adaptive_ETolerance,
     : PRIMMEF77_adaptive

      parameter(
     : PRIMMEF77_smallest = 0,
     : PRIMMEF77_largest = 1,
     : PRIMMEF77_closest_geq = 2,
     : PRIMMEF77_closest_leq = 3,
     : PRIMMEF77_closest_abs = 4,
     : PRIMMEF77_largest_abs = 5,
     : PRIMMEF77_proj_default = 0,
     : PRIMMEF77_proj_RR = 1,
     : PRIMMEF77_proj_harmonic = 2,
     : PRIMMEF77_proj_refined = 3,
     : PRIMMEF77_init_default = 0,
     : PRIMMEF77_init_krylov = 1,
     : PRIMMEF77_init_random = 2,
     : PRIMMEF77_init_user = 3,
     : PRIMMEF77_thick = 0,
     : PRIMMEF77_dtr = 1,
     : PRIMMEF77_full_LTolerance = 0,
     : PRIMMEF77_decreasing_LTolerance = 1,
     : PRIMMEF77_adaptive_ETolerance = 2,
     : PRIMMEF77_adaptive = 3
     : )
