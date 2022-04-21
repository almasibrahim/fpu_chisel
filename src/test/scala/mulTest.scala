
import chisel3._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class mulTest extends FreeSpec with ChiselScalatestTester {

  "mul Test" in {
    test(new mul()).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>

       // pass
        // c.io.input1.poke("hC28FDAE0".U)   
        // c.io.input2.poke("hBFEB0BE1".U)       
        // c.clock.step(100)                   //(h43041498) 

       // pass
        // c.io.input1.poke("h00000000".U)   
        // c.io.input2.poke("h42A20952".U)       
        // c.clock.step(100)                   //(h00000000) 
       
        // pass
        // c.io.input1.poke("h4203BF7D".U)   
        // c.io.input2.poke("h41AF37B5".U)       
        // c.clock.step(100)                   //(h44345923) 
       
       
        // pass
        // c.io.input1.poke("hBEBAC472".U)   
        // c.io.input2.poke("hC0893607".U)       
        // c.clock.step(100)                   //(h3FC83517) 
        
        // pass
        // c.io.input1.poke("hBF4CCCCD".U)   
        // c.io.input2.poke("h3F9DF3B6".U)       
        // c.clock.step(100)                   //(hBF7CB923) 
        
        
        // pass
        // c.io.input1.poke("h40B9999A".U)   
        // c.io.input2.poke("h404CCCCD".U)       
        // c.clock.step(100)                   //(h41947AE2) (round+1)
       
       
        // pass
        // c.io.input1.poke("h3F7F7CEE".U)    //(0.998)
        // c.io.input2.poke("hBF05E354".U)       //(-0.523)
        // c.clock.step(100)                   //(-0.521954)   (BF059EC7)


       
        //  // pass
        // c.io.input1.poke("hC2B06666".U)    //(-88.2)
        // c.io.input2.poke("h40B9999A".U)       //(5.8)
        // c.clock.step(100)                   //(-511.56)   (C3FFC7AE)

        
        
        // pass
        // c.io.input1.poke("h40E00000".U)    //(7.0)
        // c.io.input2.poke("h41100000".U)       //(9.0)
        // c.clock.step(100)                   //(63.0)   (427C0000)


        //pass
        // c.io.input1.poke("hBE99999A".U)    //(-0.3)
        // c.io.input2.poke("hBE99999A".U)       //(-0.3)
        // c.clock.step(100)                   //(0.09)   (3DB851EC)


      

    }
  }
}
