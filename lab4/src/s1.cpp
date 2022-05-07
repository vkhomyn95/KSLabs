#include "systemc.h"
#include "s1.h"


//Definition of addsub method
void s1::first()
{
    double x = in1.read();
    double y = in2.read();

    //power 
    double resP = pow(x, y);
    power.write(resP);
    //f1 
    double resF1 = 0;
    double temp = 0;
    for (int i = 1; i < y + 1; i++)
    {
        temp = x * i;

        resF1 = resF1 + temp;
    }

    f1.write(resF1);

} // end of addsub method