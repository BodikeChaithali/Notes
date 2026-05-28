module full_subtractor (
    input A, B, Bin,
    output Difference, Borrow
);

assign Difference = A ^ B ^ Bin;
assign Borrow = (~A & B) | (~A & Bin) | (B & Bin);

endmodule
