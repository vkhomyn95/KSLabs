#ifndef S2_H
#define S2_H

struct s2 : sc_module {
    sc_in<bool> clk;
    sc_in<double> power;
    sc_in<double> f1;
    sc_out<double> r1;
    sc_out<double> r2;

    void setOutputVars();  

    //Counstructor
    SC_CTOR(s2) {
        SC_METHOD(setOutputVars);     //Declare addsub as SC_METHOD and  
        dont_initialize();
        sensitive << clk.pos();  //make it sensitive to positive clock edge
    }

};

#endif
