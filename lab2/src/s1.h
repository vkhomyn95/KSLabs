#include "systemc.h"
#include<iomanip>
#include <iostream>
#include "math.h"
double calc (double x, double y)
{
    double c = 0;
    for (int i = 1; i <= y; i++)
    {
    	c += x * i;
     }
	return c; 
}

SC_MODULE(Module_S1) {
    sc_in<bool> CLK;
    sc_in<double> X, Y;
    sc_out<double> f1, power;
    void S1_mod() {
        f1.write(calc(X.read(), Y.read()));
        power.write(pow(X.read(), Y.read()));
    }
    // constructor for module
    SC_CTOR(Module_S1) {
        SC_METHOD(S1_mod);
        // sensitive << X << Y;
        sensitive << X << Y << CLK.pos();
	} 
};
