// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmul.h for the primary calling header

#include "Vmul.h"
#include "Vmul__Syms.h"

//==========

VL_CTOR_IMP(Vmul) {
    Vmul__Syms* __restrict vlSymsp = __VlSymsp = new Vmul__Syms(this, name());
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmul::__Vconfigure(Vmul__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmul::~Vmul() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vmul::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmul::eval\n"); );
    Vmul__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("mul.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmul::_eval_initial_loop(Vmul__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("mul.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vmul::_combo__TOP__1(Vmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmul::_combo__TOP__1\n"); );
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mul__DOT__o_mant = (((0U == vlTOPp->io_input1) 
                                 | (0U == vlTOPp->io_input2))
                                 ? VL_ULL(0) : (VL_ULL(0xffffffffffff) 
                                                & ((QData)((IData)(
                                                                   (0x800000U 
                                                                    | (0x7fffffU 
                                                                       & vlTOPp->io_input1)))) 
                                                   * (QData)((IData)(
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->io_input2)))))));
    vlTOPp->mul__DOT__o_exp = (((0U == vlTOPp->io_input1) 
                                | (0U == vlTOPp->io_input2))
                                ? 0U : (0xffU & (((vlTOPp->io_input1 
                                                   >> 0x17U) 
                                                  + 
                                                  (vlTOPp->io_input2 
                                                   >> 0x17U)) 
                                                 - (IData)(0x7fU))));
    vlTOPp->mul__DOT___io_result_T = ((0x80000000U 
                                       & (((~ ((0U 
                                                == vlTOPp->io_input1) 
                                               | (0U 
                                                  == vlTOPp->io_input2))) 
                                           << 0x1fU) 
                                          & (vlTOPp->io_input1 
                                             ^ vlTOPp->io_input2))) 
                                      | (((((0U == vlTOPp->io_input1) 
                                            | (0U == vlTOPp->io_input2))
                                            ? 0U : 
                                           (0xffU & 
                                            ((1U & (IData)(
                                                           (vlTOPp->mul__DOT__o_mant 
                                                            >> 0x2fU)))
                                              ? ((IData)(1U) 
                                                 + (IData)(vlTOPp->mul__DOT__o_exp))
                                              : (((~ (IData)(
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
                                                  : (IData)(vlTOPp->mul__DOT__o_exp))))) 
                                          << 0x17U) 
                                         | (((0U == vlTOPp->io_input1) 
                                             | (0U 
                                                == vlTOPp->io_input2))
                                             ? 0U : 
                                            (0x7fffffU 
                                             & (IData)(
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
                                                        >> 0x17U))))));
    vlTOPp->io_result = (((0U == vlTOPp->io_input1) 
                          | (0U == vlTOPp->io_input2))
                          ? 0U : vlTOPp->mul__DOT___io_result_T);
}

void Vmul::_eval(Vmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmul::_eval\n"); );
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
}

void Vmul::_eval_initial(Vmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmul::_eval_initial\n"); );
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmul::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmul::final\n"); );
    // Variables
    Vmul__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmul::_eval_settle(Vmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmul::_eval_settle\n"); );
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vmul::_change_request(Vmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmul::_change_request\n"); );
    Vmul* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmul::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmul::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

void Vmul::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmul::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_input1 = VL_RAND_RESET_I(32);
    io_input2 = VL_RAND_RESET_I(32);
    io_result = VL_RAND_RESET_I(32);
    mul__DOT__o_mant = VL_RAND_RESET_Q(48);
    mul__DOT__o_exp = VL_RAND_RESET_I(8);
    mul__DOT___io_result_T = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
