#author: sergey boldenko
#data  : 07.08.2022

set_device GW1NSR-LV4CQN48PC6/I5 -name GW1NSR-4C

add_file src/hdl/gowin_arm_m3_uart_top.v
add_file src/ip/gowin_pllvr_24/gowin_pllvr_24.v
add_file src/ip/gowin_pllvr_160_40/gowin_pllvr_160_40.v
add_file src/ip/gowin_empu/gowin_empu.v
add_file src/constraints/gowin_arm_m3_uart.sdc
add_file src/constraints/gowin_arm_m3_uart.cst

set_option -synthesis_tool gowinsynthesis
set_option -output_base_name gowin_arm_m3_hello_world
set_option -verilog_std v2001
set_option -top_module gowin_arm_m3_uart_top

run all