module tb_half_subtractor;

reg A, B;
wire Difference, Borrow;

half_subtractor uut (
    .A(A),
    .B(B),
    .Difference(Difference),
    .Borrow(Borrow)
);

initial begin
    $dumpfile("dump.vcd");
  $dumpvars(0, tb_half_subtractor);

    A=0; B=0; #10;
    A=0; B=1; #10;
    A=1; B=0; #10;
    A=1; B=1; #10;

    $finish;
end

endmodule
