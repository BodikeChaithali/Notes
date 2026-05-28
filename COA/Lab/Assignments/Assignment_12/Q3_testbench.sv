module tb_d_flipflop;

reg clk, reset, d;
wire q;

d_flipflop uut (
    .clk(clk),
    .reset(reset),
    .d(d),
    .q(q)
);

// clock generation
always #5 clk = ~clk;

initial begin
    $dumpfile("dump.vcd");
    $dumpvars(0, tb_d_flipflop);

    clk = 0;

    // time 0
    reset = 1; d = 0;
    #10;

    // time 5 (posedge clk)
    reset = 0; d = 1;
    #10;

    // time 15
    d = 0;
    #10;

    // time 25
    d = 1;
    #10;

    $finish;
end

endmodule
