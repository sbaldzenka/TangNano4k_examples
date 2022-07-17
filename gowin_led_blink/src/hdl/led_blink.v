/*
    author: sergey boldenko
    data  : 17.07.2022
*/

module led_blink
(
    input  clk_i,
    input  reset_n_i,
    output led_o
);

    reg [23:0] counter;
    reg        polarity;

    always@(posedge clk_i) begin
        if (!reset_n_i)
            counter <= 24'h00000;
        else
            counter <= counter + 1'b1;

        if (counter == 24'hFFFFF)
            polarity <= ~polarity;
    end

    assign led_o = polarity;

endmodule