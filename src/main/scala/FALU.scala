import chisel3._
import chisel3.util._

class FALU extends Module {
  val io = IO(new Bundle {
    val input1: UInt = Input(UInt(32.W))
    val input2: UInt = Input(UInt(32.W))
    val aluCtl: UInt = Input(UInt(5.W))
  //  val rmm: UInt = Input(UInt(3.W))
    val opcode: UInt = Input(UInt(7.W))

    val result: UInt = Output(UInt(32.W))
  })

  
  
  

    //   add.io.input1:=io.input1
    //   add.io.input2 := io.input2
    //   io.result:= add.io.result

    when((io.aluCtl==="b00000".U || io.aluCtl==="b00001".U) && io.opcode==="b1010011".U){
        val add = Module(new NFALU)
        add.io.input1:=io.input1
        add.io.input2 := io.input2
        // mult.io.input1:=0.U
        // mult.io.input2 := 0.U
        io.result:= add.io.result
    }.otherwise{
      val mult = Module(new mul)
        // add.io.input1:=0.U
        // add.io.input2 := 0.U
        mult.io.input1:=io.input1
        mult.io.input2 := io.input2
        io.result:= mult.io.result
    }

   

}
