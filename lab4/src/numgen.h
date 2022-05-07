#ifndef NUMGEN_H
#define NUMGEN_H


struct numgen : sc_module {
    sc_in<bool> clk;
    sc_out<double> out1;
    sc_out<double> out2;

    // method to write values to the output ports
    void generate();
    
    //Constructor
    SC_CTOR( numgen ) {
	SC_METHOD( generate );   //Declare generate as SC_METHOD and
        dont_initialize();
        sensitive << clk.pos();  //make it sensitive to positive clock edge
				       
    }
};

#endif


    
