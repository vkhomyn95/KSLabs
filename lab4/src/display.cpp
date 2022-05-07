#include "systemc.h"
#include "display.h"

#include <stdio.h>

//Definition of print_result method 
void display::print_result()
{
    cout << "clk is " << clk << endl;
    cout << "sum is " << sum << endl;
    cout << "diff is " << diff << endl;
    cout << "prod is " << prod << endl;
    cout << "quot is " << quot << endl;
    cout << "powr is " << powr << endl;
    cout << "itr is " << itr << endl;
    cout << "power " << power << endl;
    cout << "f1 " << f1 << endl;
    cout << "r1 " << r1 << endl;
    cout << "r2 " << r2 << endl;
} // end of print method

