/*
    author: sergey boldenko
    data  : 18.07.2022
*/

module gowin_arm_m3_uart_top
(
    input  clk_i,
    input  reset_n_i,
    input  uart_rxd_i,
    output uart_txd_o
);

    wire reset;
    wire reset_n;
    wire clk_24;
    wire clk_160;
    wire clk_40;

    assign reset = ~reset_n_i;

    gowin_pllvr_24 gowin_pllvr_24_inst
    (
        .clkout ( clk_24  ), //output clkout
        .lock   ( reset_n ), //output lock
        .reset  ( reset   ), //input  reset
        .clkin  ( clk_i   )  //input  clkin
    );

    gowin_pllvr_160_40 gowin_pllvr_160_40_inst
    (
        .clkout  ( clk_160 ), //output clkout
        .clkoutd ( clk_40  ), //output clkoutd
        .clkin   ( clk_24  )  //input  clkin
    );

	gowin_empu_m3 gowin_empu_m3_inst
	(
		.sys_clk   ( clk_40     ), //input         sys_clk
		.uart0_rxd ( uart_rxd_i ), //input         uart0_rxd
		.uart0_txd ( uart_txd_o ), //output        uart0_txd
		.reset_n   ( reset_n    )  //input         reset_n
	);

endmodule