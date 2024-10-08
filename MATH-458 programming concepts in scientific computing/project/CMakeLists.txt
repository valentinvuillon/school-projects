
cmake_minimum_required (VERSION 3.1)
project (ProjectODE)
set(CMAKE_CXX_STANDARD 20)
include_directories(eigen-3.4.0)
add_executable(main
        main.cc
        reader.cc
        text_reader.cc
        terminal_reader.cc
        data_in.cc
        function.cc
        simple_function.cc
        integrator.cc
        explicit_integrator.cc
        implicit_integrator.cc
        r_k.cc
        r_k_1.cc
        r_k_2.cc
        r_k_3.cc
        r_k_4.cc
        adams_bashforth.cc
        adams_bashforth_1.cc
        adams_bashforth_2.cc
        adams_bashforth_3.cc
        adams_bashforth_4.cc
        backward_differentiation.cc
        backward_differentiation_1.cc
        backward_differentiation_2.cc
        backward_differentiation_3.cc
        backward_differentiation_4.cc
        adams_moulton.cc
        adams_moulton_1.cc
        adams_moulton_2.cc
        adams_moulton_3.cc
        adams_moulton_4.cc
        data_out.cc
        writer.cc
        text_writer.cc
        terminal_writer.cc
        usefull_function.cpp
        Newton.cc)
