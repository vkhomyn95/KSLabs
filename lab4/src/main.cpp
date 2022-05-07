#include "systemc.h"
#include "s1.h"
#include "s2.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "display.h"
#include "numgen.h"

int sc_main(int argc, char** argv) {
    sc_signal<double> f1;
    sc_signal<double> power;
    sc_signal<double> r1;
    sc_signal<double> r2;
    sc_signal<double> in1;
    sc_signal<double> in2;
    sc_signal<double> sum;
    sc_signal<double> diff;
    sc_signal<double> prod;
    sc_signal<double> quot;
    sc_signal<double> powr;
    sc_signal<double> itr;
    //Clock
    sc_signal<bool> clk;
    clk = true;

    numgen N("numgen");
    N(clk, in1, in2);

    s1 MS1("s1");
    MS1(clk, in1, in2, power, f1);

    s2 MS2("s2");
    MS2(clk, power, f1, r1, r2);

    stage1 S1("stage1");
    S1(clk, in1, in2, sum, diff);

    stage2 S2("stage2");
    S2(clk, sum, diff, prod, quot);

    stage3 S3("stage3");
    S3(clk, prod, quot, powr, itr);

    display D("display");
    D(clk, sum, diff, prod, quot, powr, itr, power, f1, r1, r2);

    sc_initialize();

    sc_trace_file* wf = sc_create_vcd_trace_file("signals");
    wf->set_time_unit(1, SC_NS);
    sc_trace(wf, clk, "clk");
    sc_trace(wf, in1, "in1");
    sc_trace(wf, in2, "in2");
    sc_trace(wf, sum, "sum");
    sc_trace(wf, diff, "diff");
    sc_trace(wf, prod, "prod");
    sc_trace(wf, quot, "quot");
    sc_trace(wf, powr, "powr");
    sc_trace(wf, power, "power");
    sc_trace(wf, f1, "f1");
    sc_trace(wf, r1, "r1");
    sc_trace(wf, r2, "r2");


    for (int i = 0; i < 250; i += 25) {
        cout << "Time is now: " << sc_time_stamp() << endl;
        clk.write(1);
        sc_start(25, SC_NS);
        clk.write(0);
        sc_start(25, SC_NS);
    }

    sc_close_vcd_trace_file(wf);

    return 0;
}

