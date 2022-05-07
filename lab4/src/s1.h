#ifndef S1_H
#define S1_H

struct s1 : sc_module {
    sc_in<bool> clk;
    sc_in<double> in1;
    sc_in<double> in2;
    sc_out<double> power;
    sc_out<double> f1;

    void first();       //method implementing functionality

    //Counstructor
    SC_CTOR(s1) {
        SC_METHOD(first);     //Declare addsub as SC_METHOD and  
        dont_initialize();
        sensitive << clk.pos();  //make it sensitive to positive clock edge
    }

};

#endif