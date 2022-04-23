// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


//======================

void VALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VALU::traceInit, &VALU::traceFull, &VALU::traceChg, this);
}
void VALU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VALU* t = (VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VALU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VALU* t = (VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VALU::traceInitThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VALU::traceFullThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VALU::traceInitThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+81,"clock", false,-1);
        vcdp->declBit(c+89,"reset", false,-1);
        vcdp->declBus(c+97,"io_input1", false,-1, 31,0);
        vcdp->declBus(c+105,"io_input2", false,-1, 31,0);
        vcdp->declBus(c+113,"io_opcode", false,-1, 6,0);
        vcdp->declBus(c+121,"io_aluCtl", false,-1, 3,0);
        vcdp->declBus(c+129,"io_f5", false,-1, 4,0);
        vcdp->declBit(c+137,"io_zero", false,-1);
        vcdp->declBus(c+145,"io_result", false,-1, 31,0);
        vcdp->declBit(c+81,"ALU clock", false,-1);
        vcdp->declBit(c+89,"ALU reset", false,-1);
        vcdp->declBus(c+97,"ALU io_input1", false,-1, 31,0);
        vcdp->declBus(c+105,"ALU io_input2", false,-1, 31,0);
        vcdp->declBus(c+113,"ALU io_opcode", false,-1, 6,0);
        vcdp->declBus(c+121,"ALU io_aluCtl", false,-1, 3,0);
        vcdp->declBus(c+129,"ALU io_f5", false,-1, 4,0);
        vcdp->declBit(c+137,"ALU io_zero", false,-1);
        vcdp->declBus(c+145,"ALU io_result", false,-1, 31,0);
        vcdp->declBus(c+97,"ALU fa_io_input1", false,-1, 31,0);
        vcdp->declBus(c+105,"ALU fa_io_input2", false,-1, 31,0);
        vcdp->declBus(c+129,"ALU fa_io_aluCtl", false,-1, 4,0);
        vcdp->declBus(c+113,"ALU fa_io_opcode", false,-1, 6,0);
        vcdp->declBus(c+153,"ALU fa_io_result", false,-1, 31,0);
        vcdp->declBus(c+97,"ALU fa io_input1", false,-1, 31,0);
        vcdp->declBus(c+105,"ALU fa io_input2", false,-1, 31,0);
        vcdp->declBus(c+129,"ALU fa io_aluCtl", false,-1, 4,0);
        vcdp->declBus(c+113,"ALU fa io_opcode", false,-1, 6,0);
        vcdp->declBus(c+153,"ALU fa io_result", false,-1, 31,0);
        vcdp->declBus(c+97,"ALU fa add_io_input1", false,-1, 31,0);
        vcdp->declBus(c+105,"ALU fa add_io_input2", false,-1, 31,0);
        vcdp->declBus(c+161,"ALU fa add_io_result", false,-1, 31,0);
        vcdp->declBus(c+97,"ALU fa mult_io_input1", false,-1, 31,0);
        vcdp->declBus(c+105,"ALU fa mult_io_input2", false,-1, 31,0);
        vcdp->declBus(c+169,"ALU fa mult_io_result", false,-1, 31,0);
        vcdp->declBus(c+97,"ALU fa add io_input1", false,-1, 31,0);
        vcdp->declBus(c+105,"ALU fa add io_input2", false,-1, 31,0);
        vcdp->declBus(c+161,"ALU fa add io_result", false,-1, 31,0);
        vcdp->declBit(c+177,"ALU fa add signBitIn1", false,-1);
        vcdp->declBit(c+185,"ALU fa add signBitIn2", false,-1);
        vcdp->declBus(c+193,"ALU fa add expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+201,"ALU fa add expBitIn2", false,-1, 7,0);
        vcdp->declBus(c+209,"ALU fa add fracBitIn1_lo", false,-1, 22,0);
        vcdp->declBus(c+217,"ALU fa add fracBitIn1", false,-1, 23,0);
        vcdp->declBus(c+225,"ALU fa add fracBitIn2_lo", false,-1, 22,0);
        vcdp->declBus(c+233,"ALU fa add fracBitIn2", false,-1, 23,0);
        vcdp->declBit(c+241,"ALU fa add andSign", false,-1);
        vcdp->declBus(c+249,"ALU fa add o_mant_lo", false,-1, 23,0);
        vcdp->declBus(c+257,"ALU fa add o_mant_lo_1", false,-1, 23,0);
        vcdp->declBus(c+265,"ALU fa add o_mant_lo_2", false,-1, 23,0);
        vcdp->declBus(c+1,"ALU fa add diff", false,-1, 7,0);
        vcdp->declBus(c+9,"ALU fa add tmp_mant", false,-1, 23,0);
        vcdp->declBus(c+17,"ALU fa add o_exp", false,-1, 7,0);
        vcdp->declBit(c+273,"ALU fa add o_sign", false,-1);
        vcdp->declBus(c+25,"ALU fa add o_mant", false,-1, 24,0);
        vcdp->declBus(c+33,"ALU fa add temExp", false,-1, 7,0);
        vcdp->declBus(c+41,"ALU fa add temFrac", false,-1, 23,0);
        vcdp->declBus(c+49,"ALU fa add io_result_lo", false,-1, 22,0);
        vcdp->declBus(c+281,"ALU fa add io_result_hi", false,-1, 8,0);
        vcdp->declBus(c+97,"ALU fa mult io_input1", false,-1, 31,0);
        vcdp->declBus(c+105,"ALU fa mult io_input2", false,-1, 31,0);
        vcdp->declBus(c+169,"ALU fa mult io_result", false,-1, 31,0);
        vcdp->declBit(c+177,"ALU fa mult signBitIn1", false,-1);
        vcdp->declBit(c+185,"ALU fa mult signBitIn2", false,-1);
        vcdp->declBus(c+193,"ALU fa mult expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+201,"ALU fa mult expBitIn2", false,-1, 7,0);
        vcdp->declBus(c+209,"ALU fa mult fracBitIn1_lo", false,-1, 22,0);
        vcdp->declBus(c+217,"ALU fa mult fracBitIn1", false,-1, 23,0);
        vcdp->declBus(c+225,"ALU fa mult fracBitIn2_lo", false,-1, 22,0);
        vcdp->declBus(c+233,"ALU fa mult fracBitIn2", false,-1, 23,0);
        vcdp->declBit(c+289,"ALU fa mult xorSign", false,-1);
        vcdp->declQuad(c+57,"ALU fa mult o_mant", false,-1, 47,0);
        vcdp->declBus(c+73,"ALU fa mult o_exp", false,-1, 7,0);
        vcdp->declQuad(c+297,"ALU fa mult temFrac", false,-1, 47,0);
        vcdp->declBus(c+313,"ALU fa mult tmptFrac", false,-1, 24,0);
        vcdp->declBus(c+321,"ALU fa mult io_result_lo", false,-1, 22,0);
        vcdp->declBit(c+329,"ALU fa mult o_sign", false,-1);
        vcdp->declBus(c+337,"ALU fa mult temExp", false,-1, 7,0);
    }
}

void VALU::traceFullThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->ALU__DOT__fa__DOT__add__DOT__diff),8);
        vcdp->fullBus(c+9,(vlTOPp->ALU__DOT__fa__DOT__add__DOT__tmp_mant),24);
        vcdp->fullBus(c+17,(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp),8);
        vcdp->fullBus(c+25,(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant),25);
        vcdp->fullBus(c+33,((0xffU & ((0x1000000U & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                       ? ((IData)(1U) 
                                          + (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp))
                                       : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_57)))),8);
        vcdp->fullBus(c+41,((0xffffffU & (IData)(((0x1000000U 
                                                   & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                                   ? (QData)((IData)(
                                                                     (0xffffffU 
                                                                      & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                         >> 1U))))
                                                   : 
                                                  (((~ 
                                                     (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                      >> 0x17U)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp)))
                                                    ? vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_54
                                                    : (QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant))))))),24);
        vcdp->fullBus(c+49,((0x7fffffU & (IData)(((0x1000000U 
                                                   & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                                   ? (QData)((IData)(
                                                                     (0xffffffU 
                                                                      & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                         >> 1U))))
                                                   : 
                                                  (((~ 
                                                     (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                      >> 0x17U)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp)))
                                                    ? vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_54
                                                    : (QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant))))))),23);
        vcdp->fullQuad(c+57,(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant),48);
        vcdp->fullBus(c+73,(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp),8);
        vcdp->fullBit(c+81,(vlTOPp->clock));
        vcdp->fullBit(c+89,(vlTOPp->reset));
        vcdp->fullBus(c+97,(vlTOPp->io_input1),32);
        vcdp->fullBus(c+105,(vlTOPp->io_input2),32);
        vcdp->fullBus(c+113,(vlTOPp->io_opcode),7);
        vcdp->fullBus(c+121,(vlTOPp->io_aluCtl),4);
        vcdp->fullBus(c+129,(vlTOPp->io_f5),5);
        vcdp->fullBit(c+137,(vlTOPp->io_zero));
        vcdp->fullBus(c+145,(vlTOPp->io_result),32);
        vcdp->fullBus(c+153,(((((0U == (IData)(vlTOPp->io_f5)) 
                                | (1U == (IData)(vlTOPp->io_f5))) 
                               & (0x53U == (IData)(vlTOPp->io_opcode)))
                               ? ((0x80000000U & ((
                                                   ((0xffU 
                                                     & (vlTOPp->io_input1 
                                                        >> 0x17U)) 
                                                    == 
                                                    (0xffU 
                                                     & (vlTOPp->io_input2 
                                                        >> 0x17U)))
                                                    ? 
                                                   (((1U 
                                                      & (vlTOPp->io_input1 
                                                         >> 0x1fU)) 
                                                     == 
                                                     (1U 
                                                      & (vlTOPp->io_input2 
                                                         >> 0x1fU)))
                                                     ? 
                                                    ((vlTOPp->io_input1 
                                                      & vlTOPp->io_input2) 
                                                     >> 0x1fU)
                                                     : 
                                                    (((0x800000U 
                                                       | (0x7fffffU 
                                                          & vlTOPp->io_input1)) 
                                                      > 
                                                      (0x800000U 
                                                       | (0x7fffffU 
                                                          & vlTOPp->io_input2)))
                                                      ? 
                                                     (vlTOPp->io_input1 
                                                      >> 0x1fU)
                                                      : 
                                                     (vlTOPp->io_input2 
                                                      >> 0x1fU)))
                                                    : 
                                                   (((0xffU 
                                                      & (vlTOPp->io_input1 
                                                         >> 0x17U)) 
                                                     > 
                                                     (0xffU 
                                                      & (vlTOPp->io_input2 
                                                         >> 0x17U)))
                                                     ? 
                                                    (vlTOPp->io_input1 
                                                     >> 0x1fU)
                                                     : 
                                                    (vlTOPp->io_input2 
                                                     >> 0x1fU))) 
                                                  << 0x1fU)) 
                                  | ((0x7f800000U & 
                                      (((0x1000000U 
                                         & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                         ? ((IData)(1U) 
                                            + (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp))
                                         : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_57)) 
                                       << 0x17U)) | 
                                     (0x7fffffU & (IData)(
                                                          ((0x1000000U 
                                                            & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                                            ? (QData)((IData)(
                                                                              (0xffffffU 
                                                                               & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                                >> 1U))))
                                                            : 
                                                           (((~ 
                                                              (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                               >> 0x17U)) 
                                                             & (0U 
                                                                != (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp)))
                                                             ? vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_54
                                                             : (QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant))))))))
                               : (((0U == vlTOPp->io_input1) 
                                   | (0U == vlTOPp->io_input2))
                                   ? 0U : vlTOPp->ALU__DOT__fa__DOT__mult__DOT___io_result_T))),32);
        vcdp->fullBus(c+161,(((0x80000000U & ((((0xffU 
                                                 & (vlTOPp->io_input1 
                                                    >> 0x17U)) 
                                                == 
                                                (0xffU 
                                                 & (vlTOPp->io_input2 
                                                    >> 0x17U)))
                                                ? (
                                                   ((1U 
                                                     & (vlTOPp->io_input1 
                                                        >> 0x1fU)) 
                                                    == 
                                                    (1U 
                                                     & (vlTOPp->io_input2 
                                                        >> 0x1fU)))
                                                    ? 
                                                   ((vlTOPp->io_input1 
                                                     & vlTOPp->io_input2) 
                                                    >> 0x1fU)
                                                    : 
                                                   (((0x800000U 
                                                      | (0x7fffffU 
                                                         & vlTOPp->io_input1)) 
                                                     > 
                                                     (0x800000U 
                                                      | (0x7fffffU 
                                                         & vlTOPp->io_input2)))
                                                     ? 
                                                    (vlTOPp->io_input1 
                                                     >> 0x1fU)
                                                     : 
                                                    (vlTOPp->io_input2 
                                                     >> 0x1fU)))
                                                : (
                                                   ((0xffU 
                                                     & (vlTOPp->io_input1 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->io_input2 
                                                        >> 0x17U)))
                                                    ? 
                                                   (vlTOPp->io_input1 
                                                    >> 0x1fU)
                                                    : 
                                                   (vlTOPp->io_input2 
                                                    >> 0x1fU))) 
                                              << 0x1fU)) 
                              | ((0x7f800000U & (((0x1000000U 
                                                   & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                                   ? 
                                                  ((IData)(1U) 
                                                   + (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp))
                                                   : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_57)) 
                                                 << 0x17U)) 
                                 | (0x7fffffU & (IData)(
                                                        ((0x1000000U 
                                                          & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                                          ? (QData)((IData)(
                                                                            (0xffffffU 
                                                                             & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                                >> 1U))))
                                                          : 
                                                         (((~ 
                                                            (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                             >> 0x17U)) 
                                                           & (0U 
                                                              != (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp)))
                                                           ? vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_54
                                                           : (QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant))))))))),32);
        vcdp->fullBus(c+169,((((0U == vlTOPp->io_input1) 
                               | (0U == vlTOPp->io_input2))
                               ? 0U : vlTOPp->ALU__DOT__fa__DOT__mult__DOT___io_result_T)),32);
        vcdp->fullBit(c+177,((1U & (vlTOPp->io_input1 
                                    >> 0x1fU))));
        vcdp->fullBit(c+185,((1U & (vlTOPp->io_input2 
                                    >> 0x1fU))));
        vcdp->fullBus(c+193,((0xffU & (vlTOPp->io_input1 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+201,((0xffU & (vlTOPp->io_input2 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+209,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->fullBus(c+217,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input1))),24);
        vcdp->fullBus(c+225,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->fullBus(c+233,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input2))),24);
        vcdp->fullBit(c+241,((1U & ((vlTOPp->io_input1 
                                     & vlTOPp->io_input2) 
                                    >> 0x1fU))));
        vcdp->fullBus(c+249,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input1)) 
                                           + (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input2))))),24);
        vcdp->fullBus(c+257,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input1)) 
                                           - (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input2))))),24);
        vcdp->fullBus(c+265,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input2)) 
                                           - (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input1))))),24);
        vcdp->fullBit(c+273,((1U & (((0xffU & (vlTOPp->io_input1 
                                               >> 0x17U)) 
                                     == (0xffU & (vlTOPp->io_input2 
                                                  >> 0x17U)))
                                     ? (((1U & (vlTOPp->io_input1 
                                                >> 0x1fU)) 
                                         == (1U & (vlTOPp->io_input2 
                                                   >> 0x1fU)))
                                         ? ((vlTOPp->io_input1 
                                             & vlTOPp->io_input2) 
                                            >> 0x1fU)
                                         : (((0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input1)) 
                                             > (0x800000U 
                                                | (0x7fffffU 
                                                   & vlTOPp->io_input2)))
                                             ? (vlTOPp->io_input1 
                                                >> 0x1fU)
                                             : (vlTOPp->io_input2 
                                                >> 0x1fU)))
                                     : (((0xffU & (vlTOPp->io_input1 
                                                   >> 0x17U)) 
                                         > (0xffU & 
                                            (vlTOPp->io_input2 
                                             >> 0x17U)))
                                         ? (vlTOPp->io_input1 
                                            >> 0x1fU)
                                         : (vlTOPp->io_input2 
                                            >> 0x1fU))))));
        vcdp->fullBus(c+281,(((0x100U & ((((0xffU & 
                                            (vlTOPp->io_input1 
                                             >> 0x17U)) 
                                           == (0xffU 
                                               & (vlTOPp->io_input2 
                                                  >> 0x17U)))
                                           ? (((1U 
                                                & (vlTOPp->io_input1 
                                                   >> 0x1fU)) 
                                               == (1U 
                                                   & (vlTOPp->io_input2 
                                                      >> 0x1fU)))
                                               ? ((vlTOPp->io_input1 
                                                   & vlTOPp->io_input2) 
                                                  >> 0x1fU)
                                               : ((
                                                   (0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input1)) 
                                                   > 
                                                   (0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input2)))
                                                   ? 
                                                  (vlTOPp->io_input1 
                                                   >> 0x1fU)
                                                   : 
                                                  (vlTOPp->io_input2 
                                                   >> 0x1fU)))
                                           : (((0xffU 
                                                & (vlTOPp->io_input1 
                                                   >> 0x17U)) 
                                               > (0xffU 
                                                  & (vlTOPp->io_input2 
                                                     >> 0x17U)))
                                               ? (vlTOPp->io_input1 
                                                  >> 0x1fU)
                                               : (vlTOPp->io_input2 
                                                  >> 0x1fU))) 
                                         << 8U)) | 
                              (0xffU & ((0x1000000U 
                                         & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                         ? ((IData)(1U) 
                                            + (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp))
                                         : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_57))))),9);
        vcdp->fullBit(c+289,((1U & ((vlTOPp->io_input1 
                                     ^ vlTOPp->io_input2) 
                                    >> 0x1fU))));
        vcdp->fullQuad(c+297,((((0U == vlTOPp->io_input1) 
                                | (0U == vlTOPp->io_input2))
                                ? VL_ULL(0) : (VL_ULL(0xffffffffffff) 
                                               & ((1U 
                                                   & (IData)(
                                                             (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                              >> 0x2fU)))
                                                   ? 
                                                  (VL_ULL(0x7fffffffffff) 
                                                   & (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                      >> 1U))
                                                   : 
                                                  (((~ (IData)(
                                                               (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                >> 0x2eU))) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp)))
                                                    ? 
                                                   ((1U 
                                                     == 
                                                     (0x3fU 
                                                      & (IData)(
                                                                (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                 >> 0x29U))))
                                                     ? 
                                                    (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                     << 5U)
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(
                                                                 (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                  >> 0x2aU))))
                                                      ? 
                                                     (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                      << 4U)
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(
                                                                  (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                   >> 0x2bU))))
                                                       ? 
                                                      (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                       << 3U)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (IData)(
                                                                   (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                    >> 0x2cU))))
                                                        ? 
                                                       (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                        << 2U)
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (IData)(
                                                                    (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                     >> 0x2dU))))
                                                         ? 
                                                        (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                         << 1U)
                                                         : VL_ULL(0))))))
                                                    : vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant))))),48);
        vcdp->fullBus(c+313,((((0U == vlTOPp->io_input1) 
                               | (0U == vlTOPp->io_input2))
                               ? 0U : (0xffffffU & (IData)(
                                                           ((((0U 
                                                               == vlTOPp->io_input1) 
                                                              | (0U 
                                                                 == vlTOPp->io_input2))
                                                              ? VL_ULL(0)
                                                              : 
                                                             ((1U 
                                                               & (IData)(
                                                                         (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                          >> 0x2fU)))
                                                               ? 
                                                              (VL_ULL(0x7fffffffffff) 
                                                               & (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                  >> 1U))
                                                               : 
                                                              (((~ (IData)(
                                                                           (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                            >> 0x2eU))) 
                                                                & (0U 
                                                                   != (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp)))
                                                                ? 
                                                               ((1U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & (IData)(
                                                                            (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                             >> 0x29U))))
                                                                 ? 
                                                                (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                 << 5U)
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(
                                                                             (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                              >> 0x2aU))))
                                                                  ? 
                                                                 (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                  << 4U)
                                                                  : 
                                                                 ((1U 
                                                                   == 
                                                                   (0xfU 
                                                                    & (IData)(
                                                                              (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                               >> 0x2bU))))
                                                                   ? 
                                                                  (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                   << 3U)
                                                                   : 
                                                                  ((1U 
                                                                    == 
                                                                    (7U 
                                                                     & (IData)(
                                                                               (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                                >> 0x2cU))))
                                                                    ? 
                                                                   (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                    << 2U)
                                                                    : 
                                                                   ((1U 
                                                                     == 
                                                                     (3U 
                                                                      & (IData)(
                                                                                (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                                >> 0x2dU))))
                                                                     ? 
                                                                    (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                     << 1U)
                                                                     : VL_ULL(0))))))
                                                                : vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant))) 
                                                            >> 0x17U))))),25);
        vcdp->fullBus(c+321,((((0U == vlTOPp->io_input1) 
                               | (0U == vlTOPp->io_input2))
                               ? 0U : (0x7fffffU & (IData)(
                                                           ((((0U 
                                                               == vlTOPp->io_input1) 
                                                              | (0U 
                                                                 == vlTOPp->io_input2))
                                                              ? VL_ULL(0)
                                                              : 
                                                             ((1U 
                                                               & (IData)(
                                                                         (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                          >> 0x2fU)))
                                                               ? 
                                                              (VL_ULL(0x7fffffffffff) 
                                                               & (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                  >> 1U))
                                                               : 
                                                              (((~ (IData)(
                                                                           (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                            >> 0x2eU))) 
                                                                & (0U 
                                                                   != (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp)))
                                                                ? 
                                                               ((1U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & (IData)(
                                                                            (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                             >> 0x29U))))
                                                                 ? 
                                                                (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                 << 5U)
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(
                                                                             (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                              >> 0x2aU))))
                                                                  ? 
                                                                 (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                  << 4U)
                                                                  : 
                                                                 ((1U 
                                                                   == 
                                                                   (0xfU 
                                                                    & (IData)(
                                                                              (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                               >> 0x2bU))))
                                                                   ? 
                                                                  (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                   << 3U)
                                                                   : 
                                                                  ((1U 
                                                                    == 
                                                                    (7U 
                                                                     & (IData)(
                                                                               (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                                >> 0x2cU))))
                                                                    ? 
                                                                   (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                    << 2U)
                                                                    : 
                                                                   ((1U 
                                                                     == 
                                                                     (3U 
                                                                      & (IData)(
                                                                                (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                                >> 0x2dU))))
                                                                     ? 
                                                                    (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                     << 1U)
                                                                     : VL_ULL(0))))))
                                                                : vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant))) 
                                                            >> 0x17U))))),23);
        vcdp->fullBit(c+329,((1U & ((~ ((0U == vlTOPp->io_input1) 
                                        | (0U == vlTOPp->io_input2))) 
                                    & ((vlTOPp->io_input1 
                                        ^ vlTOPp->io_input2) 
                                       >> 0x1fU)))));
        vcdp->fullBus(c+337,((((0U == vlTOPp->io_input1) 
                               | (0U == vlTOPp->io_input2))
                               ? 0U : (0xffU & ((1U 
                                                 & (IData)(
                                                           (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                            >> 0x2fU)))
                                                 ? 
                                                ((IData)(1U) 
                                                 + (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp))
                                                 : 
                                                (((~ (IData)(
                                                             (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                              >> 0x2eU))) 
                                                  & (0U 
                                                     != (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp)))
                                                  ? 
                                                 ((1U 
                                                   == 
                                                   (0x3fU 
                                                    & (IData)(
                                                              (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                               >> 0x29U))))
                                                   ? 
                                                  ((IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp) 
                                                   - (IData)(5U))
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(
                                                               (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                >> 0x2aU))))
                                                    ? 
                                                   ((IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp) 
                                                    - (IData)(4U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(
                                                                (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                 >> 0x2bU))))
                                                     ? 
                                                    ((IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp) 
                                                     - (IData)(3U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (IData)(
                                                                 (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                  >> 0x2cU))))
                                                      ? 
                                                     ((IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp) 
                                                      - (IData)(2U))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (3U 
                                                        & (IData)(
                                                                  (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                                   >> 0x2dU))))
                                                       ? 
                                                      ((IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp) 
                                                       - (IData)(1U))
                                                       : 0U)))))
                                                  : (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp)))))),8);
    }
}
