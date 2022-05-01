#include "systemc.h"
#include<iomanip>
#include <iostream>
#include "math.h"

SC_MODULE(Module_S2) {
    sc_in<bool> CLK;
    sc_in<double> A, B;
    sc_out<double> r1, r2;
    void S2_mod() {
        r1.write(A.read() * A.read());
        r2.write(B.read() * B.read());
}
    // constructor for module
    SC_CTOR(Module_S2) {
        SC_METHOD(S2_mod);
        //sensitive << A << B ;
        sensitive << A << B << CLK.pos();
    } 
};