module NFALU(
  input         clock,
  input         reset,
  input  [31:0] io_input1,
  input  [31:0] io_input2,
  output [31:0] io_result
);
  wire  signBitIn1 = io_input1[31]; // @[NFALU.scala 13:40]
  wire  signBitIn2 = io_input2[31]; // @[NFALU.scala 14:40]
  wire [7:0] expBitIn1 = io_input1[30:23]; // @[NFALU.scala 17:27]
  wire [7:0] expBitIn2 = io_input2[30:23]; // @[NFALU.scala 19:27]
  wire [22:0] fracBitIn1_lo = io_input1[22:0]; // @[NFALU.scala 22:36]
  wire [23:0] fracBitIn1 = {1'h1,fracBitIn1_lo}; // @[Cat.scala 30:58]
  wire [22:0] fracBitIn2_lo = io_input2[22:0]; // @[NFALU.scala 24:36]
  wire [23:0] fracBitIn2 = {1'h1,fracBitIn2_lo}; // @[Cat.scala 30:58]
  wire  andSign = signBitIn1 & signBitIn2; // @[NFALU.scala 27:30]
  wire  _T_1 = signBitIn1 == signBitIn2; // @[NFALU.scala 53:24]
  wire [23:0] o_mant_lo = fracBitIn1 + fracBitIn2; // @[NFALU.scala 55:40]
  wire [24:0] _o_mant_T_1 = {1'h1,o_mant_lo}; // @[Cat.scala 30:58]
  wire [23:0] o_mant_lo_1 = fracBitIn1 - fracBitIn2; // @[NFALU.scala 60:43]
  wire [24:0] _o_mant_T_3 = {1'h0,o_mant_lo_1}; // @[Cat.scala 30:58]
  wire [23:0] o_mant_lo_2 = fracBitIn2 - fracBitIn1; // @[NFALU.scala 63:43]
  wire [24:0] _o_mant_T_5 = {1'h0,o_mant_lo_2}; // @[Cat.scala 30:58]
  wire  _GEN_0 = fracBitIn1 > fracBitIn2 ? signBitIn1 : signBitIn2; // @[NFALU.scala 58:39 NFALU.scala 59:22 NFALU.scala 62:22]
  wire [24:0] _GEN_1 = fracBitIn1 > fracBitIn2 ? _o_mant_T_3 : _o_mant_T_5; // @[NFALU.scala 58:39 NFALU.scala 60:22 NFALU.scala 63:22]
  wire  _GEN_2 = signBitIn1 == signBitIn2 ? andSign : _GEN_0; // @[NFALU.scala 53:38 NFALU.scala 54:19]
  wire [24:0] _GEN_3 = signBitIn1 == signBitIn2 ? _o_mant_T_1 : _GEN_1; // @[NFALU.scala 53:38 NFALU.scala 55:19]
  wire [7:0] _diff_T_1 = expBitIn1 - expBitIn2; // @[NFALU.scala 71:29]
  wire [7:0] _diff_T_3 = expBitIn2 - expBitIn1; // @[NFALU.scala 81:29]
  wire [7:0] _GEN_8 = expBitIn1 > expBitIn2 ? _diff_T_1 : _diff_T_3; // @[NFALU.scala 68:34 NFALU.scala 71:17 NFALU.scala 81:17]
  wire [7:0] diff = expBitIn1 == expBitIn2 ? 8'h0 : _GEN_8; // @[NFALU.scala 51:32 NFALU.scala 43:9]
  wire [23:0] _tmp_mant_T = fracBitIn2 >> diff; // @[NFALU.scala 72:35]
  wire [24:0] _o_mant_T_6 = {1'h0,1'h1,fracBitIn1_lo}; // @[Cat.scala 30:58]
  wire [23:0] _lo_T = fracBitIn1 >> diff; // @[NFALU.scala 82:35]
  wire [23:0] _GEN_9 = expBitIn1 > expBitIn2 ? _tmp_mant_T : _lo_T; // @[NFALU.scala 68:34 NFALU.scala 72:21 NFALU.scala 82:21]
  wire [23:0] tmp_mant = expBitIn1 == expBitIn2 ? 24'h0 : _GEN_9; // @[NFALU.scala 51:32 NFALU.scala 41:13]
  wire [24:0] _o_mant_T_7 = {1'h0,tmp_mant}; // @[Cat.scala 30:58]
  wire [24:0] _o_mant_T_9 = _o_mant_T_6 + _o_mant_T_7; // @[NFALU.scala 74:45]
  wire [24:0] _o_mant_T_13 = _o_mant_T_6 - _o_mant_T_7; // @[NFALU.scala 76:45]
  wire [24:0] _GEN_4 = _T_1 ? _o_mant_T_9 : _o_mant_T_13; // @[NFALU.scala 73:42 NFALU.scala 74:23 NFALU.scala 76:23]
  wire [24:0] _o_mant_T_14 = {1'h0,1'h1,fracBitIn2_lo}; // @[Cat.scala 30:58]
  wire [24:0] _o_mant_T_17 = _o_mant_T_14 + _o_mant_T_7; // @[NFALU.scala 84:45]
  wire [24:0] _o_mant_T_21 = _o_mant_T_14 - _o_mant_T_7; // @[NFALU.scala 86:45]
  wire [24:0] _GEN_5 = _T_1 ? _o_mant_T_17 : _o_mant_T_21; // @[NFALU.scala 83:42 NFALU.scala 84:23 NFALU.scala 86:23]
  wire [7:0] _GEN_6 = expBitIn1 > expBitIn2 ? expBitIn1 : expBitIn2; // @[NFALU.scala 68:34 NFALU.scala 69:18 NFALU.scala 79:18]
  wire  _GEN_7 = expBitIn1 > expBitIn2 ? signBitIn1 : signBitIn2; // @[NFALU.scala 68:34 NFALU.scala 70:19 NFALU.scala 80:19]
  wire [24:0] _GEN_10 = expBitIn1 > expBitIn2 ? _GEN_4 : _GEN_5; // @[NFALU.scala 68:34]
  wire [7:0] o_exp = expBitIn1 == expBitIn2 ? expBitIn1 : _GEN_6; // @[NFALU.scala 51:32 NFALU.scala 52:14]
  wire  o_sign = expBitIn1 == expBitIn2 ? _GEN_2 : _GEN_7; // @[NFALU.scala 51:32]
  wire [24:0] o_mant = expBitIn1 == expBitIn2 ? _GEN_3 : _GEN_10; // @[NFALU.scala 51:32]
  wire [24:0] _temFrac_T = {{1'd0}, o_mant[24:1]}; // @[NFALU.scala 95:27]
  wire [7:0] _temExp_T_1 = o_exp + 8'h1; // @[NFALU.scala 96:25]
  wire [44:0] _GEN_61 = {o_mant, 20'h0}; // @[NFALU.scala 100:31]
  wire [55:0] _temFrac_T_1 = {{11'd0}, _GEN_61}; // @[NFALU.scala 100:31]
  wire [7:0] _temExp_T_3 = o_exp - 8'h14; // @[NFALU.scala 101:29]
  wire [43:0] _GEN_62 = {o_mant, 19'h0}; // @[NFALU.scala 103:31]
  wire [55:0] _temFrac_T_2 = {{12'd0}, _GEN_62}; // @[NFALU.scala 103:31]
  wire [7:0] _temExp_T_5 = o_exp - 8'h13; // @[NFALU.scala 104:29]
  wire [42:0] _GEN_63 = {o_mant, 18'h0}; // @[NFALU.scala 106:31]
  wire [55:0] _temFrac_T_3 = {{13'd0}, _GEN_63}; // @[NFALU.scala 106:31]
  wire [7:0] _temExp_T_7 = o_exp - 8'h12; // @[NFALU.scala 107:29]
  wire [41:0] _GEN_64 = {o_mant, 17'h0}; // @[NFALU.scala 109:31]
  wire [55:0] _temFrac_T_4 = {{14'd0}, _GEN_64}; // @[NFALU.scala 109:31]
  wire [7:0] _temExp_T_9 = o_exp - 8'h11; // @[NFALU.scala 110:29]
  wire [40:0] _GEN_65 = {o_mant, 16'h0}; // @[NFALU.scala 112:31]
  wire [55:0] _temFrac_T_5 = {{15'd0}, _GEN_65}; // @[NFALU.scala 112:31]
  wire [7:0] _temExp_T_11 = o_exp - 8'h10; // @[NFALU.scala 113:29]
  wire [39:0] _temFrac_T_6 = {o_mant, 15'h0}; // @[NFALU.scala 115:31]
  wire [7:0] _temExp_T_13 = o_exp - 8'hf; // @[NFALU.scala 116:29]
  wire [38:0] _GEN_66 = {o_mant, 14'h0}; // @[NFALU.scala 118:31]
  wire [39:0] _temFrac_T_7 = {{1'd0}, _GEN_66}; // @[NFALU.scala 118:31]
  wire [7:0] _temExp_T_15 = o_exp - 8'he; // @[NFALU.scala 119:29]
  wire [37:0] _GEN_67 = {o_mant, 13'h0}; // @[NFALU.scala 121:31]
  wire [39:0] _temFrac_T_8 = {{2'd0}, _GEN_67}; // @[NFALU.scala 121:31]
  wire [7:0] _temExp_T_17 = o_exp - 8'hd; // @[NFALU.scala 122:29]
  wire [36:0] _GEN_68 = {o_mant, 12'h0}; // @[NFALU.scala 124:31]
  wire [39:0] _temFrac_T_9 = {{3'd0}, _GEN_68}; // @[NFALU.scala 124:31]
  wire [7:0] _temExp_T_19 = o_exp - 8'hc; // @[NFALU.scala 125:29]
  wire [35:0] _GEN_69 = {o_mant, 11'h0}; // @[NFALU.scala 127:31]
  wire [39:0] _temFrac_T_10 = {{4'd0}, _GEN_69}; // @[NFALU.scala 127:31]
  wire [7:0] _temExp_T_21 = o_exp - 8'hb; // @[NFALU.scala 128:29]
  wire [34:0] _GEN_70 = {o_mant, 10'h0}; // @[NFALU.scala 130:31]
  wire [39:0] _temFrac_T_11 = {{5'd0}, _GEN_70}; // @[NFALU.scala 130:31]
  wire [7:0] _temExp_T_23 = o_exp - 8'ha; // @[NFALU.scala 131:29]
  wire [33:0] _GEN_71 = {o_mant, 9'h0}; // @[NFALU.scala 133:31]
  wire [39:0] _temFrac_T_12 = {{6'd0}, _GEN_71}; // @[NFALU.scala 133:31]
  wire [7:0] _temExp_T_25 = o_exp - 8'h9; // @[NFALU.scala 134:29]
  wire [32:0] _GEN_72 = {o_mant, 8'h0}; // @[NFALU.scala 136:31]
  wire [39:0] _temFrac_T_13 = {{7'd0}, _GEN_72}; // @[NFALU.scala 136:31]
  wire [7:0] _temExp_T_27 = o_exp - 8'h8; // @[NFALU.scala 137:29]
  wire [31:0] _temFrac_T_14 = {o_mant, 7'h0}; // @[NFALU.scala 139:31]
  wire [7:0] _temExp_T_29 = o_exp - 8'h7; // @[NFALU.scala 140:29]
  wire [30:0] _GEN_73 = {o_mant, 6'h0}; // @[NFALU.scala 142:31]
  wire [31:0] _temFrac_T_15 = {{1'd0}, _GEN_73}; // @[NFALU.scala 142:31]
  wire [7:0] _temExp_T_31 = o_exp - 8'h6; // @[NFALU.scala 143:29]
  wire [29:0] _GEN_74 = {o_mant, 5'h0}; // @[NFALU.scala 145:31]
  wire [31:0] _temFrac_T_16 = {{2'd0}, _GEN_74}; // @[NFALU.scala 145:31]
  wire [7:0] _temExp_T_33 = o_exp - 8'h5; // @[NFALU.scala 146:29]
  wire [28:0] _GEN_75 = {o_mant, 4'h0}; // @[NFALU.scala 148:31]
  wire [31:0] _temFrac_T_17 = {{3'd0}, _GEN_75}; // @[NFALU.scala 148:31]
  wire [7:0] _temExp_T_35 = o_exp - 8'h4; // @[NFALU.scala 149:29]
  wire [27:0] _temFrac_T_18 = {o_mant, 3'h0}; // @[NFALU.scala 151:31]
  wire [7:0] _temExp_T_37 = o_exp - 8'h3; // @[NFALU.scala 152:29]
  wire [26:0] _GEN_76 = {o_mant, 2'h0}; // @[NFALU.scala 154:31]
  wire [27:0] _temFrac_T_19 = {{1'd0}, _GEN_76}; // @[NFALU.scala 154:31]
  wire [7:0] _temExp_T_39 = o_exp - 8'h2; // @[NFALU.scala 155:29]
  wire [25:0] _temFrac_T_20 = {o_mant, 1'h0}; // @[NFALU.scala 157:31]
  wire [7:0] _temExp_T_41 = o_exp - 8'h1; // @[NFALU.scala 158:29]
  wire [25:0] _GEN_16 = o_mant[23:22] == 2'h1 ? _temFrac_T_20 : 26'h0; // @[NFALU.scala 156:44 NFALU.scala 157:21 NFALU.scala 161:21]
  wire [7:0] _GEN_17 = o_mant[23:22] == 2'h1 ? _temExp_T_41 : 8'h0; // @[NFALU.scala 156:44 NFALU.scala 158:20 NFALU.scala 162:20]
  wire [27:0] _GEN_18 = o_mant[23:21] == 3'h1 ? _temFrac_T_19 : {{2'd0}, _GEN_16}; // @[NFALU.scala 153:45 NFALU.scala 154:21]
  wire [7:0] _GEN_19 = o_mant[23:21] == 3'h1 ? _temExp_T_39 : _GEN_17; // @[NFALU.scala 153:45 NFALU.scala 155:20]
  wire [27:0] _GEN_20 = o_mant[23:20] == 4'h1 ? _temFrac_T_18 : _GEN_18; // @[NFALU.scala 150:46 NFALU.scala 151:21]
  wire [7:0] _GEN_21 = o_mant[23:20] == 4'h1 ? _temExp_T_37 : _GEN_19; // @[NFALU.scala 150:46 NFALU.scala 152:20]
  wire [31:0] _GEN_22 = o_mant[23:19] == 5'h1 ? _temFrac_T_17 : {{4'd0}, _GEN_20}; // @[NFALU.scala 147:47 NFALU.scala 148:21]
  wire [7:0] _GEN_23 = o_mant[23:19] == 5'h1 ? _temExp_T_35 : _GEN_21; // @[NFALU.scala 147:47 NFALU.scala 149:20]
  wire [31:0] _GEN_24 = o_mant[23:18] == 6'h1 ? _temFrac_T_16 : _GEN_22; // @[NFALU.scala 144:48 NFALU.scala 145:21]
  wire [7:0] _GEN_25 = o_mant[23:18] == 6'h1 ? _temExp_T_33 : _GEN_23; // @[NFALU.scala 144:48 NFALU.scala 146:20]
  wire [31:0] _GEN_26 = o_mant[23:17] == 7'h1 ? _temFrac_T_15 : _GEN_24; // @[NFALU.scala 141:49 NFALU.scala 142:21]
  wire [7:0] _GEN_27 = o_mant[23:17] == 7'h1 ? _temExp_T_31 : _GEN_25; // @[NFALU.scala 141:49 NFALU.scala 143:20]
  wire [31:0] _GEN_28 = o_mant[23:16] == 8'h1 ? _temFrac_T_14 : _GEN_26; // @[NFALU.scala 138:50 NFALU.scala 139:21]
  wire [7:0] _GEN_29 = o_mant[23:16] == 8'h1 ? _temExp_T_29 : _GEN_27; // @[NFALU.scala 138:50 NFALU.scala 140:20]
  wire [39:0] _GEN_30 = o_mant[23:15] == 9'h1 ? _temFrac_T_13 : {{8'd0}, _GEN_28}; // @[NFALU.scala 135:51 NFALU.scala 136:21]
  wire [7:0] _GEN_31 = o_mant[23:15] == 9'h1 ? _temExp_T_27 : _GEN_29; // @[NFALU.scala 135:51 NFALU.scala 137:20]
  wire [39:0] _GEN_32 = o_mant[23:14] == 10'h1 ? _temFrac_T_12 : _GEN_30; // @[NFALU.scala 132:52 NFALU.scala 133:21]
  wire [7:0] _GEN_33 = o_mant[23:14] == 10'h1 ? _temExp_T_25 : _GEN_31; // @[NFALU.scala 132:52 NFALU.scala 134:20]
  wire [39:0] _GEN_34 = o_mant[23:13] == 11'h1 ? _temFrac_T_11 : _GEN_32; // @[NFALU.scala 129:53 NFALU.scala 130:21]
  wire [7:0] _GEN_35 = o_mant[23:13] == 11'h1 ? _temExp_T_23 : _GEN_33; // @[NFALU.scala 129:53 NFALU.scala 131:20]
  wire [39:0] _GEN_36 = o_mant[23:12] == 12'h1 ? _temFrac_T_10 : _GEN_34; // @[NFALU.scala 126:54 NFALU.scala 127:21]
  wire [7:0] _GEN_37 = o_mant[23:12] == 12'h1 ? _temExp_T_21 : _GEN_35; // @[NFALU.scala 126:54 NFALU.scala 128:20]
  wire [39:0] _GEN_38 = o_mant[23:11] == 13'h1 ? _temFrac_T_9 : _GEN_36; // @[NFALU.scala 123:55 NFALU.scala 124:21]
  wire [7:0] _GEN_39 = o_mant[23:11] == 13'h1 ? _temExp_T_19 : _GEN_37; // @[NFALU.scala 123:55 NFALU.scala 125:20]
  wire [39:0] _GEN_40 = o_mant[23:10] == 14'h1 ? _temFrac_T_8 : _GEN_38; // @[NFALU.scala 120:56 NFALU.scala 121:21]
  wire [7:0] _GEN_41 = o_mant[23:10] == 14'h1 ? _temExp_T_17 : _GEN_39; // @[NFALU.scala 120:56 NFALU.scala 122:20]
  wire [39:0] _GEN_42 = o_mant[23:9] == 15'h1 ? _temFrac_T_7 : _GEN_40; // @[NFALU.scala 117:56 NFALU.scala 118:21]
  wire [7:0] _GEN_43 = o_mant[23:9] == 15'h1 ? _temExp_T_15 : _GEN_41; // @[NFALU.scala 117:56 NFALU.scala 119:20]
  wire [39:0] _GEN_44 = o_mant[23:8] == 16'h1 ? _temFrac_T_6 : _GEN_42; // @[NFALU.scala 114:57 NFALU.scala 115:21]
  wire [7:0] _GEN_45 = o_mant[23:8] == 16'h1 ? _temExp_T_13 : _GEN_43; // @[NFALU.scala 114:57 NFALU.scala 116:20]
  wire [55:0] _GEN_46 = o_mant[23:7] == 17'h1 ? _temFrac_T_5 : {{16'd0}, _GEN_44}; // @[NFALU.scala 111:58 NFALU.scala 112:21]
  wire [7:0] _GEN_47 = o_mant[23:7] == 17'h1 ? _temExp_T_11 : _GEN_45; // @[NFALU.scala 111:58 NFALU.scala 113:20]
  wire [55:0] _GEN_48 = o_mant[23:6] == 18'h1 ? _temFrac_T_4 : _GEN_46; // @[NFALU.scala 108:59 NFALU.scala 109:21]
  wire [7:0] _GEN_49 = o_mant[23:6] == 18'h1 ? _temExp_T_9 : _GEN_47; // @[NFALU.scala 108:59 NFALU.scala 110:20]
  wire [55:0] _GEN_50 = o_mant[23:5] == 19'h1 ? _temFrac_T_3 : _GEN_48; // @[NFALU.scala 105:60 NFALU.scala 106:21]
  wire [7:0] _GEN_51 = o_mant[23:5] == 19'h1 ? _temExp_T_7 : _GEN_49; // @[NFALU.scala 105:60 NFALU.scala 107:20]
  wire [55:0] _GEN_52 = o_mant[23:4] == 20'h1 ? _temFrac_T_2 : _GEN_50; // @[NFALU.scala 102:61 NFALU.scala 103:21]
  wire [7:0] _GEN_53 = o_mant[23:4] == 20'h1 ? _temExp_T_5 : _GEN_51; // @[NFALU.scala 102:61 NFALU.scala 104:20]
  wire [55:0] _GEN_54 = o_mant[23:3] == 21'h1 ? _temFrac_T_1 : _GEN_52; // @[NFALU.scala 99:57 NFALU.scala 100:21]
  wire [7:0] _GEN_55 = o_mant[23:3] == 21'h1 ? _temExp_T_3 : _GEN_53; // @[NFALU.scala 99:57 NFALU.scala 101:20]
  wire [55:0] _GEN_56 = ~o_mant[23] & o_exp != 8'h0 ? _GEN_54 : {{31'd0}, o_mant}; // @[NFALU.scala 98:47 NFALU.scala 166:17]
  wire [7:0] _GEN_57 = ~o_mant[23] & o_exp != 8'h0 ? _GEN_55 : o_exp; // @[NFALU.scala 98:47 NFALU.scala 167:16]
  wire [55:0] _GEN_58 = o_mant[24] ? {{31'd0}, _temFrac_T} : _GEN_56; // @[NFALU.scala 94:27 NFALU.scala 95:17]
  wire [7:0] temExp = o_mant[24] ? _temExp_T_1 : _GEN_57; // @[NFALU.scala 94:27 NFALU.scala 96:16]
  wire [23:0] temFrac = _GEN_58[23:0]; // @[NFALU.scala 33:23]
  wire [22:0] io_result_lo = temFrac[22:0]; // @[NFALU.scala 169:41]
  wire [8:0] io_result_hi = {o_sign,temExp}; // @[Cat.scala 30:58]
  assign io_result = {io_result_hi,io_result_lo}; // @[Cat.scala 30:58]
endmodule
