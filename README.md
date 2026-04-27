# Project Overview

This project implements a custom 32-bit RISC-V (RV32I) CPU from scratch, with a focus on understanding computer architecture through progressive design and optimization.

Rather than building a complete processor at once, the system is developed in incremental stages, starting from a simple single-cycle CPU and evolving into a pipelined and optimized architecture.

## Development Approach

The CPU is built in the following stages:

- Stage 1: Single-Cycle CPU
ALU (Arithmetic Logic Unit)
Register File (32 × 32-bit)
Control Unit
Instruction & Data Memory Interface
Executes one instruction per clock cycle
- Stage 2: 5-Stage Pipeline
Instruction Fetch (IF)
Instruction Decode (ID)
Execute (EX)
Memory (MEM)
Write Back (WB)

Enhancements:

Hazard Detection Unit
Data Forwarding (Bypassing)
Basic Control Hazard Handling
- Stage 3: Performance Optimization
Pipeline efficiency improvements
Stall minimization
Instruction throughput analysis
- Stage 4: Custom Hardware Accelerator

A MAC (Multiply-Accumulate) unit is integrated via a custom instruction.

Enables efficient vector/dot-product operations
Demonstrates hardware-software co-design
Used for signal processing / compute workloads
- Stage 5: Memory Hierarchy (Cache)
Direct-mapped cache implementation
Hit/miss detection logic
Reduced memory access latency

## Evaluation

The system is analyzed through:

-Functional simulation (Verilator)
-Waveform debugging (GTKWave)
-Performance comparison:
-Single-cycle vs Pipelined
-With vs Without MAC accelerator

## Hardware Perspective (Optional)

Selected modules (ALU / MAC) are synthesized to evaluate:

-Timing
-Area
-Design constraints

## Learning Objectives

This project demonstrates practical understanding of:

-Datapath and control design
-Instruction set architecture (RV32I)
-Pipelining and hazards
-Custom ISA extensions
-Memory hierarchy (cache)
-Hardware/software co-design
-Performance vs complexity trade-offs

##  How to Run

```bash
verilator -Wall --cc src/alu.v --exe tb/alu_tb.cpp
make -C obj_dir -f Valu.mk
./obj_dir/Valu
---




