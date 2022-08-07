#author: sergey boldenko
#data  : 06.08.2022

set_device GW1NSR-LV4CQN48PC6/I5 -name GW1NSR-4C

add_file src/hdl/led_blink.v
add_file src/constraints/gowin_led_blink.sdc
add_file src/constraints/gowin_led_blink.cst

set_option -synthesis_tool gowinsynthesis
set_option -output_base_name gowin_led_blink
set_option -verilog_std v2001
set_option -top_module led_blink

run all