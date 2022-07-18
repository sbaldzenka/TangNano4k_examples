/*
    author: sergey boldenko
    data  : 18.07.2022
*/

create_clock -name CLK_IN -period 37.037 -waveform {0 18.52} [get_ports {clk_i}]