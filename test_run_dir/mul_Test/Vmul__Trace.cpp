// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmul__Syms.h"


//======================

void Vmul::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vmul* t = (Vmul*)userthis;
    Vmul__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vmul::traceChgThis(Vmul__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vmul::traceChgThis__2(Vmul__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgQuad(c+1,(vlTOPp->mul__DOT__o_mant),48);
        vcdp->chgBus(c+17,(vlTOPp->mul__DOT__o_exp),8);
    }
}

void Vmul::traceChgThis__3(Vmul__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+25,(vlTOPp->clock));
        vcdp->chgBit(c+33,(vlTOPp->reset));
        vcdp->chgBus(c+41,(vlTOPp->io_input1),32);
        vcdp->chgBus(c+49,(vlTOPp->io_input2),32);
        vcdp->chgBus(c+57,(vlTOPp->io_result),32);
        vcdp->chgBit(c+65,((1U & (vlTOPp->io_input1 
                                  >> 0x1fU))));
        vcdp->chgBit(c+73,((1U & (vlTOPp->io_input2 
                                  >> 0x1fU))));
        vcdp->chgBus(c+81,((0xffU & (vlTOPp->io_input1 
                                     >> 0x17U))),8);
        vcdp->chgBus(c+89,((0xffU & (vlTOPp->io_input2 
                                     >> 0x17U))),8);
        vcdp->chgBus(c+97,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->chgBus(c+105,((0x800000U | (0x7fffffU 
                                          & vlTOPp->io_input1))),24);
        vcdp->chgBus(c+113,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->chgBus(c+121,((0x800000U | (0x7fffffU 
                                          & vlTOPp->io_input2))),24);
        vcdp->chgBit(c+129,((1U & ((vlTOPp->io_input1 
                                    ^ vlTOPp->io_input2) 
                                   >> 0x1fU))));
        vcdp->chgQuad(c+137,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBus(c+153,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBus(c+161,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBit(c+169,((1U & ((~ ((0U == vlTOPp->io_input1) 
                                       | (0U == vlTOPp->io_input2))) 
                                   & ((vlTOPp->io_input1 
                                       ^ vlTOPp->io_input2) 
                                      >> 0x1fU)))));
        vcdp->chgBus(c+177,((((0U == vlTOPp->io_input1) 
                              | (0U == vlTOPp->io_input2))
                              ? 0U : (0xffU & ((1U 
                                                & (IData)(
                                                          (vlTOPp->mul__DOT__o_mant 
                                                           >> 0x2fU)))
                                                ? ((IData)(1U) 
                                                   + (IData)(vlTOPp->mul__DOT__o_exp))
                                                : (
                                                   ((~ (IData)(
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
