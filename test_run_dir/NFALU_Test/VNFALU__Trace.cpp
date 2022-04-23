// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VNFALU__Syms.h"


//======================

void VNFALU::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VNFALU* t = (VNFALU*)userthis;
    VNFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VNFALU::traceChgThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VNFALU::traceChgThis__2(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->NFALU__DOT__diff),8);
        vcdp->chgBus(c+9,(vlTOPp->NFALU__DOT__tmp_mant),24);
        vcdp->chgBus(c+17,(vlTOPp->NFALU__DOT__o_exp),8);
        vcdp->chgBus(c+25,(vlTOPp->NFALU__DOT__o_mant),25);
        vcdp->chgBus(c+33,((0xffU & ((0x1000000U & vlTOPp->NFALU__DOT__o_mant)
                                      ? ((IData)(1U) 
                                         + (IData)(vlTOPp->NFALU__DOT__o_exp))
                                      : (IData)(vlTOPp->NFALU__DOT___GEN_57)))),8);
        vcdp->chgBus(c+41,((0xffffffU & (IData)(((0x1000000U 
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
        vcdp->chgBus(c+49,((0x7fffffU & (IData)(((0x1000000U 
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
    }
}

void VNFALU::traceChgThis__3(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+57,(vlTOPp->clock));
        vcdp->chgBit(c+65,(vlTOPp->reset));
        vcdp->chgBus(c+73,(vlTOPp->io_input1),32);
        vcdp->chgBus(c+81,(vlTOPp->io_input2),32);
        vcdp->chgBus(c+89,(vlTOPp->io_result),32);
        vcdp->chgBit(c+97,((1U & (vlTOPp->io_input1 
                                  >> 0x1fU))));
        vcdp->chgBit(c+105,((1U & (vlTOPp->io_input2 
                                   >> 0x1fU))));
        vcdp->chgBus(c+113,((0xffU & (vlTOPp->io_input1 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+121,((0xffU & (vlTOPp->io_input2 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+129,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->chgBus(c+137,((0x800000U | (0x7fffffU 
                                          & vlTOPp->io_input1))),24);
        vcdp->chgBus(c+145,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->chgBus(c+153,((0x800000U | (0x7fffffU 
                                          & vlTOPp->io_input2))),24);
        vcdp->chgBit(c+161,((1U & ((vlTOPp->io_input1 
                                    & vlTOPp->io_input2) 
                                   >> 0x1fU))));
        vcdp->chgBus(c+169,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input1)) 
                                          + (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input2))))),24);
        vcdp->chgBus(c+177,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input1)) 
                                          - (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input2))))),24);
        vcdp->chgBus(c+185,((0xffffffU & ((0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->io_input2)) 
                                          - (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input1))))),24);
        vcdp->chgBit(c+193,((1U & (((0xffU & (vlTOPp->io_input1 
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
        vcdp->chgBus(c+201,(((0x100U & ((((0xffU & 
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
                                                       & vlTOPp->NFALU__DOT__o_mant)
                                                       ? 
                                                      ((IData)(1U) 
                                                       + (IData)(vlTOPp->NFALU__DOT__o_exp))
                                                       : (IData)(vlTOPp->NFALU__DOT___GEN_57))))),9);
    }
}
