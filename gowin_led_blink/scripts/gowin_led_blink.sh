#!/bin/bash

IDE_PATH=/home/sboldenko/programs/Gowin_V1.9.8.06-1/IDE/bin
PROJECT_PATH=$(pwd)

cd ../

$IDE_PATH/gw_sh $PROJECT_PATH/gowin_led_blink.tcl