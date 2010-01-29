#! /bin/sh

#DOUBLEDEFINE="-DPRJACUDADOUBLE"
DOUBLEDEFINE=""
export DOUBLEDEFINE

#DOUBLEFLAGS="$DOUBLEDEFINE --gpu-architecture sm_13"
DOUBLEFLAGS=""

PRJACUDACFLAGS="-deviceemu -DPRJCUDAEMU -I include/common -I include $DOUBLEFLAGS"
export PRJACUDACFLAGS

PRJACUDAOBJEXT=o
export PRJACUDAOBJEXT

PRJACUDAEXEEXT=exe
export PRJACUDAEXEEXT

PRJACUDAHOSTLD=gcc
export PRJACUDAHOSTLD

PRJACUDALIBEXT=a
export PRJACUDALIBEXT

PRJACUDAHOSCC=gcc
export PRJACUDAHOSCC