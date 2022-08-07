#!/bin/bash

#author: sergey boldenko
#data  : 07.08.2022

IDE_PATH=/home/sboldenko/programs/Gowin_V1.9.8.06-1/IDE/bin
PROJECT_PATH=$(pwd)

cd ../

$IDE_PATH/gw_sh $PROJECT_PATH/build.tcl