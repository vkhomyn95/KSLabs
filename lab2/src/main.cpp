#include "systemc.h"
#include<iomanip>
#include <iostream>
#include "math.h"

int sc_main(int argc, char** argv) { 
	sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING);
	sc_clock CLK{ "clk", 1, SC_NS };
	sc_signal<double> myVariant, myASCIICode;
    myVariant = 24.0;
    myASCIICode = 156.0; // S + I (83+73 = 156)
    while (myASCIICode.get_new_value() == 0)
    {
        std::cout << "Reenter a myASCIICode: ";
        int a = 0;
        std::cin >> a;
        myASCIICode = a;
    }
    sc_signal<double> f1_S1, power_S1;
    Module_S1 moduleS1("Module_S1");
    moduleS1.CLK(CLK);
    moduleS1.X(myVariant);
    moduleS1.Y(myASCIICode);
    moduleS1.f1(f1_S1);
    moduleS1.power(power_S1);
    sc_signal<double> r1_S2, r2_S2;
    Module_S2 moduleS2("Module_S2");
    moduleS2.CLK(CLK);
    moduleS2.A(f1_S1);
    moduleS2.B(power_S1);
    moduleS2.r1(r1_S2);
    moduleS2.r2(r2_S2);
	display disp("disp");
	disp(CLK, f1_S1, power_S1, r1_S2, r2_S2); sc_start(50, SC_NS);
	return 0; 
}