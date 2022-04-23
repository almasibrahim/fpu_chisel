// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU.h"
#include "VALU__Syms.h"

//==========

VL_CTOR_IMP(VALU) {
    VALU__Syms* __restrict vlSymsp = __VlSymsp = new VALU__Syms(this, name());
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VALU::__Vconfigure(VALU__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VALU::~VALU() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VALU::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU::eval\n"); );
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("ALU.v", 243, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU::_eval_initial_loop(VALU__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("ALU.v", 243, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU::_initial__TOP__1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_initial__TOP__1\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_zero = 0U;
}

VL_INLINE_OPT void VALU::_combo__TOP__2(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_combo__TOP__2\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant = 
        (((0U == vlTOPp->io_input1) | (0U == vlTOPp->io_input2))
          ? VL_ULL(0) : (VL_ULL(0xffffffffffff) & ((QData)((IData)(
                                                                   (0x800000U 
                                                                    | (0x7fffffU 
                                                                       & vlTOPp->io_input1)))) 
                                                   * (QData)((IData)(
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->io_input2)))))));
    vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp = (
                                                   ((0U 
                                                     == vlTOPp->io_input1) 
                                                    | (0U 
                                                       == vlTOPp->io_input2))
                                                    ? 0U
                                                    : 
                                                   (0xffU 
                                                    & (((vlTOPp->io_input1 
                                                         >> 0x17U) 
                                                        + 
                                                        (vlTOPp->io_input2 
                                                         >> 0x17U)) 
                                                       - (IData)(0x7fU))));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp = (0xffU 
                                                  & (((0xffU 
                                                       & (vlTOPp->io_input1 
                                                          >> 0x17U)) 
                                                      == 
                                                      (0xffU 
                                                       & (vlTOPp->io_input2 
                                                          >> 0x17U)))
                                                      ? 
                                                     (vlTOPp->io_input1 
                                                      >> 0x17U)
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
                                                       >> 0x17U)
                                                       : 
                                                      (vlTOPp->io_input2 
                                                       >> 0x17U))));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT___T_1 = ((1U 
                                                  & (vlTOPp->io_input1 
                                                     >> 0x1fU)) 
                                                 == 
                                                 (1U 
                                                  & (vlTOPp->io_input2 
                                                     >> 0x1fU)));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT__diff = (((0xffU 
                                                   & (vlTOPp->io_input1 
                                                      >> 0x17U)) 
                                                  == 
                                                  (0xffU 
                                                   & (vlTOPp->io_input2 
                                                      >> 0x17U)))
                                                  ? 0U
                                                  : 
                                                 (0xffU 
                                                  & (((0xffU 
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
    vlTOPp->ALU__DOT__fa__DOT__mult__DOT___io_result_T 
        = ((0x80000000U & (((~ ((0U == vlTOPp->io_input1) 
                                | (0U == vlTOPp->io_input2))) 
                            << 0x1fU) & (vlTOPp->io_input1 
                                         ^ vlTOPp->io_input2))) 
           | (((((0U == vlTOPp->io_input1) | (0U == vlTOPp->io_input2))
                 ? 0U : (0xffU & ((1U & (IData)((vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                 >> 0x2fU)))
                                   ? ((IData)(1U) + (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp))
                                   : (((~ (IData)((vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                   >> 0x2eU))) 
                                       & (0U != (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp)))
                                       ? ((1U == (0x3fU 
                                                  & (IData)(
                                                            (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                             >> 0x29U))))
                                           ? ((IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp) 
                                              - (IData)(5U))
                                           : ((1U == 
                                               (0x1fU 
                                                & (IData)(
                                                          (vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_mant 
                                                           >> 0x2aU))))
                                               ? ((IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp) 
                                                  - (IData)(4U))
                                               : ((1U 
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
                                       : (IData)(vlTOPp->ALU__DOT__fa__DOT__mult__DOT__o_exp))))) 
               << 0x17U) | (((0U == vlTOPp->io_input1) 
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
                                                          >> 0x17U))))));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT__tmp_mant = 
        (((0xffU & (vlTOPp->io_input1 >> 0x17U)) == 
          (0xffU & (vlTOPp->io_input2 >> 0x17U))) ? 0U
          : (0xffffffU & (((0xffU & (vlTOPp->io_input1 
                                     >> 0x17U)) > (0xffU 
                                                   & (vlTOPp->io_input2 
                                                      >> 0x17U)))
                           ? ((0x17U >= (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__diff))
                               ? ((0x800000U | (0x7fffffU 
                                                & vlTOPp->io_input2)) 
                                  >> (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__diff))
                               : 0U) : ((0x17U >= (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__diff))
                                         ? ((0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->io_input1)) 
                                            >> (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__diff))
                                         : 0U))));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant = (0x1ffffffU 
                                                   & (((0xffU 
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
                                                       ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___T_1)
                                                         ? 
                                                        ((0x800000U 
                                                          | (0x7fffffU 
                                                             & vlTOPp->io_input1)) 
                                                         + vlTOPp->ALU__DOT__fa__DOT__add__DOT__tmp_mant)
                                                         : 
                                                        ((0x800000U 
                                                          | (0x7fffffU 
                                                             & vlTOPp->io_input1)) 
                                                         - vlTOPp->ALU__DOT__fa__DOT__add__DOT__tmp_mant))
                                                        : 
                                                       ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___T_1)
                                                         ? 
                                                        ((0x800000U 
                                                          | (0x7fffffU 
                                                             & vlTOPp->io_input2)) 
                                                         + vlTOPp->ALU__DOT__fa__DOT__add__DOT__tmp_mant)
                                                         : 
                                                        ((0x800000U 
                                                          | (0x7fffffU 
                                                             & vlTOPp->io_input2)) 
                                                         - vlTOPp->ALU__DOT__fa__DOT__add__DOT__tmp_mant)))));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_34 = 
        ((1U == (0x7ffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                           >> 0xdU))) ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                         << 0xaU) : 
         ((1U == (0x3ffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                            >> 0xeU))) ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                          << 9U) : 
          ((1U == (0x1ffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                             >> 0xfU))) ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                           << 8U) : (QData)((IData)(
                                                                    ((1U 
                                                                      == 
                                                                      (0xffU 
                                                                       & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                          >> 0x10U)))
                                                                      ? 
                                                                     (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                      << 7U)
                                                                      : 
                                                                     ((1U 
                                                                       == 
                                                                       (0x7fU 
                                                                        & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                           >> 0x11U)))
                                                                       ? 
                                                                      (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                       << 6U)
                                                                       : 
                                                                      ((1U 
                                                                        == 
                                                                        (0x3fU 
                                                                         & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                            >> 0x12U)))
                                                                        ? 
                                                                       (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                        << 5U)
                                                                        : 
                                                                       ((1U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                             >> 0x13U)))
                                                                         ? 
                                                                        (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                         << 4U)
                                                                         : 
                                                                        ((1U 
                                                                          == 
                                                                          (0xfU 
                                                                           & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                              >> 0x14U)))
                                                                          ? 
                                                                         (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                          << 3U)
                                                                          : 
                                                                         ((1U 
                                                                           == 
                                                                           (7U 
                                                                            & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                               >> 0x15U)))
                                                                           ? 
                                                                          (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                           << 2U)
                                                                           : 
                                                                          ((1U 
                                                                            == 
                                                                            (3U 
                                                                             & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                                >> 0x16U)))
                                                                            ? 
                                                                           (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                                            << 1U)
                                                                            : 0U))))))))))));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_35 = 
        (0xffU & ((1U == (0x7ffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                    >> 0xdU))) ? ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                  - (IData)(0xaU))
                   : ((1U == (0x3ffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                        >> 0xeU))) ? 
                      ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                       - (IData)(9U)) : ((1U == (0x1ffU 
                                                 & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                    >> 0xfU)))
                                          ? ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                             - (IData)(8U))
                                          : ((1U == 
                                              (0xffU 
                                               & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                  >> 0x10U)))
                                              ? ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                 - (IData)(7U))
                                              : ((1U 
                                                  == 
                                                  (0x7fU 
                                                   & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                      >> 0x11U)))
                                                  ? 
                                                 ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                  - (IData)(6U))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (0x3fU 
                                                    & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                       >> 0x12U)))
                                                   ? 
                                                  ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                   - (IData)(5U))
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                        >> 0x13U)))
                                                    ? 
                                                   ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                    - (IData)(4U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0xfU 
                                                      & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                         >> 0x14U)))
                                                     ? 
                                                    ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                     - (IData)(3U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                          >> 0x15U)))
                                                      ? 
                                                     ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                      - (IData)(2U))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (3U 
                                                        & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                           >> 0x16U)))
                                                       ? 
                                                      ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                       - (IData)(1U))
                                                       : 0U)))))))))));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_54 = 
        ((1U == (0x1fffffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                              >> 3U))) ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                          << 0x14U)
          : ((1U == (0xfffffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                 >> 4U))) ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                             << 0x13U)
              : ((1U == (0x7ffffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                     >> 5U))) ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                                 << 0x12U)
                  : ((1U == (0x3ffffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                         >> 6U))) ? 
                     ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                      << 0x11U) : ((1U == (0x1ffffU 
                                           & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                              >> 7U)))
                                    ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                       << 0x10U) : 
                                   ((1U == (0xffffU 
                                            & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                               >> 8U)))
                                     ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                        << 0xfU) : 
                                    ((1U == (0x7fffU 
                                             & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                >> 9U)))
                                      ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                         << 0xeU) : 
                                     ((1U == (0x3fffU 
                                              & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                 >> 0xaU)))
                                       ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                          << 0xdU) : 
                                      ((1U == (0x1fffU 
                                               & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                  >> 0xbU)))
                                        ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                           << 0xcU)
                                        : ((1U == (0xfffU 
                                                   & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                      >> 0xcU)))
                                            ? ((QData)((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)) 
                                               << 0xbU)
                                            : vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_34))))))))));
    vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_57 = 
        (0xffU & (((~ (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                       >> 0x17U)) & (0U != (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp)))
                   ? ((1U == (0x1fffffU & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                           >> 3U)))
                       ? ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                          - (IData)(0x14U)) : ((1U 
                                                == 
                                                (0xfffffU 
                                                 & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                    >> 4U)))
                                                ? ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                   - (IData)(0x13U))
                                                : (
                                                   (1U 
                                                    == 
                                                    (0x7ffffU 
                                                     & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                        >> 5U)))
                                                    ? 
                                                   ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                    - (IData)(0x12U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x3ffffU 
                                                      & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                         >> 6U)))
                                                     ? 
                                                    ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                     - (IData)(0x11U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1ffffU 
                                                       & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                          >> 7U)))
                                                      ? 
                                                     ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                      - (IData)(0x10U))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (0xffffU 
                                                        & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                           >> 8U)))
                                                       ? 
                                                      ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                       - (IData)(0xfU))
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (0x7fffU 
                                                         & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                            >> 9U)))
                                                        ? 
                                                       ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                        - (IData)(0xeU))
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (0x3fffU 
                                                          & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                             >> 0xaU)))
                                                         ? 
                                                        ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                         - (IData)(0xdU))
                                                         : 
                                                        ((1U 
                                                          == 
                                                          (0x1fffU 
                                                           & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                              >> 0xbU)))
                                                          ? 
                                                         ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                          - (IData)(0xcU))
                                                          : 
                                                         ((1U 
                                                           == 
                                                           (0xfffU 
                                                            & (vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant 
                                                               >> 0xcU)))
                                                           ? 
                                                          ((IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp) 
                                                           - (IData)(0xbU))
                                                           : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_35)))))))))))
                   : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp)));
    vlTOPp->ALU__DOT___GEN_0 = (VL_ULL(0x7fffffffffffffff) 
                                & ((0x53U == (IData)(vlTOPp->io_opcode))
                                    ? (QData)((IData)(
                                                      ((((0U 
                                                          == (IData)(vlTOPp->io_f5)) 
                                                         | (1U 
                                                            == (IData)(vlTOPp->io_f5))) 
                                                        & (0x53U 
                                                           == (IData)(vlTOPp->io_opcode)))
                                                        ? 
                                                       ((0x80000000U 
                                                         & ((((0xffU 
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
                                                        | ((0x7f800000U 
                                                            & (((0x1000000U 
                                                                 & vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_mant)
                                                                 ? 
                                                                ((IData)(1U) 
                                                                 + (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT__o_exp))
                                                                 : (IData)(vlTOPp->ALU__DOT__fa__DOT__add__DOT___GEN_57)) 
                                                               << 0x17U)) 
                                                           | (0x7fffffU 
                                                              & (IData)(
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
                                                        : 
                                                       (((0U 
                                                          == vlTOPp->io_input1) 
                                                         | (0U 
                                                            == vlTOPp->io_input2))
                                                         ? 0U
                                                         : vlTOPp->ALU__DOT__fa__DOT__mult__DOT___io_result_T))))
                                    : ((0U == (IData)(vlTOPp->io_aluCtl))
                                        ? (QData)((IData)(
                                                          (vlTOPp->io_input1 
                                                           & vlTOPp->io_input2)))
                                        : ((1U == (IData)(vlTOPp->io_aluCtl))
                                            ? (QData)((IData)(
                                                              (vlTOPp->io_input1 
                                                               | vlTOPp->io_input2)))
                                            : ((2U 
                                                == (IData)(vlTOPp->io_aluCtl))
                                                ? (QData)((IData)(
                                                                  (vlTOPp->io_input1 
                                                                   + vlTOPp->io_input2)))
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->io_aluCtl))
                                                    ? (QData)((IData)(
                                                                      (vlTOPp->io_input1 
                                                                       - vlTOPp->io_input2)))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlTOPp->io_aluCtl))
                                                     ? (QData)((IData)(
                                                                       VL_LTS_III(1,32,32, vlTOPp->io_input1, vlTOPp->io_input2)))
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlTOPp->io_aluCtl))
                                                      ? (QData)((IData)(
                                                                        (vlTOPp->io_input1 
                                                                         < vlTOPp->io_input2)))
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlTOPp->io_aluCtl))
                                                       ? 
                                                      ((QData)((IData)(vlTOPp->io_input1)) 
                                                       << 
                                                       (0x1fU 
                                                        & vlTOPp->io_input2))
                                                       : (QData)((IData)(
                                                                         ((7U 
                                                                           == (IData)(vlTOPp->io_aluCtl))
                                                                           ? 
                                                                          (vlTOPp->io_input1 
                                                                           >> 
                                                                           (0x1fU 
                                                                            & vlTOPp->io_input2))
                                                                           : 
                                                                          ((8U 
                                                                            == (IData)(vlTOPp->io_aluCtl))
                                                                            ? 
                                                                           VL_SHIFTRS_III(32,32,5, vlTOPp->io_input1, 
                                                                                (0x1fU 
                                                                                & vlTOPp->io_input2))
                                                                            : 
                                                                           ((9U 
                                                                             == (IData)(vlTOPp->io_aluCtl))
                                                                             ? 
                                                                            (vlTOPp->io_input1 
                                                                             ^ vlTOPp->io_input2)
                                                                             : 0U))))))))))))));
    vlTOPp->io_result = (IData)(vlTOPp->ALU__DOT___GEN_0);
}

void VALU::_eval(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
}

void VALU::_eval_initial(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_initial\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void VALU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::final\n"); );
    // Variables
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::_eval_settle(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_settle\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VALU::_change_request(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_change_request\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_opcode & 0x80U))) {
        Verilated::overWidthError("io_opcode");}
    if (VL_UNLIKELY((io_aluCtl & 0xf0U))) {
        Verilated::overWidthError("io_aluCtl");}
    if (VL_UNLIKELY((io_f5 & 0xe0U))) {
        Verilated::overWidthError("io_f5");}
}
#endif  // VL_DEBUG

void VALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_input1 = VL_RAND_RESET_I(32);
    io_input2 = VL_RAND_RESET_I(32);
    io_opcode = VL_RAND_RESET_I(7);
    io_aluCtl = VL_RAND_RESET_I(4);
    io_f5 = VL_RAND_RESET_I(5);
    io_zero = VL_RAND_RESET_I(1);
    io_result = VL_RAND_RESET_I(32);
    ALU__DOT___GEN_0 = VL_RAND_RESET_Q(63);
    ALU__DOT__fa__DOT__add__DOT___T_1 = VL_RAND_RESET_I(1);
    ALU__DOT__fa__DOT__add__DOT__diff = VL_RAND_RESET_I(8);
    ALU__DOT__fa__DOT__add__DOT__tmp_mant = VL_RAND_RESET_I(24);
    ALU__DOT__fa__DOT__add__DOT__o_exp = VL_RAND_RESET_I(8);
    ALU__DOT__fa__DOT__add__DOT__o_mant = VL_RAND_RESET_I(25);
    ALU__DOT__fa__DOT__add__DOT___GEN_34 = VL_RAND_RESET_Q(40);
    ALU__DOT__fa__DOT__add__DOT___GEN_35 = VL_RAND_RESET_I(8);
    ALU__DOT__fa__DOT__add__DOT___GEN_54 = VL_RAND_RESET_Q(56);
    ALU__DOT__fa__DOT__add__DOT___GEN_57 = VL_RAND_RESET_I(8);
    ALU__DOT__fa__DOT__mult__DOT__o_mant = VL_RAND_RESET_Q(48);
    ALU__DOT__fa__DOT__mult__DOT__o_exp = VL_RAND_RESET_I(8);
    ALU__DOT__fa__DOT__mult__DOT___io_result_T = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
