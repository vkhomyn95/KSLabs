#ifndef DISPLAY_H
#define DISPLAY_H 


struct display : sc_module {
    sc_in<bool> clk;
    sc_in<double> sum;
    sc_in<double> diff;
    sc_in<double> prod;
    sc_in<double> quot;
    sc_in<double> powr;
    sc_in<double> itr;
    sc_in<double> power;
    sc_in<double> f1;
    sc_in<double> r1;
    sc_in<double> r2;

    void print_result();     // method to display input port values
    
    //Constructor
    SC_CTOR( display ) {
	SC_METHOD(print_result); // declare print_result as SC_METHOD and 
    dont_initialize();
	sensitive << clk.pos();    // make it sensitive to positive clock edge
    }
	
};

#endif
