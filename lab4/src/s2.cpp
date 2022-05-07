#include "systemc.h"
#include "s2.h"


//Definition of addsub method
void s2::setOutputVars()
{
    r1.write(power.read() * power.read());
    r2.write(f1.read() * f1.read());

} // end of addsub method