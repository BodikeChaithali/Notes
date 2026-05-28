module half_subtractor (
    input A, B,
    output Difference, Borrow
);

assign Difference = A ^ B;
assign Borrow = (~A) & B;

endmodule
