// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


//======================

void VALU::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VALU* t = (VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VALU::traceChgThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VALU::traceChgThis__2(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->ALU__DOT__fa__DOT__add__DOT__diff),8);
        vcdp->chgBus(c+9,(vlTOPp->ALU__DOT__fa__DOT__add__DOT__tmp_mant),24);
        vcdp->chgBus(c+17,(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp),8);
        vcdp->chgBus(c+25,(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant),25);
        vcdp->chgBus(c+33,((0xffU & ((0x1000000U & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                      ? ((IData)(1U) 
                                         + (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp))
                                      : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_57)))),8);
        vcdp->chgBus(c+41,((0xffffffU & (IData)(((0x1000000U 
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
        vcdp->chgBus(c+49,((0x7fffffU & (IData)(((0x1000000U 
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
        vcdp->chgQuad(c+57,(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant),48);
        vcdp->chgBus(c+73,(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp),8);
    }
}

void VALU::traceChgThis__3(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+81,(vlTOPp->clock));
        vcdp->chgBit(c+89,(vlTOPp->reset));
        vcdp->chgBus(c+97,(vlTOPp->io_input1),32);
        vcdp->chgBus(c+105,(vlTOPp->io_input2),32);
        vcdp->chgBus(c+113,(vlTOPp->io_opcode),7);
        vcdp->chgBus(c+121,(vlTOPp->io_aluCtl),4);
        vcdp->chgBus(c+129,(vlTOPp->io_f5),5);
        vcdp->chgBit(c+137,(vlTOPp->io_zero));
        vcdp->chgBus(c+145,(vlTOPp->io_result),32);
        vcdp->chgBus(c+153,(((((0U == (IData)(vlTOPp->io_f5)) 
                               | (1U == (IData)(vlTOPp->io_f5))) 
                              & (0x53U == (IData)(vlTOPp->io_opcode)))
                              ? ((0x80000000U & (((
                                                   (0xffU 
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
        vcdp->chgBus(c+161,(((0x80000000U & ((((0xffU 
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
        vcdp->chgBus(c+169,((((0U == vlTOPp->io_input1) 
                              | (0U == vlTOPp->io_input2))
                              ? 0U : vlTOPp->ALU__DOT__fa__DOT__mult__DOT___io_result_T)),32);
        vcdp->chgBit(c+177,((1U & (vlTOPp->io_input1 
                                   >> 0x1fU))));
        vcdp->chgBit(c+185,((1U & (vlTOPp->io_input2 
                                   >> 0x1fU))));
        vcdp->chgBus(c+193,((0xffU & (vlTOPp->io_input1 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+201,((0xffU & (vlTOPp->io_input2 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+209,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->chgBus(c+217,((0x800000U | (0x7fffffU 
                                          & vlTOPp->io_input1))),24);
        vcdp->chgBus(c+225,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->chgBus(c+233,((0x800000U | (0x7fffffU 
                                          & vlTOPp->io_input2))),24);
        vcdp->chgBit(c+241,((1U & ((vlTOPp->io_input1 
                                    & vlTOPp->io_input2) 
                                   >> 0x1fU))));
        vcdp->chgBus(c+249,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input1)) 
                                          + (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input2))))),24);
        vcdp->chgBus(c+257,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input1)) 
                                          - (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input2))))),24);
        vcdp->chgBus(c+265,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input2)) 
                                          - (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input1))))),24);
        vcdp->chgBit(c+273,((1U & (((0xffU & (vlTOPp->io_input1 
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
        vcdp->chgBus(c+281,(((0x100U & ((((0xffU & 
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
                                                       & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                                       ? 
                                                      ((IData)(1U) 
                                                       + (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp))
                                                       : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_57))))),9);
        vcdp->chgBit(c+289,((1U & ((vlTOPp->io_input1 
                                    ^ vlTOPp->io_input2) 
                                   >> 0x1fU))));
        vcdp->chgQuad(c+297,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBus(c+313,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBus(c+321,((((0U == vlTOPp->io_input1) 
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
        vcdp->chgBit(c+329,((1U & ((~ ((0U == vlTOPp->io_input1) 
                                       | (0U == vlTOPp->io_input2))) 
                                   & ((vlTOPp->io_input1 
                                       ^ vlTOPp->io_input2) 
                                      >> 0x1fU)))));
        vcdp->chgBus(c+337,((((0U == vlTOPp->io_input1) 
                              | (0U == vlTOPp->io_input2))
                              ? 0U : (0xffU & ((1U 
                                                & (IData)(
                                                          (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                           >> 0x2fU)))
                                                ? ((IData)(1U) 
                                                   + (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp))
                                                : (
                                                   ((~ (IData)(
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
