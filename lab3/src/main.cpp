#include "systemc.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "display.h"
#include "numgen.h"

int sc_main(int argc, char** argv) {
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

    stage1 S1("stage1");
    S1(clk, in1, in2, sum, diff);

    stage2 S2("stage2");
    S2(clk, sum, diff, prod, quot);

    stage3 S3("stage3");
    S3(clk, prod, quot, powr, itr);

    display D("display");
    D(clk, sum, diff, prod, quot, powr, itr);

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

