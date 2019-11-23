#!/bin/bash
# get the location of the current script
SCIRPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )" 
# get where the user currently is 
USER_DIR=${PWD}

# move to where the script is located
cd $SCIRPT_DIR

cd ..
cd round\ robin/

mkdir bin
make

cd .. 
cd sjf

# create bin folder 
mkdir bin
# create the project
make
# return the user to the directory they where in originaly
cd $USER_DIR
echo "done"
