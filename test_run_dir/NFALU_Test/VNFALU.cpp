// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNFALU.h for the primary calling header

#include "VNFALU.h"
#include "VNFALU__Syms.h"

//==========

VL_CTOR_IMP(VNFALU) {
    VNFALU__Syms* __restrict vlSymsp = __VlSymsp = new VNFALU__Syms(this, name());
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VNFALU::__Vconfigure(VNFALU__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VNFALU::~VNFALU() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VNFALU::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VNFALU::eval\n"); );
    VNFALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("NFALU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VNFALU::_eval_initial_loop(VNFALU__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("NFALU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VNFALU::_combo__TOP__1(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_combo__TOP__1\n"); );
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->NFALU__DOT__o_exp = (0xffU & (((0xffU & 
                                            (vlTOPp->io_input1 
                                             >> 0x17U)) 
                                           == (0xffU 
                                               & (vlTOPp->io_input2 
                                                  >> 0x17U)))
                                           ? (vlTOPp->io_input1 
                                              >> 0x17U)
                                           : (((0xffU 
                                                & (vlTOPp->io_input1 
                                                   >> 0x17U)) 
                                               > (0xffU 
                                                  & (vlTOPp->io_input2 
                                                     >> 0x17U)))
                                               ? (vlTOPp->io_input1 
                                                  >> 0x17U)
                                               : (vlTOPp->io_input2 
                                                  >> 0x17U))));
    vlTOPp->NFALU__DOT___T_1 = ((1U & (vlTOPp->io_input1 
                                       >> 0x1fU)) == 
                                (1U & (vlTOPp->io_input2 
                                       >> 0x1fU)));
    vlTOPp->NFALU__DOT__diff = (((0xffU & (vlTOPp->io_input1 
                                           >> 0x17U)) 
                                 == (0xffU & (vlTOPp->io_input2 
                                              >> 0x17U)))
                                 ? 0U : (0xffU & ((
                                                   (0xffU 
                                                    & (vlTOPp->io_input1 
                                                       >> 0x17U)) 
                                                   > 
                                                   (0xffU 
                                                    & (vlTOPp->io_input2 
                                                       >> 0x17U)))
                                                   ? 
                                                  ((vlTOPp->io_input1 
                                                    >> 0x17U) 
                                                   - 
                                                   (vlTOPp->io_input2 
                                                    >> 0x17U))
                                                   : 
                                                  ((vlTOPp->io_input2 
                                                    >> 0x17U) 
                                                   - 
                                                   (vlTOPp->io_input1 
                                                    >> 0x17U)))));
    vlTOPp->NFALU__DOT__tmp_mant = (((0xffU & (vlTOPp->io_input1 
                                               >> 0x17U)) 
                                     == (0xffU & (vlTOPp->io_input2 
                                                  >> 0x17U)))
                                     ? 0U : (0xffffffU 
                                             & (((0xffU 
                                                  & (vlTOPp->io_input1 
                                                     >> 0x17U)) 
                                                 > 
                                                 (0xffU 
                                                  & (vlTOPp->io_input2 
                                                     >> 0x17U)))
                                                 ? 
                                                ((0x17U 
                                                  >= (IData)(vlTOPp->NFALU__DOT__diff))
                                                  ? 
                                                 ((0x800000U 
                                                   | (0x7fffffU 
                                                      & vlTOPp->io_input2)) 
                                                  >> (IData)(vlTOPp->NFALU__DOT__diff))
                                                  : 0U)
                                                 : 
                                                ((0x17U 
                                                  >= (IData)(vlTOPp->NFALU__DOT__diff))
                                                  ? 
                                                 ((0x800000U 
                                                   | (0x7fffffU 
                                                      & vlTOPp->io_input1)) 
                                                  >> (IData)(vlTOPp->NFALU__DOT__diff))
                                                  : 0U))));
    vlTOPp->NFALU__DOT__o_mant = (0x1ffffffU & (((0xffU 
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
                                                 (0x1000000U 
                                                  | (0xffffffU 
                                                     & ((0x800000U 
                                                         | (0x7fffffU 
                                                            & vlTOPp->io_input1)) 
                                                        + 
                                                        (0x800000U 
                                                         | (0x7fffffU 
                                                            & vlTOPp->io_input2)))))
                                                  : 
                                                 (((0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input1)) 
                                                   > 
                                                   (0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input2)))
                                                   ? 
                                                  (0xffffffU 
                                                   & ((0x800000U 
                                                       | (0x7fffffU 
                                                          & vlTOPp->io_input1)) 
                                                      - 
                                                      (0x800000U 
                                                       | (0x7fffffU 
                                                          & vlTOPp->io_input2))))
                                                   : 
                                                  (0xffffffU 
                                                   & ((0x800000U 
                                                       | (0x7fffffU 
                                                          & vlTOPp->io_input2)) 
                                                      - 
                                                      (0x800000U 
                                                       | (0x7fffffU 
                                                          & vlTOPp->io_input1))))))
                                                 : 
                                                (((0xffU 
                                                   & (vlTOPp->io_input1 
                                                      >> 0x17U)) 
                                                  > 
                                                  (0xffU 
                                                   & (vlTOPp->io_input2 
                                                      >> 0x17U)))
                                                  ? 
                                                 ((IData)(vlTOPp->NFALU__DOT___T_1)
                                                   ? 
                                                  ((0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input1)) 
                                                   + vlTOPp->NFALU__DOT__tmp_mant)
                                                   : 
                                                  ((0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input1)) 
                                                   - vlTOPp->NFALU__DOT__tmp_mant))
                                                  : 
                                                 ((IData)(vlTOPp->NFALU__DOT___T_1)
                                                   ? 
                                                  ((0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input2)) 
                                                   + vlTOPp->NFALU__DOT__tmp_mant)
                                                   : 
                                                  ((0x800000U 
                                                    | (0x7fffffU 
                                                       & vlTOPp->io_input2)) 
                                                   - vlTOPp->NFALU__DOT__tmp_mant)))));
    vlTOPp->NFALU__DOT___GEN_34 = ((1U == (0x7ffU & 
                                           (vlTOPp->NFALU__DOT__o_mant 
                                            >> 0xdU)))
                                    ? ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                       << 0xaU) : (
                                                   (1U 
                                                    == 
                                                    (0x3ffU 
                                                     & (vlTOPp->NFALU__DOT__o_mant 
                                                        >> 0xeU)))
                                                    ? 
                                                   ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                                    << 9U)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x1ffU 
                                                      & (vlTOPp->NFALU__DOT__o_mant 
                                                         >> 0xfU)))
                                                     ? 
                                                    ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                                     << 8U)
                                                     : (QData)((IData)(
                                                                       ((1U 
                                                                         == 
                                                                         (0xffU 
                                                                          & (vlTOPp->NFALU__DOT__o_mant 
                                                                             >> 0x10U)))
                                                                         ? 
                                                                        (vlTOPp->NFALU__DOT__o_mant 
                                                                         << 7U)
                                                                         : 
                                                                        ((1U 
                                                                          == 
                                                                          (0x7fU 
                                                                           & (vlTOPp->NFALU__DOT__o_mant 
                                                                              >> 0x11U)))
                                                                          ? 
                                                                         (vlTOPp->NFALU__DOT__o_mant 
                                                                          << 6U)
                                                                          : 
                                                                         ((1U 
                                                                           == 
                                                                           (0x3fU 
                                                                            & (vlTOPp->NFALU__DOT__o_mant 
                                                                               >> 0x12U)))
                                                                           ? 
                                                                          (vlTOPp->NFALU__DOT__o_mant 
                                                                           << 5U)
                                                                           : 
                                                                          ((1U 
                                                                            == 
                                                                            (0x1fU 
                                                                             & (vlTOPp->NFALU__DOT__o_mant 
                                                                                >> 0x13U)))
                                                                            ? 
                                                                           (vlTOPp->NFALU__DOT__o_mant 
                                                                            << 4U)
                                                                            : 
                                                                           ((1U 
                                                                             == 
                                                                             (0xfU 
                                                                              & (vlTOPp->NFALU__DOT__o_mant 
                                                                                >> 0x14U)))
                                                                             ? 
                                                                            (vlTOPp->NFALU__DOT__o_mant 
                                                                             << 3U)
                                                                             : 
                                                                            ((1U 
                                                                              == 
                                                                              (7U 
                                                                               & (vlTOPp->NFALU__DOT__o_mant 
                                                                                >> 0x15U)))
                                                                              ? 
                                                                             (vlTOPp->NFALU__DOT__o_mant 
                                                                              << 2U)
                                                                              : 
                                                                             ((1U 
                                                                               == 
                                                                               (3U 
                                                                                & (vlTOPp->NFALU__DOT__o_mant 
                                                                                >> 0x16U)))
                                                                               ? 
                                                                              (vlTOPp->NFALU__DOT__o_mant 
                                                                               << 1U)
                                                                               : 0U))))))))))));
    vlTOPp->NFALU__DOT___GEN_35 = (0xffU & ((1U == 
                                             (0x7ffU 
                                              & (vlTOPp->NFALU__DOT__o_mant 
                                                 >> 0xdU)))
                                             ? ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                - (IData)(0xaU))
                                             : ((1U 
                                                 == 
                                                 (0x3ffU 
                                                  & (vlTOPp->NFALU__DOT__o_mant 
                                                     >> 0xeU)))
                                                 ? 
                                                ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                 - (IData)(9U))
                                                 : 
                                                ((1U 
                                                  == 
                                                  (0x1ffU 
                                                   & (vlTOPp->NFALU__DOT__o_mant 
                                                      >> 0xfU)))
                                                  ? 
                                                 ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                  - (IData)(8U))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (0xffU 
                                                    & (vlTOPp->NFALU__DOT__o_mant 
                                                       >> 0x10U)))
                                                   ? 
                                                  ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                   - (IData)(7U))
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x7fU 
                                                     & (vlTOPp->NFALU__DOT__o_mant 
                                                        >> 0x11U)))
                                                    ? 
                                                   ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                    - (IData)(6U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x3fU 
                                                      & (vlTOPp->NFALU__DOT__o_mant 
                                                         >> 0x12U)))
                                                     ? 
                                                    ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                     - (IData)(5U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->NFALU__DOT__o_mant 
                                                          >> 0x13U)))
                                                      ? 
                                                     ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                      - (IData)(4U))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (0xfU 
                                                        & (vlTOPp->NFALU__DOT__o_mant 
                                                           >> 0x14U)))
                                                       ? 
                                                      ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                       - (IData)(3U))
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->NFALU__DOT__o_mant 
                                                            >> 0x15U)))
                                                        ? 
                                                       ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                        - (IData)(2U))
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (vlTOPp->NFALU__DOT__o_mant 
                                                             >> 0x16U)))
                                                         ? 
                                                        ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                         - (IData)(1U))
                                                         : 0U)))))))))));
    vlTOPp->NFALU__DOT___GEN_54 = ((1U == (0x1fffffU 
                                           & (vlTOPp->NFALU__DOT__o_mant 
                                              >> 3U)))
                                    ? ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                       << 0x14U) : 
                                   ((1U == (0xfffffU 
                                            & (vlTOPp->NFALU__DOT__o_mant 
                                               >> 4U)))
                                     ? ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                        << 0x13U) : 
                                    ((1U == (0x7ffffU 
                                             & (vlTOPp->NFALU__DOT__o_mant 
                                                >> 5U)))
                                      ? ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                         << 0x12U) : 
                                     ((1U == (0x3ffffU 
                                              & (vlTOPp->NFALU__DOT__o_mant 
                                                 >> 6U)))
                                       ? ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                          << 0x11U)
                                       : ((1U == (0x1ffffU 
                                                  & (vlTOPp->NFALU__DOT__o_mant 
                                                     >> 7U)))
                                           ? ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                              << 0x10U)
                                           : ((1U == 
                                               (0xffffU 
                                                & (vlTOPp->NFALU__DOT__o_mant 
                                                   >> 8U)))
                                               ? ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                                  << 0xfU)
                                               : ((1U 
                                                   == 
                                                   (0x7fffU 
                                                    & (vlTOPp->NFALU__DOT__o_mant 
                                                       >> 9U)))
                                                   ? 
                                                  ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                                   << 0xeU)
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x3fffU 
                                                     & (vlTOPp->NFALU__DOT__o_mant 
                                                        >> 0xaU)))
                                                    ? 
                                                   ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                                    << 0xdU)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x1fffU 
                                                      & (vlTOPp->NFALU__DOT__o_mant 
                                                         >> 0xbU)))
                                                     ? 
                                                    ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                                     << 0xcU)
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0xfffU 
                                                       & (vlTOPp->NFALU__DOT__o_mant 
                                                          >> 0xcU)))
                                                      ? 
                                                     ((QData)((IData)(vlTOPp->NFALU__DOT__o_mant)) 
                                                      << 0xbU)
                                                      : vlTOPp->NFALU__DOT___GEN_34))))))))));
    vlTOPp->NFALU__DOT___GEN_57 = (0xffU & (((~ (vlTOPp->NFALU__DOT__o_mant 
                                                 >> 0x17U)) 
                                             & (0U 
                                                != (IData)(vlTOPp->NFALU__DOT__o_exp)))
                                             ? ((1U 
                                                 == 
                                                 (0x1fffffU 
                                                  & (vlTOPp->NFALU__DOT__o_mant 
                                                     >> 3U)))
                                                 ? 
                                                ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                 - (IData)(0x14U))
                                                 : 
                                                ((1U 
                                                  == 
                                                  (0xfffffU 
                                                   & (vlTOPp->NFALU__DOT__o_mant 
                                                      >> 4U)))
                                                  ? 
                                                 ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                  - (IData)(0x13U))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (0x7ffffU 
                                                    & (vlTOPp->NFALU__DOT__o_mant 
                                                       >> 5U)))
                                                   ? 
                                                  ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                   - (IData)(0x12U))
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x3ffffU 
                                                     & (vlTOPp->NFALU__DOT__o_mant 
                                                        >> 6U)))
                                                    ? 
                                                   ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                    - (IData)(0x11U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x1ffffU 
                                                      & (vlTOPp->NFALU__DOT__o_mant 
                                                         >> 7U)))
                                                     ? 
                                                    ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                     - (IData)(0x10U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0xffffU 
                                                       & (vlTOPp->NFALU__DOT__o_mant 
                                                          >> 8U)))
                                                      ? 
                                                     ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                      - (IData)(0xfU))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (0x7fffU 
                                                        & (vlTOPp->NFALU__DOT__o_mant 
                                                           >> 9U)))
                                                       ? 
                                                      ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                       - (IData)(0xeU))
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (0x3fffU 
                                                         & (vlTOPp->NFALU__DOT__o_mant 
                                                            >> 0xaU)))
                                                        ? 
                                                       ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                        - (IData)(0xdU))
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (0x1fffU 
                                                          & (vlTOPp->NFALU__DOT__o_mant 
                                                             >> 0xbU)))
                                                         ? 
                                                        ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                         - (IData)(0xcU))
                                                         : 
                                                        ((1U 
                                                          == 
                                                          (0xfffU 
                                                           & (vlTOPp->NFALU__DOT__o_mant 
                                                              >> 0xcU)))
                                                          ? 
                                                         ((IData)(vlTOPp->NFALU__DOT__o_exp) 
                                                          - (IData)(0xbU))
                                                          : (IData)(vlTOPp->NFALU__DOT___GEN_35)))))))))))
                                             : (IData)(vlTOPp->NFALU__DOT__o_exp)));
    vlTOPp->io_result = ((0x80000000U & ((((0xffU & 
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
                                         << 0x1fU)) 
                         | ((0x7f800000U & (((0x1000000U 
                                              & vlTOPp->NFALU__DOT__o_mant)
                                              ? ((IData)(1U) 
                                                 + (IData)(vlTOPp->NFALU__DOT__o_exp))
                                              : (IData)(vlTOPp->NFALU__DOT___GEN_57)) 
                                            << 0x17U)) 
                            | (0x7fffffU & (IData)(
                                                   ((0x1000000U 
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
                                                      : (QData)((IData)(vlTOPp->NFALU__DOT__o_mant))))))));
}

void VNFALU::_eval(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_eval\n"); );
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
}

void VNFALU::_eval_initial(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_eval_initial\n"); );
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VNFALU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::final\n"); );
    // Variables
    VNFALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VNFALU::_eval_settle(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_eval_settle\n"); );
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VNFALU::_change_request(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_change_request\n"); );
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VNFALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

void VNFALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_input1 = VL_RAND_RESET_I(32);
    io_input2 = VL_RAND_RESET_I(32);
    io_result = VL_RAND_RESET_I(32);
    NFALU__DOT___T_1 = VL_RAND_RESET_I(1);
    NFALU__DOT__diff = VL_RAND_RESET_I(8);
    NFALU__DOT__tmp_mant = VL_RAND_RESET_I(24);
    NFALU__DOT__o_exp = VL_RAND_RESET_I(8);
    NFALU__DOT__o_mant = VL_RAND_RESET_I(25);
    NFALU__DOT___GEN_34 = VL_RAND_RESET_Q(40);
    NFALU__DOT___GEN_35 = VL_RAND_RESET_I(8);
    NFALU__DOT___GEN_54 = VL_RAND_RESET_Q(56);
    NFALU__DOT___GEN_57 = VL_RAND_RESET_I(8);
    __Vm_traceActivity = 0;
}
