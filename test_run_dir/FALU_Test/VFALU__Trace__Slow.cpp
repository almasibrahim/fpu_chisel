// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFALU__Syms.h"


//======================

void VFALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VFALU::traceInit, &VFALU::traceFull, &VFALU::traceChg, this);
}
void VFALU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VFALU* t = (VFALU*)userthis;
    VFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VFALU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VFALU* t = (VFALU*)userthis;
    VFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VFALU::traceInitThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VFALU::traceFullThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VFALU::traceInitThis__1(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+137,"clock", false,-1);
        vcdp->declBit(c+145,"reset", false,-1);
        vcdp->declBus(c+153,"io_input1", false,-1, 31,0);
        vcdp->declBus(c+161,"io_input2", false,-1, 31,0);
        vcdp->declBus(c+169,"io_aluCtl", false,-1, 4,0);
        vcdp->declBus(c+177,"io_opcode", false,-1, 6,0);
        vcdp->declBus(c+185,"io_result", false,-1, 31,0);
        vcdp->declBit(c+137,"FALU clock", false,-1);
        vcdp->declBit(c+145,"FALU reset", false,-1);
        vcdp->declBus(c+153,"FALU io_input1", false,-1, 31,0);
        vcdp->declBus(c+161,"FALU io_input2", false,-1, 31,0);
        vcdp->declBus(c+169,"FALU io_aluCtl", false,-1, 4,0);
        vcdp->declBus(c+177,"FALU io_opcode", false,-1, 6,0);
        vcdp->declBus(c+185,"FALU io_result", false,-1, 31,0);
        vcdp->declBus(c+153,"FALU add_io_input1", false,-1, 31,0);
        vcdp->declBus(c+161,"FALU add_io_input2", false,-1, 31,0);
        vcdp->declBus(c+193,"FALU add_io_result", false,-1, 31,0);
        vcdp->declBus(c+153,"FALU add_1_io_input1", false,-1, 31,0);
        vcdp->declBus(c+201,"FALU add_1_io_input2", false,-1, 31,0);
        vcdp->declBus(c+209,"FALU add_1_io_result", false,-1, 31,0);
        vcdp->declBus(c+153,"FALU mult_io_input1", false,-1, 31,0);
        vcdp->declBus(c+161,"FALU mult_io_input2", false,-1, 31,0);
        vcdp->declBus(c+217,"FALU mult_io_result", false,-1, 31,0);
        vcdp->declBus(c+225,"FALU add_io_input2_lo", false,-1, 30,0);
        vcdp->declBus(c+153,"FALU add io_input1", false,-1, 31,0);
        vcdp->declBus(c+161,"FALU add io_input2", false,-1, 31,0);
        vcdp->declBus(c+193,"FALU add io_result", false,-1, 31,0);
        vcdp->declBit(c+233,"FALU add signBitIn1", false,-1);
        vcdp->declBit(c+241,"FALU add signBitIn2", false,-1);
        vcdp->declBus(c+249,"FALU add expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+257,"FALU add expBitIn2", false,-1, 7,0);
        vcdp->declBus(c+265,"FALU add fracBitIn1_lo", false,-1, 22,0);
        vcdp->declBus(c+273,"FALU add fracBitIn1", false,-1, 23,0);
        vcdp->declBus(c+281,"FALU add fracBitIn2_lo", false,-1, 22,0);
        vcdp->declBus(c+289,"FALU add fracBitIn2", false,-1, 23,0);
        vcdp->declBit(c+297,"FALU add andSign", false,-1);
        vcdp->declBus(c+305,"FALU add o_mant_lo", false,-1, 23,0);
        vcdp->declBus(c+313,"FALU add o_mant_lo_1", false,-1, 23,0);
        vcdp->declBus(c+321,"FALU add o_mant_lo_2", false,-1, 23,0);
        vcdp->declBus(c+1,"FALU add diff", false,-1, 7,0);
        vcdp->declBus(c+9,"FALU add tmp_mant", false,-1, 23,0);
        vcdp->declBus(c+17,"FALU add o_exp", false,-1, 7,0);
        vcdp->declBit(c+329,"FALU add o_sign", false,-1);
        vcdp->declBus(c+25,"FALU add o_mant", false,-1, 24,0);
        vcdp->declBus(c+33,"FALU add temExp", false,-1, 7,0);
        vcdp->declBus(c+41,"FALU add temFrac", false,-1, 23,0);
        vcdp->declBus(c+49,"FALU add io_result_lo", false,-1, 22,0);
        vcdp->declBus(c+337,"FALU add io_result_hi", false,-1, 8,0);
        vcdp->declBus(c+153,"FALU add_1 io_input1", false,-1, 31,0);
        vcdp->declBus(c+201,"FALU add_1 io_input2", false,-1, 31,0);
        vcdp->declBus(c+209,"FALU add_1 io_result", false,-1, 31,0);
        vcdp->declBit(c+233,"FALU add_1 signBitIn1", false,-1);
        vcdp->declBit(c+465,"FALU add_1 signBitIn2", false,-1);
        vcdp->declBus(c+249,"FALU add_1 expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+345,"FALU add_1 expBitIn2", false,-1, 7,0);
        vcdp->declBus(c+265,"FALU add_1 fracBitIn1_lo", false,-1, 22,0);
        vcdp->declBus(c+273,"FALU add_1 fracBitIn1", false,-1, 23,0);
        vcdp->declBus(c+353,"FALU add_1 fracBitIn2_lo", false,-1, 22,0);
        vcdp->declBus(c+361,"FALU add_1 fracBitIn2", false,-1, 23,0);
        vcdp->declBit(c+233,"FALU add_1 andSign", false,-1);
        vcdp->declBus(c+369,"FALU add_1 o_mant_lo", false,-1, 23,0);
        vcdp->declBus(c+377,"FALU add_1 o_mant_lo_1", false,-1, 23,0);
        vcdp->declBus(c+385,"FALU add_1 o_mant_lo_2", false,-1, 23,0);
        vcdp->declBus(c+57,"FALU add_1 diff", false,-1, 7,0);
        vcdp->declBus(c+65,"FALU add_1 tmp_mant", false,-1, 23,0);
        vcdp->declBus(c+73,"FALU add_1 o_exp", false,-1, 7,0);
        vcdp->declBit(c+393,"FALU add_1 o_sign", false,-1);
        vcdp->declBus(c+81,"FALU add_1 o_mant", false,-1, 24,0);
        vcdp->declBus(c+89,"FALU add_1 temExp", false,-1, 7,0);
        vcdp->declBus(c+97,"FALU add_1 temFrac", false,-1, 23,0);
        vcdp->declBus(c+105,"FALU add_1 io_result_lo", false,-1, 22,0);
        vcdp->declBus(c+401,"FALU add_1 io_result_hi", false,-1, 8,0);
        vcdp->declBus(c+153,"FALU mult io_input1", false,-1, 31,0);
        vcdp->declBus(c+161,"FALU mult io_input2", false,-1, 31,0);
        vcdp->declBus(c+217,"FALU mult io_result", false,-1, 31,0);
        vcdp->declBit(c+233,"FALU mult signBitIn1", false,-1);
        vcdp->declBit(c+241,"FALU mult signBitIn2", false,-1);
        vcdp->declBus(c+249,"FALU mult expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+257,"FALU mult expBitIn2", false,-1, 7,0);
        vcdp->declBus(c+265,"FALU mult fracBitIn1_lo", false,-1, 22,0);
        vcdp->declBus(c+273,"FALU mult fracBitIn1", false,-1, 23,0);
        vcdp->declBus(c+281,"FALU mult fracBitIn2_lo", false,-1, 22,0);
        vcdp->declBus(c+289,"FALU mult fracBitIn2", false,-1, 23,0);
        vcdp->declBit(c+409,"FALU mult xorSign", false,-1);
        vcdp->declQuad(c+113,"FALU mult o_mant", false,-1, 47,0);
        vcdp->declBus(c+129,"FALU mult o_exp", false,-1, 7,0);
        vcdp->declQuad(c+417,"FALU mult temFrac", false,-1, 47,0);
        vcdp->declBus(c+433,"FALU mult tmptFrac", false,-1, 24,0);
        vcdp->declBus(c+441,"FALU mult io_result_lo", false,-1, 22,0);
        vcdp->declBit(c+449,"FALU mult o_sign", false,-1);
        vcdp->declBus(c+457,"FALU mult temExp", false,-1, 7,0);
    }
}

void VFALU::traceFullThis__1(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->FALU__DOT__add__DOT__diff),8);
        vcdp->fullBus(c+9,(vlTOPp->FALU__DOT__add__DOT__tmp_mant),24);
        vcdp->fullBus(c+17,(vlTOPp->FALU__DOT__add__DOT__o_exp),8);
        vcdp->fullBus(c+25,(vlTOPp->FALU__DOT__add__DOT__o_mant),25);
        vcdp->fullBus(c+33,((0xffU & ((0x1000000U & vlTOPp->FALU__DOT__add__DOT__o_mant)
                                       ? ((IData)(1U) 
                                          + (IData)(vlTOPp->FALU__DOT__add__DOT__o_exp))
                                       : (IData)(vlTOPp->FALU__DOT__add__DOT___GEN_57)))),8);
        vcdp->fullBus(c+41,((0xffffffU & (IData)(((0x1000000U 
                                                   & vlTOPp->FALU__DOT__add__DOT__o_mant)
                                                   ? (QData)((IData)(
                                                                     (0xffffffU 
                                                                      & (vlTOPp->FALU__DOT__add__DOT__o_mant 
                                                                         >> 1U))))
                                                   : 
                                                  (((~ 
                                                     (vlTOPp->FALU__DOT__add__DOT__o_mant 
                                                      >> 0x17U)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->FALU__DOT__add__DOT__o_exp)))
                                                    ? vlTOPp->FALU__DOT__add__DOT___GEN_54
                                                    : (QData)((IData)(vlTOPp->FALU__DOT__add__DOT__o_mant))))))),24);
        vcdp->fullBus(c+49,((0x7fffffU & (IData)(((0x1000000U 
                                                   & vlTOPp->FALU__DOT__add__DOT__o_mant)
                                                   ? (QData)((IData)(
                                                                     (0xffffffU 
                                                                      & (vlTOPp->FALU__DOT__add__DOT__o_mant 
                                                                         >> 1U))))
                                                   : 
                                                  (((~ 
                                                     (vlTOPp->FALU__DOT__add__DOT__o_mant 
                                                      >> 0x17U)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->FALU__DOT__add__DOT__o_exp)))
                                                    ? vlTOPp->FALU__DOT__add__DOT___GEN_54
                                                    : (QData)((IData)(vlTOPp->FALU__DOT__add__DOT__o_mant))))))),23);
        vcdp->fullBus(c+57,(vlTOPp->FALU__DOT__add_1__DOT__diff),8);
        vcdp->fullBus(c+65,(vlTOPp->FALU__DOT__add_1__DOT__tmp_mant),24);
        vcdp->fullBus(c+73,(vlTOPp->FALU__DOT__add_1__DOT__o_exp),8);
        vcdp->fullBus(c+81,(vlTOPp->FALU__DOT__add_1__DOT__o_mant),25);
        vcdp->fullBus(c+89,((0xffU & ((0x1000000U & vlTOPp->FALU__DOT__add_1__DOT__o_mant)
                                       ? ((IData)(1U) 
                                          + (IData)(vlTOPp->FALU__DOT__add_1__DOT__o_exp))
                                       : (IData)(vlTOPp->FALU__DOT__add_1__DOT___GEN_57)))),8);
        vcdp->fullBus(c+97,((0xffffffU & (IData)(((0x1000000U 
                                                   & vlTOPp->FALU__DOT__add_1__DOT__o_mant)
                                                   ? (QData)((IData)(
                                                                     (0xffffffU 
                                                                      & (vlTOPp->FALU__DOT__add_1__DOT__o_mant 
                                                                         >> 1U))))
                                                   : 
                                                  (((~ 
                                                     (vlTOPp->FALU__DOT__add_1__DOT__o_mant 
                                                      >> 0x17U)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->FALU__DOT__add_1__DOT__o_exp)))
                                                    ? vlTOPp->FALU__DOT__add_1__DOT___GEN_54
                                                    : (QData)((IData)(vlTOPp->FALU__DOT__add_1__DOT__o_mant))))))),24);
        vcdp->fullBus(c+105,((0x7fffffU & (IData)((
                                                   (0x1000000U 
                                                    & vlTOPp->FALU__DOT__add_1__DOT__o_mant)
                                                    ? (QData)((IData)(
                                                                      (0xffffffU 
                                                                       & (vlTOPp->FALU__DOT__add_1__DOT__o_mant 
                                                                          >> 1U))))
                                                    : 
                                                   (((~ 
                                                      (vlTOPp->FALU__DOT__add_1__DOT__o_mant 
                                                       >> 0x17U)) 
                                                     & (0U 
                                                        != (IData)(vlTOPp->FALU__DOT__add_1__DOT__o_exp)))
                                                     ? vlTOPp->FALU__DOT__add_1__DOT___GEN_54
                                                     : (QData)((IData)(vlTOPp->FALU__DOT__add_1__DOT__o_mant))))))),23);
        vcdp->fullQuad(c+113,(vlTOPp->FALU__DOT__mult__DOT__o_mant),48);
        vcdp->fullBus(c+129,(vlTOPp->FALU__DOT__mult__DOT__o_exp),8);
        vcdp->fullBit(c+137,(vlTOPp->clock));
        vcdp->fullBit(c+145,(vlTOPp->reset));
        vcdp->fullBus(c+153,(vlTOPp->io_input1),32);
        vcdp->fullBus(c+161,(vlTOPp->io_input2),32);
        vcdp->fullBus(c+169,(vlTOPp->io_aluCtl),5);
        vcdp->fullBus(c+177,(vlTOPp->io_opcode),7);
        vcdp->fullBus(c+185,(vlTOPp->io_result),32);
        vcdp->fullBus(c+193,(((0x80000000U & ((((0xffU 
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
                                                   & vlTOPp->FALU__DOT__add__DOT__o_mant)
                                                   ? 
                                                  ((IData)(1U) 
                                                   + (IData)(vlTOPp->FALU__DOT__add__DOT__o_exp))
                                                   : (IData)(vlTOPp->FALU__DOT__add__DOT___GEN_57)) 
                                                 << 0x17U)) 
                                 | (0x7fffffU & (IData)(
                                                        ((0x1000000U 
                                                          & vlTOPp->FALU__DOT__add__DOT__o_mant)
                                                          ? (QData)((IData)(
                                                                            (0xffffffU 
                                                                             & (vlTOPp->FALU__DOT__add__DOT__o_mant 
                                                                                >> 1U))))
                                                          : 
                                                         (((~ 
                                                            (vlTOPp->FALU__DOT__add__DOT__o_mant 
                                                             >> 0x17U)) 
                                                           & (0U 
                                                              != (IData)(vlTOPp->FALU__DOT__add__DOT__o_exp)))
                                                           ? vlTOPp->FALU__DOT__add__DOT___GEN_54
                                                           : (QData)((IData)(vlTOPp->FALU__DOT__add__DOT__o_mant))))))))),32);
        vcdp->fullBus(c+201,((0x80000000U | (0x7fffffffU 
                                             & vlTOPp->io_input2))),32);
        vcdp->fullBus(c+209,(((0x80000000U & ((((0xffU 
                                                 & (vlTOPp->io_input1 
                                                    >> 0x17U)) 
                                                == 
                                                (0xffU 
                                                 & (vlTOPp->io_input2 
                                                    >> 0x17U)))
                                                ? (
                                                   (0x80000000U 
                                                    & vlTOPp->io_input1)
                                                    ? 
                                                   (vlTOPp->io_input1 
                                                    >> 0x1fU)
                                                    : 
                                                   (((0x800000U 
                                                      | (0x7fffffU 
                                                         & vlTOPp->io_input1)) 
                                                     <= 
                                                     (0x800000U 
                                                      | (0x7fffffU 
                                                         & vlTOPp->io_input2))) 
                                                    | (vlTOPp->io_input1 
                                                       >> 0x1fU)))
                                                : (
                                                   ((0xffU 
                                                     & (vlTOPp->io_input1 
                                                        >> 0x17U)) 
                                                    <= 
                                                    (0xffU 
                                                     & (vlTOPp->io_input2 
                                                        >> 0x17U))) 
                                                   | (vlTOPp->io_input1 
                                                      >> 0x1fU))) 
                                              << 0x1fU)) 
                              | ((0x7f800000U & (((0x1000000U 
                                                   & vlTOPp->FALU__DOT__add_1__DOT__o_mant)
                                                   ? 
                                                  ((IData)(1U) 
                                                   + (IData)(vlTOPp->FALU__DOT__add_1__DOT__o_exp))
                                                   : (IData)(vlTOPp->FALU__DOT__add_1__DOT___GEN_57)) 
                                                 << 0x17U)) 
                                 | (0x7fffffU & (IData)(
                                                        ((0x1000000U 
                                                          & vlTOPp->FALU__DOT__add_1__DOT__o_mant)
                                                          ? (QData)((IData)(
                                                                            (0xffffffU 
                                                                             & (vlTOPp->FALU__DOT__add_1__DOT__o_mant 
                                                                                >> 1U))))
                                                          : 
                                                         (((~ 
                                                            (vlTOPp->FALU__DOT__add_1__DOT__o_mant 
                                                             >> 0x17U)) 
                                                           & (0U 
                                                              != (IData)(vlTOPp->FALU__DOT__add_1__DOT__o_exp)))
                                                           ? vlTOPp->FALU__DOT__add_1__DOT___GEN_54
                                                           : (QData)((IData)(vlTOPp->FALU__DOT__add_1__DOT__o_mant))))))))),32);
        vcdp->fullBus(c+217,((((0U == vlTOPp->io_input1) 
                               | (0U == vlTOPp->io_input2))
                               ? 0U : vlTOPp->FALU__DOT__mult__DOT___io_result_T)),32);
        vcdp->fullBus(c+225,((0x7fffffffU & vlTOPp->io_input2)),31);
        vcdp->fullBit(c+233,((1U & (vlTOPp->io_input1 
                                    >> 0x1fU))));
        vcdp->fullBit(c+241,((1U & (vlTOPp->io_input2 
                                    >> 0x1fU))));
        vcdp->fullBus(c+249,((0xffU & (vlTOPp->io_input1 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+257,((0xffU & (vlTOPp->io_input2 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+265,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->fullBus(c+273,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input1))),24);
        vcdp->fullBus(c+281,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->fullBus(c+289,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input2))),24);
        vcdp->fullBit(c+297,((1U & ((vlTOPp->io_input1 
                                     & vlTOPp->io_input2) 
                                    >> 0x1fU))));
        vcdp->fullBus(c+305,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input1)) 
                                           + (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input2))))),24);
        vcdp->fullBus(c+313,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input1)) 
                                           - (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input2))))),24);
        vcdp->fullBus(c+321,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input2)) 
                                           - (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input1))))),24);
        vcdp->fullBit(c+329,((1U & (((0xffU & (vlTOPp->io_input1 
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
        vcdp->fullBus(c+337,(((0x100U & ((((0xffU & 
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
                                         & vlTOPp->FALU__DOT__add__DOT__o_mant)
                                         ? ((IData)(1U) 
                                            + (IData)(vlTOPp->FALU__DOT__add__DOT__o_exp))
                                         : (IData)(vlTOPp->FALU__DOT__add__DOT___GEN_57))))),9);
        vcdp->fullBus(c+345,((0xffU & (vlTOPp->io_input2 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+353,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->fullBus(c+361,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input2))),24);
        vcdp->fullBus(c+369,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input1)) 
                                           + (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input2))))),24);
        vcdp->fullBus(c+377,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input1)) 
                                           - (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input2))))),24);
        vcdp->fullBus(c+385,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input2)) 
                                           - (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input1))))),24);
        vcdp->fullBit(c+393,((1U & (((0xffU & (vlTOPp->io_input1 
                                               >> 0x17U)) 
                                     == (0xffU & (vlTOPp->io_input2 
                                                  >> 0x17U)))
                                     ? ((0x80000000U 
                                         & vlTOPp->io_input1)
                                         ? (vlTOPp->io_input1 
                                            >> 0x1fU)
                                         : (((0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input1)) 
                                             <= (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->io_input2))) 
                                            | (vlTOPp->io_input1 
                                               >> 0x1fU)))
                                     : (((0xffU & (vlTOPp->io_input1 
                                                   >> 0x17U)) 
                                         <= (0xffU 
                                             & (vlTOPp->io_input2 
                                                >> 0x17U))) 
                                        | (vlTOPp->io_input1 
                                           >> 0x1fU))))));
        vcdp->fullBus(c+401,(((0x100U & ((((0xffU & 
                                            (vlTOPp->io_input1 
                                             >> 0x17U)) 
                                           == (0xffU 
                                               & (vlTOPp->io_input2 
                                                  >> 0x17U)))
                                           ? ((0x80000000U 
                                               & vlTOPp->io_input1)
                                               ? (vlTOPp->io_input1 
                                                  >> 0x1fU)
                                               : ((
                                                   (0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input1)) 
                                                   <= 
                                                   (0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input2))) 
                                                  | (vlTOPp->io_input1 
                                                     >> 0x1fU)))
                                           : (((0xffU 
                                                & (vlTOPp->io_input1 
                                                   >> 0x17U)) 
                                               <= (0xffU 
                                                   & (vlTOPp->io_input2 
                                                      >> 0x17U))) 
                                              | (vlTOPp->io_input1 
                                                 >> 0x1fU))) 
                                         << 8U)) | 
                              (0xffU & ((0x1000000U 
                                         & vlTOPp->FALU__DOT__add_1__DOT__o_mant)
                                         ? ((IData)(1U) 
                                            + (IData)(vlTOPp->FALU__DOT__add_1__DOT__o_exp))
                                         : (IData)(vlTOPp->FALU__DOT__add_1__DOT___GEN_57))))),9);
        vcdp->fullBit(c+409,((1U & ((vlTOPp->io_input1 
                                     ^ vlTOPp->io_input2) 
                                    >> 0x1fU))));
        vcdp->fullQuad(c+417,((((0U == vlTOPp->io_input1) 
                                | (0U == vlTOPp->io_input2))
                                ? VL_ULL(0) : (VL_ULL(0xffffffffffff) 
                                               & ((1U 
                                                   & (IData)(
                                                             (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                              >> 0x2fU)))
                                                   ? 
                                                  (VL_ULL(0x7fffffffffff) 
                                                   & (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                      >> 1U))
                                                   : 
                                                  (((~ (IData)(
                                                               (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                >> 0x2eU))) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp)))
                                                    ? 
                                                   ((1U 
                                                     == 
                                                     (0x3fU 
                                                      & (IData)(
                                                                (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                 >> 0x29U))))
                                                     ? 
                                                    (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                     << 5U)
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(
                                                                 (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                  >> 0x2aU))))
                                                      ? 
                                                     (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                      << 4U)
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(
                                                                  (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                   >> 0x2bU))))
                                                       ? 
                                                      (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                       << 3U)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (IData)(
                                                                   (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                    >> 0x2cU))))
                                                        ? 
                                                       (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                        << 2U)
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (IData)(
                                                                    (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                     >> 0x2dU))))
                                                         ? 
                                                        (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                         << 1U)
                                                         : VL_ULL(0))))))
                                                    : vlTOPp->FALU__DOT__mult__DOT__o_mant))))),48);
        vcdp->fullBus(c+433,((((0U == vlTOPp->io_input1) 
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
                                                                         (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                          >> 0x2fU)))
                                                               ? 
                                                              (VL_ULL(0x7fffffffffff) 
                                                               & (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                  >> 1U))
                                                               : 
                                                              (((~ (IData)(
                                                                           (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                            >> 0x2eU))) 
                                                                & (0U 
                                                                   != (IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp)))
                                                                ? 
                                                               ((1U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & (IData)(
                                                                            (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                             >> 0x29U))))
                                                                 ? 
                                                                (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                 << 5U)
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(
                                                                             (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                              >> 0x2aU))))
                                                                  ? 
                                                                 (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                  << 4U)
                                                                  : 
                                                                 ((1U 
                                                                   == 
                                                                   (0xfU 
                                                                    & (IData)(
                                                                              (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                               >> 0x2bU))))
                                                                   ? 
                                                                  (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                   << 3U)
                                                                   : 
                                                                  ((1U 
                                                                    == 
                                                                    (7U 
                                                                     & (IData)(
                                                                               (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                                >> 0x2cU))))
                                                                    ? 
                                                                   (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                    << 2U)
                                                                    : 
                                                                   ((1U 
                                                                     == 
                                                                     (3U 
                                                                      & (IData)(
                                                                                (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                                >> 0x2dU))))
                                                                     ? 
                                                                    (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                     << 1U)
                                                                     : VL_ULL(0))))))
                                                                : vlTOPp->FALU__DOT__mult__DOT__o_mant))) 
                                                            >> 0x17U))))),25);
        vcdp->fullBus(c+441,((((0U == vlTOPp->io_input1) 
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
                                                                         (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                          >> 0x2fU)))
                                                               ? 
                                                              (VL_ULL(0x7fffffffffff) 
                                                               & (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                  >> 1U))
                                                               : 
                                                              (((~ (IData)(
                                                                           (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                            >> 0x2eU))) 
                                                                & (0U 
                                                                   != (IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp)))
                                                                ? 
                                                               ((1U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & (IData)(
                                                                            (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                             >> 0x29U))))
                                                                 ? 
                                                                (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                 << 5U)
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(
                                                                             (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                              >> 0x2aU))))
                                                                  ? 
                                                                 (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                  << 4U)
                                                                  : 
                                                                 ((1U 
                                                                   == 
                                                                   (0xfU 
                                                                    & (IData)(
                                                                              (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                               >> 0x2bU))))
                                                                   ? 
                                                                  (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                   << 3U)
                                                                   : 
                                                                  ((1U 
                                                                    == 
                                                                    (7U 
                                                                     & (IData)(
                                                                               (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                                >> 0x2cU))))
                                                                    ? 
                                                                   (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                    << 2U)
                                                                    : 
                                                                   ((1U 
                                                                     == 
                                                                     (3U 
                                                                      & (IData)(
                                                                                (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                                >> 0x2dU))))
                                                                     ? 
                                                                    (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                     << 1U)
                                                                     : VL_ULL(0))))))
                                                                : vlTOPp->FALU__DOT__mult__DOT__o_mant))) 
                                                            >> 0x17U))))),23);
        vcdp->fullBit(c+449,((1U & ((~ ((0U == vlTOPp->io_input1) 
                                        | (0U == vlTOPp->io_input2))) 
                                    & ((vlTOPp->io_input1 
                                        ^ vlTOPp->io_input2) 
                                       >> 0x1fU)))));
        vcdp->fullBus(c+457,((((0U == vlTOPp->io_input1) 
                               | (0U == vlTOPp->io_input2))
                               ? 0U : (0xffU & ((1U 
                                                 & (IData)(
                                                           (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                            >> 0x2fU)))
                                                 ? 
                                                ((IData)(1U) 
                                                 + (IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp))
                                                 : 
                                                (((~ (IData)(
                                                             (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                              >> 0x2eU))) 
                                                  & (0U 
                                                     != (IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp)))
                                                  ? 
                                                 ((1U 
                                                   == 
                                                   (0x3fU 
                                                    & (IData)(
                                                              (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                               >> 0x29U))))
                                                   ? 
                                                  ((IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp) 
                                                   - (IData)(5U))
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(
                                                               (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                >> 0x2aU))))
                                                    ? 
                                                   ((IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp) 
                                                    - (IData)(4U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(
                                                                (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                 >> 0x2bU))))
                                                     ? 
                                                    ((IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp) 
                                                     - (IData)(3U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (IData)(
                                                                 (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                  >> 0x2cU))))
                                                      ? 
                                                     ((IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp) 
                                                      - (IData)(2U))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (3U 
                                                        & (IData)(
                                                                  (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                                   >> 0x2dU))))
                                                       ? 
                                                      ((IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp) 
                                                       - (IData)(1U))
                                                       : 0U)))))
                                                  : (IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp)))))),8);
        vcdp->fullBit(c+465,(1U));
    }
}
