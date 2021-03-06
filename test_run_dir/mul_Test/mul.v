module mul(
  input         clock,
  input         reset,
  input  [31:0] io_input1,
  input  [31:0] io_input2,
  output [31:0] io_result
);
  wire  signBitIn1 = io_input1[31]; // @[mul.scala 12:38]
  wire  signBitIn2 = io_input2[31]; // @[mul.scala 13:38]
  wire [7:0] expBitIn1 = io_input1[30:23]; // @[mul.scala 16:25]
  wire [7:0] expBitIn2 = io_input2[30:23]; // @[mul.scala 18:25]
  wire [22:0] fracBitIn1_lo = io_input1[22:0]; // @[mul.scala 21:34]
  wire [23:0] fracBitIn1 = {1'h1,fracBitIn1_lo}; // @[Cat.scala 30:58]
  wire [22:0] fracBitIn2_lo = io_input2[22:0]; // @[mul.scala 23:34]
  wire [23:0] fracBitIn2 = {1'h1,fracBitIn2_lo}; // @[Cat.scala 30:58]
  wire  xorSign = signBitIn1 ^ signBitIn2; // @[mul.scala 35:28]
  wire [7:0] _o_exp_T_1 = expBitIn1 + expBitIn2; // @[mul.scala 51:28]
  wire [7:0] _o_exp_T_3 = _o_exp_T_1 - 8'h7f; // @[mul.scala 51:39]
  wire [47:0] _o_mant_T = fracBitIn1 * fracBitIn2; // @[mul.scala 53:29]
  wire [47:0] o_mant = io_input1 == 32'h0 | io_input2 == 32'h0 ? 48'h0 : _o_mant_T; // @[mul.scala 45:45 mul.scala 42:9 mul.scala 53:15]
  wire [47:0] _temFrac_T = {{1'd0}, o_mant[47:1]}; // @[mul.scala 56:31]
  wire [7:0] o_exp = io_input1 == 32'h0 | io_input2 == 32'h0 ? 8'h0 : _o_exp_T_3; // @[mul.scala 45:45 mul.scala 41:8 mul.scala 51:15]
  wire [7:0] _temExp_T_1 = o_exp + 8'h1; // @[mul.scala 57:29]
  wire [52:0] _GEN_22 = {o_mant, 5'h0}; // @[mul.scala 60:35]
  wire [54:0] _temFrac_T_1 = {{2'd0}, _GEN_22}; // @[mul.scala 60:35]
  wire [7:0] _temExp_T_3 = o_exp - 8'h5; // @[mul.scala 61:33]
  wire [51:0] _GEN_23 = {o_mant, 4'h0}; // @[mul.scala 63:35]
  wire [54:0] _temFrac_T_2 = {{3'd0}, _GEN_23}; // @[mul.scala 63:35]
  wire [7:0] _temExp_T_5 = o_exp - 8'h4; // @[mul.scala 64:33]
  wire [50:0] _temFrac_T_3 = {o_mant, 3'h0}; // @[mul.scala 66:35]
  wire [7:0] _temExp_T_7 = o_exp - 8'h3; // @[mul.scala 67:33]
  wire [49:0] _GEN_24 = {o_mant, 2'h0}; // @[mul.scala 69:35]
  wire [50:0] _temFrac_T_4 = {{1'd0}, _GEN_24}; // @[mul.scala 69:35]
  wire [7:0] _temExp_T_9 = o_exp - 8'h2; // @[mul.scala 70:33]
  wire [48:0] _temFrac_T_5 = {o_mant, 1'h0}; // @[mul.scala 72:35]
  wire [7:0] _temExp_T_11 = o_exp - 8'h1; // @[mul.scala 73:33]
  wire [48:0] _GEN_0 = o_mant[46:45] == 2'h1 ? _temFrac_T_5 : 49'h0; // @[mul.scala 71:48 mul.scala 72:25 mul.scala 76:25]
  wire [7:0] _GEN_1 = o_mant[46:45] == 2'h1 ? _temExp_T_11 : 8'h0; // @[mul.scala 71:48 mul.scala 73:24 mul.scala 77:24]
  wire [50:0] _GEN_2 = o_mant[46:44] == 3'h1 ? _temFrac_T_4 : {{2'd0}, _GEN_0}; // @[mul.scala 68:49 mul.scala 69:25]
  wire [7:0] _GEN_3 = o_mant[46:44] == 3'h1 ? _temExp_T_9 : _GEN_1; // @[mul.scala 68:49 mul.scala 70:24]
  wire [50:0] _GEN_4 = o_mant[46:43] == 4'h1 ? _temFrac_T_3 : _GEN_2; // @[mul.scala 65:50 mul.scala 66:25]
  wire [7:0] _GEN_5 = o_mant[46:43] == 4'h1 ? _temExp_T_7 : _GEN_3; // @[mul.scala 65:50 mul.scala 67:24]
  wire [54:0] _GEN_6 = o_mant[46:42] == 5'h1 ? _temFrac_T_2 : {{4'd0}, _GEN_4}; // @[mul.scala 62:51 mul.scala 63:25]
  wire [7:0] _GEN_7 = o_mant[46:42] == 5'h1 ? _temExp_T_5 : _GEN_5; // @[mul.scala 62:51 mul.scala 64:24]
  wire [54:0] _GEN_8 = o_mant[46:41] == 6'h1 ? _temFrac_T_1 : _GEN_6; // @[mul.scala 59:46 mul.scala 60:25]
  wire [7:0] _GEN_9 = o_mant[46:41] == 6'h1 ? _temExp_T_3 : _GEN_7; // @[mul.scala 59:46 mul.scala 61:24]
  wire [54:0] _GEN_10 = ~o_mant[46] & o_exp != 8'h0 ? _GEN_8 : {{7'd0}, o_mant}; // @[mul.scala 58:52 mul.scala 81:21]
  wire [7:0] _GEN_11 = ~o_mant[46] & o_exp != 8'h0 ? _GEN_9 : o_exp; // @[mul.scala 58:52 mul.scala 82:20]
  wire [54:0] _GEN_12 = o_mant[47] ? {{7'd0}, _temFrac_T} : _GEN_10; // @[mul.scala 55:31 mul.scala 56:21]
  wire [7:0] _GEN_13 = o_mant[47] ? _temExp_T_1 : _GEN_11; // @[mul.scala 55:31 mul.scala 57:20]
  wire [54:0] _GEN_18 = io_input1 == 32'h0 | io_input2 == 32'h0 ? 55'h0 : _GEN_12; // @[mul.scala 45:45 mul.scala 37:10]
  wire [47:0] temFrac = _GEN_18[47:0]; // @[mul.scala 25:21]
  wire [23:0] _GEN_20 = io_input1 == 32'h0 | io_input2 == 32'h0 ? 24'h0 : temFrac[46:23]; // @[mul.scala 45:45 mul.scala 39:11 mul.scala 84:17]
  wire [24:0] tmptFrac = {{1'd0}, _GEN_20}; // @[mul.scala 28:22]
  wire [22:0] io_result_lo = tmptFrac[22:0]; // @[mul.scala 85:46]
  wire  o_sign = io_input1 == 32'h0 | io_input2 == 32'h0 ? 1'h0 : xorSign; // @[mul.scala 45:45 mul.scala 40:9 mul.scala 49:15]
  wire [7:0] temExp = io_input1 == 32'h0 | io_input2 == 32'h0 ? 8'h0 : _GEN_13; // @[mul.scala 45:45 mul.scala 38:9]
  wire [31:0] _io_result_T = {o_sign,temExp,io_result_lo}; // @[Cat.scala 30:58]
  assign io_result = io_input1 == 32'h0 | io_input2 == 32'h0 ? 32'h0 : _io_result_T; // @[mul.scala 45:45 mul.scala 46:18 mul.scala 85:18]
endmodule
