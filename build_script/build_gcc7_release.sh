#!/bin/bash -xe

export AR=gcc-ar-7
export CC=gcc-7
export CPP=g++-7
export CXX=g++-7


BUILDDIR="../_build_gcc7_release"
rm -rf $BUILDDIR || true
mkdir $BUILDDIR
cd $BUILDDIR

cmake -DCMAKE_INSTALL_PREFIX=target -DCMAKE_BUILD_TYPE=Release ..

make
