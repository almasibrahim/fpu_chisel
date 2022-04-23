// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmul__Syms.h"


//======================

void Vmul::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vmul::traceInit, &Vmul::traceFull, &Vmul::traceChg, this);
}
void Vmul::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vmul* t = (Vmul*)userthis;
    Vmul__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vmul::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vmul* t = (Vmul*)userthis;
    Vmul__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vmul::traceInitThis(Vmul__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vmul::traceFullThis(Vmul__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vmul::traceInitThis__1(Vmul__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+25,"clock", false,-1);
        vcdp->declBit(c+33,"reset", false,-1);
        vcdp->declBus(c+41,"io_input1", false,-1, 31,0);
        vcdp->declBus(c+49,"io_input2", false,-1, 31,0);
        vcdp->declBus(c+57,"io_result", false,-1, 31,0);
        vcdp->declBit(c+25,"mul clock", false,-1);
        vcdp->declBit(c+33,"mul reset", false,-1);
        vcdp->declBus(c+41,"mul io_input1", false,-1, 31,0);
        vcdp->declBus(c+49,"mul io_input2", false,-1, 31,0);
        vcdp->declBus(c+57,"mul io_result", false,-1, 31,0);
        vcdp->declBit(c+65,"mul signBitIn1", false,-1);
        vcdp->declBit(c+73,"mul signBitIn2", false,-1);
        vcdp->declBus(c+81,"mul expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+89,"mul expBitIn2", false,-1, 7,0);
        vcdp->declBus(c+97,"mul fracBitIn1_lo", false,-1, 22,0);
        vcdp->declBus(c+105,"mul fracBitIn1", false,-1, 23,0);
        vcdp->declBus(c+113,"mul fracBitIn2_lo", false,-1, 22,0);
        vcdp->declBus(c+121,"mul fracBitIn2", false,-1, 23,0);
        vcdp->declBit(c+129,"mul xorSign", false,-1);
        vcdp->declQuad(c+1,"mul o_mant", false,-1, 47,0);
        vcdp->declBus(c+17,"mul o_exp", false,-1, 7,0);
        vcdp->declQuad(c+137,"mul temFrac", false,-1, 47,0);
        vcdp->declBus(c+153,"mul tmptFrac", false,-1, 24,0);
        vcdp->declBus(c+161,"mul io_result_lo", false,-1, 22,0);
        vcdp->declBit(c+169,"mul o_sign", false,-1);
        vcdp->declBus(c+177,"mul temExp", false,-1, 7,0);
    }
}

void Vmul::traceFullThis__1(Vmul__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullQuad(c+1,(vlTOPp->mul__DOT__o_mant),48);
        vcdp->fullBus(c+17,(vlTOPp->mul__DOT__o_exp),8);
        vcdp->fullBit(c+25,(vlTOPp->clock));
        vcdp->fullBit(c+33,(vlTOPp->reset));
        vcdp->fullBus(c+41,(vlTOPp->io_input1),32);
        vcdp->fullBus(c+49,(vlTOPp->io_input2),32);
        vcdp->fullBus(c+57,(vlTOPp->io_result),32);
        vcdp->fullBit(c+65,((1U & (vlTOPp->io_input1 
                                   >> 0x1fU))));
        vcdp->fullBit(c+73,((1U & (vlTOPp->io_input2 
                                   >> 0x1fU))));
        vcdp->fullBus(c+81,((0xffU & (vlTOPp->io_input1 
                                      >> 0x17U))),8);
        vcdp->fullBus(c+89,((0xffU & (vlTOPp->io_input2 
                                      >> 0x17U))),8);
        vcdp->fullBus(c+97,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->fullBus(c+105,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input1))),24);
        vcdp->fullBus(c+113,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->fullBus(c+121,((0x800000U | (0x7fffffU 
                                           & vlTOPp->io_input2))),24);
        vcdp->fullBit(c+129,((1U & ((vlTOPp->io_input1 
                                     ^ vlTOPp->io_input2) 
                                    >> 0x1fU))));
        vcdp->fullQuad(c+137,((((0U == vlTOPp->io_input1) 
                                | (0U == vlTOPp->io_input2))
                                ? VL_ULL(0) : (VL_ULL(0xffffffffffff) 
                                               & ((1U 
                                                   & (IData)(
                                                             (vlTOPp->mul__DOT__o_mant 
                                                              >> 0x2fU)))
                                                   ? 
                                                  (VL_ULL(0x7fffffffffff) 
                                                   & (vlTOPp->mul__DOT__o_mant 
                                                      >> 1U))
                                                   : 
                                                  (((~ (IData)(
                                                               (vlTOPp->mul__DOT__o_mant 
                                                                >> 0x2eU))) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->mul__DOT__o_exp)))
                                                    ? 
                                                   ((1U 
                                                     == 
                                                     (0x3fU 
                                                      & (IData)(
                                                                (vlTOPp->mul__DOT__o_mant 
                                                                 >> 0x29U))))
                                                     ? 
                                                    (vlTOPp->mul__DOT__o_mant 
                                                     << 5U)
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(
                                                                 (vlTOPp->mul__DOT__o_mant 
                                                                  >> 0x2aU))))
                                                      ? 
                                                     (vlTOPp->mul__DOT__o_mant 
                                                      << 4U)
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(
                                                                  (vlTOPp->mul__DOT__o_mant 
                                                                   >> 0x2bU))))
                                                       ? 
                                                      (vlTOPp->mul__DOT__o_mant 
                                                       << 3U)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (IData)(
                                                                   (vlTOPp->mul__DOT__o_mant 
                                                                    >> 0x2cU))))
                                                        ? 
                                                       (vlTOPp->mul__DOT__o_mant 
                                                        << 2U)
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (IData)(
                                                                    (vlTOPp->mul__DOT__o_mant 
                                                                     >> 0x2dU))))
                                                         ? 
                                                        (vlTOPp->mul__DOT__o_mant 
                                                         << 1U)
                                                         : VL_ULL(0))))))
                                                    : vlTOPp->mul__DOT__o_mant))))),48);
        vcdp->fullBus(c+153,((((0U == vlTOPp->io_input1) 
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
                                                                         (vlTOPp->mul__DOT__o_mant 
                                                                          >> 0x2fU)))
                                                               ? 
                                                              (VL_ULL(0x7fffffffffff) 
                                                               & (vlTOPp->mul__DOT__o_mant 
                                                                  >> 1U))
                                                               : 
                                                              (((~ (IData)(
                                                                           (vlTOPp->mul__DOT__o_mant 
                                                                            >> 0x2eU))) 
                                                                & (0U 
                                                                   != (IData)(vlTOPp->mul__DOT__o_exp)))
                                                                ? 
                                                               ((1U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & (IData)(
                                                                            (vlTOPp->mul__DOT__o_mant 
                                                                             >> 0x29U))))
                                                                 ? 
                                                                (vlTOPp->mul__DOT__o_mant 
                                                                 << 5U)
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(
                                                                             (vlTOPp->mul__DOT__o_mant 
                                                                              >> 0x2aU))))
                                                                  ? 
                                                                 (vlTOPp->mul__DOT__o_mant 
                                                                  << 4U)
                                                                  : 
                                                                 ((1U 
                                                                   == 
                                                                   (0xfU 
                                                                    & (IData)(
                                                                              (vlTOPp->mul__DOT__o_mant 
                                                                               >> 0x2bU))))
                                                                   ? 
                                                                  (vlTOPp->mul__DOT__o_mant 
                                                                   << 3U)
                                                                   : 
                                                                  ((1U 
                                                                    == 
                                                                    (7U 
                                                                     & (IData)(
                                                                               (vlTOPp->mul__DOT__o_mant 
                                                                                >> 0x2cU))))
                                                                    ? 
                                                                   (vlTOPp->mul__DOT__o_mant 
                                                                    << 2U)
                                                                    : 
                                                                   ((1U 
                                                                     == 
                                                                     (3U 
                                                                      & (IData)(
                                                                                (vlTOPp->mul__DOT__o_mant 
                                                                                >> 0x2dU))))
                                                                     ? 
                                                                    (vlTOPp->mul__DOT__o_mant 
                                                                     << 1U)
                                                                     : VL_ULL(0))))))
                                                                : vlTOPp->mul__DOT__o_mant))) 
                                                            >> 0x17U))))),25);
        vcdp->fullBus(c+161,((((0U == vlTOPp->io_input1) 
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
                                                                         (vlTOPp->mul__DOT__o_mant 
                                                                          >> 0x2fU)))
                                                               ? 
                                                              (VL_ULL(0x7fffffffffff) 
                                                               & (vlTOPp->mul__DOT__o_mant 
                                                                  >> 1U))
                                                               : 
                                                              (((~ (IData)(
                                                                           (vlTOPp->mul__DOT__o_mant 
                                                                            >> 0x2eU))) 
                                                                & (0U 
                                                                   != (IData)(vlTOPp->mul__DOT__o_exp)))
                                                                ? 
                                                               ((1U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & (IData)(
                                                                            (vlTOPp->mul__DOT__o_mant 
                                                                             >> 0x29U))))
                                                                 ? 
                                                                (vlTOPp->mul__DOT__o_mant 
                                                                 << 5U)
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(
                                                                             (vlTOPp->mul__DOT__o_mant 
                                                                              >> 0x2aU))))
                                                                  ? 
                                                                 (vlTOPp->mul__DOT__o_mant 
                                                                  << 4U)
                                                                  : 
                                                                 ((1U 
                                                                   == 
                                                                   (0xfU 
                                                                    & (IData)(
                                                                              (vlTOPp->mul__DOT__o_mant 
                                                                               >> 0x2bU))))
                                                                   ? 
                                                                  (vlTOPp->mul__DOT__o_mant 
                                                                   << 3U)
                                                                   : 
                                                                  ((1U 
                                                                    == 
                                                                    (7U 
                                                                     & (IData)(
                                                                               (vlTOPp->mul__DOT__o_mant 
                                                                                >> 0x2cU))))
                                                                    ? 
                                                                   (vlTOPp->mul__DOT__o_mant 
                                                                    << 2U)
                                                                    : 
                                                                   ((1U 
                                                                     == 
                                                                     (3U 
                                                                      & (IData)(
                                                                                (vlTOPp->mul__DOT__o_mant 
                                                                                >> 0x2dU))))
                                                                     ? 
                                                                    (vlTOPp->mul__DOT__o_mant 
                                                                     << 1U)
                                                                     : VL_ULL(0))))))
                                                                : vlTOPp->mul__DOT__o_mant))) 
                                                            >> 0x17U))))),23);
        vcdp->fullBit(c+169,((1U & ((~ ((0U == vlTOPp->io_input1) 
                                        | (0U == vlTOPp->io_input2))) 
                                    & ((vlTOPp->io_input1 
                                        ^ vlTOPp->io_input2) 
                                       >> 0x1fU)))));
        vcdp->fullBus(c+177,((((0U == vlTOPp->io_input1) 
                               | (0U == vlTOPp->io_input2))
                               ? 0U : (0xffU & ((1U 
                                                 & (IData)(
                                                           (vlTOPp->mul__DOT__o_mant 
                                                            >> 0x2fU)))
                                                 ? 
                                                ((IData)(1U) 
                                                 + (IData)(vlTOPp->mul__DOT__o_exp))
                                                 : 
                                                (((~ (IData)(
                                                             (vlTOPp->mul__DOT__o_mant 
                                                              >> 0x2eU))) 
                                                  & (0U 
                                                     != (IData)(vlTOPp->mul__DOT__o_exp)))
                                                  ? 
                                                 ((1U 
                                                   == 
                                                   (0x3fU 
                                                    & (IData)(
                                                              (vlTOPp->mul__DOT__o_mant 
                                                               >> 0x29U))))
                                                   ? 
                                                  ((IData)(vlTOPp->mul__DOT__o_exp) 
                                                   - (IData)(5U))
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(
                                                               (vlTOPp->mul__DOT__o_mant 
                                                                >> 0x2aU))))
                                                    ? 
                                                   ((IData)(vlTOPp->mul__DOT__o_exp) 
                                                    - (IData)(4U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(
                                                                (vlTOPp->mul__DOT__o_mant 
                                                                 >> 0x2bU))))
                                                     ? 
                                                    ((IData)(vlTOPp->mul__DOT__o_exp) 
                                                     - (IData)(3U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (IData)(
                                                                 (vlTOPp->mul__DOT__o_mant 
                                                                  >> 0x2cU))))
                                                      ? 
                                                     ((IData)(vlTOPp->mul__DOT__o_exp) 
                                                      - (IData)(2U))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (3U 
                                                        & (IData)(
                                                                  (vlTOPp->mul__DOT__o_mant 
                                                                   >> 0x2dU))))
                                                       ? 
                                                      ((IData)(vlTOPp->mul__DOT__o_exp) 
                                                       - (IData)(1U))
                                                       : 0U)))))
                                                  : (IData)(vlTOPp->mul__DOT__o_exp)))))),8);
    }
}
