@echo off
set MATLAB=C:\Program Files\MATLAB\R2018a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2018a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=score_func_mex
set MEX_NAME=score_func_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for score_func > score_func_mex.mki
echo COMPILER=%COMPILER%>> score_func_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> score_func_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> score_func_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> score_func_mex.mki
echo LINKER=%LINKER%>> score_func_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> score_func_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> score_func_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> score_func_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> score_func_mex.mki
echo OMPFLAGS= >> score_func_mex.mki
echo OMPLINKFLAGS= >> score_func_mex.mki
echo EMC_COMPILER=msvc150>> score_func_mex.mki
echo EMC_CONFIG=optim>> score_func_mex.mki
"C:\Program Files\MATLAB\R2018a\bin\win64\gmake" -j 1 -B -f score_func_mex.mk
