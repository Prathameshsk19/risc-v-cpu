# RISC-V CPU Design (Verilog + Verilator)

## 📌 Overview
This project is a step-by-step implementation of a RISC-V CPU using Verilog.  
Simulation is done using Verilator and waveforms are viewed using GTKWave.

## 🧱 Current Progress
- ✅ ALU (Arithmetic Logic Unit)
- ⏳ Register File (next)
- ⏳ Control Unit
- ⏳ Datapath
- ⏳ Full CPU

## ⚙️ Tools Used
- Verilog
- Verilator
- GTKWave
- C++ (testbench)
- Git + GitHub

## 🚀 How to Run

```bash
verilator -Wall --cc src/alu.v --exe tb/alu_tb.cpp
make -C obj_dir -f Valu.mk
./obj_dir/Valu


---

📊 Future Goals
Add instruction decoding
Implement pipeline
Run real RISC-V programs

👨‍💻 Author

Prathamesh Kulkarni