// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFALU_H_
#define _VFALU_H_  // guard

#include "verilated.h"

//==========

class VFALU__Syms;
class VFALU_VerilatedVcd;


//----------

VL_MODULE(VFALU) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_aluCtl,4,0);
    VL_IN8(io_opcode,6,0);
    VL_IN(io_input1,31,0);
    VL_IN(io_input2,31,0);
    VL_OUT(io_result,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ FALU__DOT__add__DOT___T_1;
    CData/*7:0*/ FALU__DOT__add__DOT__diff;
    CData/*7:0*/ FALU__DOT__add__DOT__o_exp;
    CData/*7:0*/ FALU__DOT__add__DOT___GEN_35;
    CData/*7:0*/ FALU__DOT__add__DOT___GEN_57;
    CData/*7:0*/ FALU__DOT__add_1__DOT__diff;
    CData/*7:0*/ FALU__DOT__add_1__DOT__o_exp;
    CData/*7:0*/ FALU__DOT__add_1__DOT___GEN_35;
    CData/*7:0*/ FALU__DOT__add_1__DOT___GEN_57;
    CData/*7:0*/ FALU__DOT__mult__DOT__o_exp;
    IData/*23:0*/ FALU__DOT__add__DOT__tmp_mant;
    IData/*24:0*/ FALU__DOT__add__DOT__o_mant;
    IData/*23:0*/ FALU__DOT__add_1__DOT__tmp_mant;
    IData/*24:0*/ FALU__DOT__add_1__DOT__o_mant;
    IData/*31:0*/ FALU__DOT__mult__DOT___io_result_T;
    QData/*39:0*/ FALU__DOT__add__DOT___GEN_34;
    QData/*55:0*/ FALU__DOT__add__DOT___GEN_54;
    QData/*39:0*/ FALU__DOT__add_1__DOT___GEN_34;
    QData/*55:0*/ FALU__DOT__add_1__DOT___GEN_54;
    QData/*47:0*/ FALU__DOT__mult__DOT__o_mant;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFALU__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VFALU);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VFALU(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VFALU();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VFALU__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VFALU__Syms* symsp, bool first);
  private:
    static QData _change_request(VFALU__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VFALU__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VFALU__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VFALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VFALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
