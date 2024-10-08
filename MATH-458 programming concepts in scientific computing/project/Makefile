
CXXFLAGS=-g -Wall
CC_FILES     = reader.cc text_reader.cc terminal_reader.cc data_in.cc function.cc simple_function.cc integrator.cc explicit_integrator.cc implicit_integrator.cc r_k.cc r_k_1.cc r_k_2.cc r_k_3.cc r_k_4.cc adams_bashforth.cc adams_bashforth_1.cc adams_bashforth_2.cc adams_bashforth_3.cc adams_bashforth_4.cc backward_differentiation.cc backward_differentiation_1.cc backward_differentiation_2.cc adams_moulton.cc adams_moulton_1.cc adams_moulton_2.cc adams_moulton_3.cc adams_moulton_4.cc data_out.cc writer.cc text_writer.cc terminal_writer.cc
OBJ_FILES    = reader.o text_reader.o terminal_reader.o data_in.o function.o simple_function.o integrator.o explicit_integrator.o implicit_integrator.o r_k.o r_k_1.o r_k_2.o r_k_3.o r_k_4.o adams_bashforth.o adams_bashforth_1.o adams_bashforth_2.o adams_bashforth_3.o adams_bashforth_4.o backward_differentiation.o backward_differentiation_1.o backward_differentiation_2.o adams_moulton.o adams_moulton_1.o adams_moulton_2.o adams_moulton_3.o adams_moulton_4.o data_out.o writer.o text_writer.o terminal_writer.o
HEADER_FILES = reader.hh text_reader.hh terminal_reader.hh data_in.hh function.hh simple_function.hh integrator.hh explicit_integrator.hh implicit_integrator.hh r_k.hh r_k_1.hh r_k_2.hh r_k_3.hh r_k_4.hh adams_bashforth.hh adams_bashforth_1.hh adams_bashforth_2.hh adams_bashforth_3.hh adams_bashforth_4.hh backward_differentiation.hh backward_differentiation_1.hh backward_differentiation_2.hh adams_moulton.hh adams_moulton_1.hh adams_moulton_2.hh adams_moulton_3.hh adams_moulton_4.hh data_out.hh writer.hh text_writer.hh terminal_writer.hh

EXEC=main

$(EXEC): $(OBJ_FILES) main.o
	g++ -g $(OBJ_FILES) main.o -o $@

.o: $(HEADER_FILES)
	g++ -c $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o *~ $(EXEC)

