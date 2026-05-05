all:
	rm -rf obj_dir waveform.vcd
	verilator -Wall --trace --cc src/alu.v --exe tb/alu_tb.cpp
	make -C obj_dir -f Valu.mk
	./obj_dir/Valu

wave:
	gtkwave waveform.vcd