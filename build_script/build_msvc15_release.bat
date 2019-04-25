@echo off

setlocal

set BUILDDIR=..\_build_msvc15_release
rd /s /q %~dp0\%BUILDDIR%
mkdir %~dp0\%BUILDDIR%
PUSHD %~dp0\%BUILDDIR%

cmake -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX=target ^
-DCMAKE_BUILD_TYPE=Release .. || (goto:abortfunc)

nmake || (goto:abortfunc)

exit /B 0

:abortfunc
exit /B 1
