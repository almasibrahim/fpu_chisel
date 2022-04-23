import chisel3._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class NFALUTest extends FreeSpec with ChiselScalatestTester {

  "NFALU Test" in {
    test(new NFALU()).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>

      c.io.input1.poke("h41500000".U)    //13.0
      c.io.input2.poke("h41A00000".U)    //20.0  
      //c.io.aluCtl.poke("b00000".U)             // expected output (42040000)
      //c.io.opcode.poke("b1010011".U)
      c.clock.step(100)
      
      //exp1>exp2

      //pass without rounding mode
      //diff sign

      // c.io.input1.poke("hC20A0000".U)     //-34.5
      // c.io.input2.poke("h41033333".U)     //8.2
      // c.io.aluCtl.poke(10.U)              //pass (C1D26666)
      // c.clock.step(100) 

      // c.io.input1.poke("hC1400000".U)     //-12.0
      // c.io.input2.poke("h40E00000".U)     //7.0
      // c.io.aluCtl.poke(10.U)              //pass (C0A00000)
      // c.clock.step(100) 

      // c.io.input1.poke("h41B00000".U)     //22.0
      // c.io.input2.poke("hC0000000".U)     //-2.0
      // c.io.aluCtl.poke(10.U)              //pass (41A00000)
      // c.clock.step(100)

      // c.io.input1.poke("h41100000".U)     //9.0
      // c.io.input2.poke("hC0000000".U)     //-2.0
      // c.io.aluCtl.poke(10.U)              //pass (40E00000)
      // c.clock.step(100)

      // c.io.input1.poke("h41100000".U)     //9.0
      // c.io.input2.poke("hC0400000".U)     //-3.0
      // c.io.aluCtl.poke(10.U)              //pass (40C00000)
      // c.clock.step(100)

      // c.io.input1.poke("h41300000".U)     //11.0
      // c.io.input2.poke("hC0400000".U)     //-3.0
      // c.io.aluCtl.poke(10.U)              //pass (41000000)
      // c.clock.step(100)


      //same sign cases

      // c.io.input1.poke("h35C29D9F".U)     //0.00000145
      // c.io.input2.poke("h34B6893F".U)     //0.00000034
      // c.io.aluCtl.poke(10.U)              //pass (round+1)
      // c.clock.step(100)

      // c.io.input1.poke("h4248676D".U)     //50.101
      // c.io.input2.poke("h40B67EFA".U)     //5.703
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("h372251CF".U)     //9.675E-6
      // c.io.input2.poke("h367D001B".U)     //0.00000377
      // c.io.aluCtl.poke(10.U)              //pass (round+1)
      // c.clock.step(100)

      // c.io.input1.poke("hC227EB85".U)     //-41.98
      // c.io.input2.poke("hC17C7AE1".U)     //-15.78
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("h418FD70A".U)     //17.98
      // c.io.input2.poke("h4098F5C3".U)     //4.78
      // c.io.aluCtl.poke(10.U)              //pass (round +1)
      // c.clock.step(100)



    // my
      // c.io.input1.poke("hC2480000".U)     //-50
      // c.io.input2.poke("hC1380000".U)     //-11.5
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("hC1B40000".U)     //-22.5
      // c.io.input2.poke("hC0B00000".U)     //-5.5
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("hC20A0000".U)     //-34.5
      // c.io.input2.poke("hC1380000".U)     //-11.5
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("h420A0000".U)     //34.5
      // c.io.input2.poke("h41380000".U)     //11.5
      // c.io.aluCtl.poke(10.U)              //pass (shift 3)
      // c.clock.step(100)

      // c.io.input1.poke("h41B40000".U)     //22.5
      // c.io.input2.poke("h40200000".U)     //2.5
      // c.io.aluCtl.poke(10.U)              //pass (shift 3)
      // c.clock.step(100)

      // c.io.input1.poke("h41AC0000".U)     //21.5
      // c.io.input2.poke("h40200000".U)     //2.5
      // c.io.aluCtl.poke(10.U)              //pass (shift 3)
      // c.clock.step(100)

      // c.io.input1.poke("h41080000".U)     //8.5 
      // c.io.input2.poke("h40200000".U)     //2.5
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("h412CCCCD".U)     //10.8  
      // c.io.input2.poke("h406CCCCD".U)     //3.7
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("h411CCCCD".U)     //9.8
      // c.io.input2.poke("h40000000".U)      //2.0
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("h411CCCCD".U)     //9.8   
      // c.io.input2.poke("h4039999A".U)     //2.9 
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)

      // c.io.input1.poke("hC1F20002".U)     
      // c.io.input2.poke("hC0C00185".U)      
      // c.io.aluCtl.poke(10.U)              //pass
      // c.clock.step(100)
      
      
      
      //exp1===exp2
      
      //sign1===sign2

        //pass
      // c.io.input1.poke("h412B3333".U)     // (10.7)
      // c.io.input2.poke("hC14B3334".U)     //(-12.700001)  
      // c.io.aluCtl.poke(10.U)              //expected output (C0000004)
      // c.clock.step(100)

      //pass
      // c.io.input1.poke("hC0200000".U)     // (-2.5)
      // c.io.input2.poke("h40333333".U)     //(2.8)  
      // c.io.aluCtl.poke(10.U)              //expected output (3E999998)
      // c.clock.step(100)


      //pass
      // c.io.input1.poke("h43168000".U)     // (150.5)
      // c.io.input2.poke("h43118000".U)     //(145.5)  
      // c.io.aluCtl.poke(10.U)              //expected output (43940000)
      // c.clock.step(100)



        //pass
        // c.io.input1.poke("h47435000".U)    //5e4
        // c.io.input2.poke("h476A6000".U)    //6e4   
        // c.io.aluCtl.poke(10.U)           // expected output (47D6D800)
        // c.clock.step(100)



        //pass
        // c.io.input1.poke("h385A1A93".U)    //0.000052
        // c.io.input2.poke("h381B3073".U)    //0.000037   
        // c.io.aluCtl.poke(10.U)           // expected output (38BAA583)
        // c.clock.step(100)




        //pass
        // c.io.input1.poke("hC53B8000".U)    //-3e4
        // c.io.input2.poke("hC53B8000".U)    //-3e4   
        // c.io.aluCtl.poke(10.U)           // expected output (C5BB8000)
        // c.clock.step(100)


        //pass
        // c.io.input1.poke("h4A989680".U)    //5e6
        // c.io.input2.poke("h4AB71B00".U)    //6e6   
        // c.io.aluCtl.poke(10.U)           // expected output (4B27D8C0)       passsss
        // c.clock.step(100)




        //pass
        // c.io.input1.poke("hC024538F".U)    //-2.5676
        // c.io.input2.poke("h4024538F".U)    //2.5676 
        // c.io.aluCtl.poke(10.U)           // expected output (00000000)
        // c.clock.step(100)



        //pass
        // c.io.input1.poke("h407F3B64".U)    //3.988
        // c.io.input2.poke("h403F1AA0".U)    //2.986
        // c.io.aluCtl.poke(10.U)           // expected output (40DF2B02)      
        // c.clock.step(100)


        //pass
        // c.io.input1.poke("h407F3B64".U)    //3.988
        // c.io.input2.poke("hC03F1AA0".U)    //-2.986
        // c.io.aluCtl.poke(10.U)           // expected output (3F804188)
        // c.clock.step(100)



        //pass
        // c.io.input1.poke("hC07F3B64".U)    //-3.988
        // c.io.input2.poke("h403F1AA0".U)    //2.986
        // c.io.aluCtl.poke(10.U)           // expected output (BF804188)
        // c.clock.step(100)


      // c.io.input1.poke("hC7927C00".U)    //-75000.0
      // c.io.input2.poke("h47A60400".U)    //85000.0  
      // c.io.aluCtl.poke(10.U)           //  10000.0 (461C4000) //pass
      // c.clock.step(100)


      // c.io.input1.poke("hC7927C00".U)    //-75000.0
      // c.io.input2.poke("h47A60400".U)    //85000.0  
      // c.io.aluCtl.poke(10.U)           //  10000.0 (461C4000) //pass
      // c.clock.step(100)

      // c.io.input1.poke("hC7927C00".U)    //-75000.0
      // c.io.input2.poke("hC7A60400".U)    //-85000.0  
      // c.io.aluCtl.poke(10.U)           //  -160000.0 (C81C4000) //pass
      // c.clock.step(100)
     
      // c.io.input1.poke("h47435000".U)    //5e4
      // c.io.input2.poke("h471c4000".U)    //4e4   
      // c.io.aluCtl.poke(10.U)           //  9e4 (47AFC800) //pass
      // c.clock.step(100)

      // c.io.input1.poke("h407F3B64".U)     //3.988
      // c.io.input2.poke("h403F1AA0".U)     //2.986
      // c.io.aluCtl.poke(10.U)              //6.974      (40DF2B02) //pass
      // c.clock.step(100)

     

    }
  }
}
