#!/bin/sh
pushd .. >& /dev/null
export DYLD_LIBRARY_PATH=`pwd`/lib:$DYLD_LIBRARY_PATH
#export LD_LIBRARY_PATH=`pwd`/lib:$LD_LIBRARY_PATH
popd >& /dev/null

