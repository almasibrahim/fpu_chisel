// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFALU__Syms.h"


//======================

void VFALU::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VFALU* t = (VFALU*)userthis;
    VFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VFALU::traceChgThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VFALU::traceChgThis__2(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->FALU__DOT__add__DOT__diff),8);
        vcdp->chgBus(c+9,(vlTOPp->FALU__DOT__add__DOT__tmp_mant),24);
        vcdp->chgBus(c+17,(vlTOPp->FALU__DOT__add__DOT__o_exp),8);
        vcdp->chgBus(c+25,(vlTOPp->FALU__DOT__add__DOT__o_mant),25);
        vcdp->chgBus(c+33,((0xffU & ((0x1000000U & vlTOPp->FALU__DOT__add__DOT__o_mant)
                                      ? ((IData)(1U) 
                                         + (IData)(vlTOPp->FALU__DOT__add__DOT__o_exp))
                                      : (IData)(vlTOPp->FALU__DOT__add__DOT___GEN_57)))),8);
        vcdp->chgBus(c+41,((0xffffffU & (IData)(((0x1000000U 
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
        vcdp->chgBus(c+49,((0x7fffffU & (IData)(((0x1000000U 
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
        vcdp->chgQuad(c+57,(vlTOPp->FALU__DOT__mult__DOT__o_mant),48);
        vcdp->chgBus(c+73,(vlTOPp->FALU__DOT__mult__DOT__o_exp),8);
    }
}

void VFALU::traceChgThis__3(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+81,(vlTOPp->clock));
        vcdp->chgBit(c+89,(vlTOPp->reset));
        vcdp->chgBus(c+97,(vlTOPp->io_input1),32);
        vcdp->chgBus(c+105,(vlTOPp->io_input2),32);
        vcdp->chgBus(c+113,(vlTOPp->io_aluCtl),5);
        vcdp->chgBus(c+121,(vlTOPp->io_opcode),7);
        vcdp->chgBus(c+129,(vlTOPp->io_result),32);
        vcdp->chgBus(c+137,(((0x80000000U & ((((0xffU 
                                                & (vlTOPp->io_input1 
                                                   >> 0x17U)) 
                                               == (0xffU 
                                                   & (vlTOPp->io_input2 
                                                      >> 0x17U)))
                                               ? ((
                                                   (1U 
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
                                               : ((
                                                   (0xffU 
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
        vcdp->chgBus(c+145,((((0U == vlTOPp->io_input1) 
                              | (0U == vlTOPp->io_input2))
                              ? 0U : vlTOPp->FALU__DOT__mult__DOT___io_result_T)),32);
        vcdp->chgBit(c+153,((1U & (vlTOPp->io_input1 
                                   >> 0x1fU))));
        vcdp->chgBit(c+161,((1U & (vlTOPp->io_input2 
                                   >> 0x1fU))));
        vcdp->chgBus(c+169,((0xffU & (vlTOPp->io_input1 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+177,((0xffU & (vlTOPp->io_input2 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+185,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->chgBus(c+193,((0x800000U | (0x7fffffU 
                                          & vlTOPp->io_input1))),24);
        vcdp->chgBus(c+201,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->chgBus(c+209,((0x800000U | (0x7fffffU 
                                          & vlTOPp->io_input2))),24);
        vcdp->chgBit(c+217,((1U & ((vlTOPp->io_input1 
                                    & vlTOPp->io_input2) 
                                   >> 0x1fU))));
        vcdp->chgBus(c+225,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input1)) 
                                          + (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input2))))),24);
        vcdp->chgBus(c+233,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input1)) 
                                          - (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input2))))),24);
        vcdp->chgBus(c+241,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input2)) 
                                          - (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input1))))),24);
        vcdp->chgBit(c+249,((1U & (((0xffU & (vlTOPp->io_input1 
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
        vcdp->chgBus(c+257,(((0x100U & ((((0xffU & 
                                           (vlTOPp->io_input1 
                                            >> 0x17U)) 
                                          == (0xffU 
                                              & (vlTOPp->io_input2 
                                                 >> 0x17U)))
                                          ? (((1U & 
                                               (vlTOPp->io_input1 
                                                >> 0x1fU)) 
                                              == (1U 
                                                  & (vlTOPp->io_input2 
                                                     >> 0x1fU)))
                                              ? ((vlTOPp->io_input1 
                                                  & vlTOPp->io_input2) 
                                                 >> 0x1fU)
                                              : (((0x800000U 
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
                                        << 8U)) | (0xffU 
                                                   & ((0x1000000U 
                                                       & vlTOPp->FALU__DOT__add__DOT__o_mant)
                                                       ? 
                                                      ((IData)(1U) 
                                                       + (IData)(vlTOPp->FALU__DOT__add__DOT__o_exp))
                                                       : (IData)(vlTOPp->FALU__DOT__add__DOT___GEN_57))))),9);
        vcdp->chgBit(c+265,((1U & ((vlTOPp->io_input1 
                                    ^ vlTOPp->io_input2) 
                                   >> 0x1fU))));
        vcdp->chgQuad(c+273,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBus(c+289,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBus(c+297,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBit(c+305,((1U & ((~ ((0U == vlTOPp->io_input1) 
                                       | (0U == vlTOPp->io_input2))) 
                                   & ((vlTOPp->io_input1 
                                       ^ vlTOPp->io_input2) 
                                      >> 0x1fU)))));
        vcdp->chgBus(c+313,((((0U == vlTOPp->io_input1) 
                              | (0U == vlTOPp->io_input2))
                              ? 0U : (0xffU & ((1U 
                                                & (IData)(
                                                          (vlTOPp->FALU__DOT__mult__DOT__o_mant 
                                                           >> 0x2fU)))
                                                ? ((IData)(1U) 
                                                   + (IData)(vlTOPp->FALU__DOT__mult__DOT__o_exp))
                                                : (
                                                   ((~ (IData)(
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
    }
}
