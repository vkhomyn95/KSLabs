#include "systemc.h"
#include<iomanip>
#include <iostream>
#include "math.h"

SC_MODULE(display) {
    sc_in<bool>   CLK;
    sc_in<double>  f1_S1;
    sc_in<double>  power_S1;
    sc_in<double>  r1_S2;
    sc_in<double>  r2_S2;
    void print()
{
cout << "Module_S1 power is " << power_S1.read() << endl;
        cout << "Module_S1 f1 is "
        cout << "Module_S2 r1 is "
        cout << "Module_S2 r2 is "
    SC_CTOR(display) {
        SC_METHOD(print);
        sensitive << CLK.pos();
    }
};