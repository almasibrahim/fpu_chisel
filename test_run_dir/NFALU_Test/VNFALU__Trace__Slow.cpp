// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VNFALU__Syms.h"


//======================

void VNFALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VNFALU::traceInit, &VNFALU::traceFull, &VNFALU::traceChg, this);
}
void VNFALU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VNFALU* t = (VNFALU*)userthis;
    VNFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VNFALU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VNFALU* t = (VNFALU*)userthis;
    VNFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VNFALU::traceInitThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VNFALU::traceFullThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VNFALU::traceInitThis__1(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+57,"clock", false,-1);
        vcdp->declBit(c+65,"reset", false,-1);
        vcdp->declBus(c+73,"io_input1", false,-1, 31,0);
        vcdp->declBus(c+81,"io_input2", false,-1, 31,0);
        vcdp->declBus(c+89,"io_result", false,-1, 31,0);
        vcdp->declBit(c+57,"NFALU clock", false,-1);
        vcdp->declBit(c+65,"NFALU reset", false,-1);
        vcdp->declBus(c+73,"NFALU io_input1", false,-1, 31,0);
        vcdp->declBus(c+81,"NFALU io_input2", false,-1, 31,0);
        vcdp->declBus(c+89,"NFALU io_result", false,-1, 31,0);
        vcdp->declBit(c+97,"NFALU signBitIn1", false,-1);
        vcdp->declBit(c+105,"NFALU signBitIn2", false,-1);
        vcdp->declBus(c+113,"NFALU expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+121,"NFALU expBitIn2", false,-1, 7,0);
        vcdp->declBus(c+129,"NFALU fracBitIn1_lo", false,-1, 22,0);
        vcdp->declBus(c+137,"NFALU fracBitIn1", false,-1, 23,0);
        vcdp->declBus(c+145,"NFALU fracBitIn2_lo", false,-1, 22,0);
        vcdp->declBus(c+153,"NFALU fracBitIn2", false,-1, 23,0);
        vcdp->declBit(c+161,"NFALU andSign", false,-1);
        vcdp->declBus(c+169,"NFALU o_mant_lo", false,-1, 23,0);
        vcdp->declBus(c+177,"NFALU o_mant_lo_1", false,-1, 23,0);
        vcdp->declBus(c+185,"NFALU o_mant_lo_2", false,-1, 23,0);
        vcdp->declBus(c+1,"NFALU diff", false,-1, 7,0);
        vcdp->declBus(c+9,"NFALU tmp_mant", false,-1, 23,0);
        vcdp->declBus(c+17,"NFALU o_exp", false,-1, 7,0);
        vcdp->declBit(c+193,"NFALU o_sign", false,-1);
        vcdp->declBus(c+25,"NFALU o_mant", false,-1, 24,0);
        vcdp->declBus(c+33,"NFALU temExp", false,-1, 7,0);
        vcdp->declBus(c+41,"NFALU temFrac", false,-1, 23,0);
        vcdp->declBus(c+49,"NFALU io_result_lo", false,-1, 22,0);
        vcdp->declBus(c+201,"NFALU io_result_hi", false,-1, 8,0);
    }
}

void VNFALU::traceFullThis__1(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->NFALU__DOT__diff),8);
        vcdp->fullBus(c+9,(vlTOPp->NFALU__DOT__tmp_mant),24);
        vcdp->fullBus(c+17,(vlTOPp->NFALU__DOT__o_exp),8);
        vcdp->fullBus(c+25,(vlTOPp->NFALU__DOT__o_mant),25);
        vcdp->fullBus(c+33,((0xffU & ((0x1000000U & vlTOPp->NFALU__DOT__o_mant)
                                       ? ((IData)(1U) 
                                          + (IData)(vlTOPp->NFALU__DOT__o_exp))
                                       : (IData)(vlTOPp->NFALU__DOT___GEN_57)))),8);
        vcdp->fullBus(c+41,((0xffffffU & (IData)(((0x1000000U 
                                                   & vlTOPp->NFALU__DOT__o_mant)
                                                   ? (QData)((IData)(
                                                                     (0xffffffU 
                                                                      & (vlTOPp->NFALU__DOT__o_mant 
                                                                         >> 1U))))
                                                   : 
                                                  (((~ 
                                                     (vlTOPp->NFALU__DOT__o_mant 
                                                      >> 0x17U)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->NFALU__DOT__o_exp)))
                                                    ? vlTOPp->NFALU__DOT___GEN_54
                                                    : (QData)((IData)(vlTOPp->NFALU__DOT__o_mant))))))),24);
        vcdp->fullBus(c+49,((0x7fffffU & (IData)(((0x1000000U 
                                                   & vlTOPp->NFALU__DOT__o_mant)
                                                   ? (QData)((IData)(
                                                                     (0xffffffU 
                                                                      & (vlTOPp->NFALU__DOT__o_mant 
                                                                         >> 1U))))
                                                   : 
                                                  (((~ 
                                                     (vlTOPp->NFALU__DOT__o_mant 
                                                      >> 0x17U)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->NFALU__DOT__o_exp)))
                                                    ? vlTOPp->NFALU__DOT___GEN_54
                                                    : (QData)((IData)(vlTOPp->NFALU__DOT__o_mant))))))),23);
        vcdp->fullBit(c+57,(vlTOPp->clock));
        vcdp->fullBit(c+65,(vlTOPp->reset));
        vcdp->fullBus(c+73,(vlTOPp->io_input1),32);
        vcdp->fullBus(c+81,(vlTOPp->io_input2),32);
        vcdp->fullBus(c+89,(vlTOPp->io_result),32);
        vcdp->fullBit(c+97,((1U & (vlTOPp->io_input1 
                                   >> 0x1fU))));
        vcdp->fullBit(c+105,((1U & (vlTOPp->io_input2 
                                    >> 0x1fU))));
        vcdp->fullBus(c+113,((0xffU & (vlTOPp->io_input1 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+121,((0xffU & (vlTOPp->io_input2 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+129,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->fullBus(c+137,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input1))),24);
        vcdp->fullBus(c+145,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->fullBus(c+153,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input2))),24);
        vcdp->fullBit(c+161,((1U & ((vlTOPp->io_input1 
                                     & vlTOPp->io_input2) 
                                    >> 0x1fU))));
        vcdp->fullBus(c+169,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input1)) 
                                           + (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input2))))),24);
        vcdp->fullBus(c+177,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input1)) 
                                           - (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input2))))),24);
        vcdp->fullBus(c+185,((0xffffffU & ((0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->io_input2)) 
                                           - (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->io_input1))))),24);
        vcdp->fullBit(c+193,((1U & (((0xffU & (vlTOPp->io_input1 
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
        vcdp->fullBus(c+201,(((0x100U & ((((0xffU & 
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
                                         & vlTOPp->NFALU__DOT__o_mant)
                                         ? ((IData)(1U) 
                                            + (IData)(vlTOPp->NFALU__DOT__o_exp))
                                         : (IData)(vlTOPp->NFALU__DOT___GEN_57))))),9);
    }
}
