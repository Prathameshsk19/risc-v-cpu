#include "Valu.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

vluint64_t sim_time = 0;

void run_test(Valu* top, VerilatedVcdC* tfp, int op, int a, int b, const char* name) {
    top->a = a;
    top->b = b;
    top->op = op;

    top->eval();
    tfp->dump(sim_time++);

    std::cout << name << " | a=" << a << " b=" << b 
              << " → result=" << top->result << std::endl;
}

int main() {
    Verilated::traceEverOn(true);

    Valu* top = new Valu;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    // -------- BASIC TESTS --------
    run_test(top, tfp, 0, 10, 5, "ADD");
    run_test(top, tfp, 1, 10, 5, "SUB");
    run_test(top, tfp, 2, 10, 5, "AND");
    run_test(top, tfp, 3, 10, 5, "OR");
    run_test(top, tfp, 4, 10, 5, "XOR");

    // -------- SHIFT TESTS --------
    run_test(top, tfp, 5, 8, 2, "SLL");   // 8 << 2 = 32
    run_test(top, tfp, 6, 8, 2, "SRL");   // 8 >> 2 = 2

    // -------- SIGNED TESTS --------
    run_test(top, tfp, 7, -8, 2, "SRA");  // -8 >>> 2 = -2

    // -------- COMPARISON TESTS --------
    run_test(top, tfp, 8, -1, 1, "SLT");   // signed
    run_test(top, tfp, 9, -1, 1, "SLTU");  // unsigned

    // -------- EDGE CASES --------
    run_test(top, tfp, 0, 0, 0, "ADD zero");
    run_test(top, tfp, 1, 5, 10, "SUB negative");
    run_test(top, tfp, 5, 1, 31, "SLL max shift");

    tfp->close();
    delete top;
    return 0;
}