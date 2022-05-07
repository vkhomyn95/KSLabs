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
} // end of print method

