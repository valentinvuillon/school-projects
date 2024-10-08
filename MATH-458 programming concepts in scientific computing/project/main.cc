
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "text_reader.hh"
#include "terminal_reader.hh"
#include "data_in.hh"
#include "data_out.hh"
#include "text_writer.hh"
#include "r_k.hh"
#include "r_k_1.hh"
#include "r_k_2.hh"
#include "r_k_3.hh"
#include "r_k_4.hh"
#include "integrator.hh"
#include "explicit_integrator.hh"
#include "adams_bashforth.hh"
#include "adams_bashforth_2.hh"
#include "adams_bashforth_3.hh"
#include "adams_bashforth_4.hh"
#include "backward_differentiation_1.hh"
#include "backward_differentiation_2.hh"
#include "backward_differentiation_3.hh"
#include "backward_differentiation_4.hh"
#include "adams_moulton_1.hh"
#include "adams_moulton_2.hh"
#include "adams_moulton_3.hh"
#include "adams_moulton_4.hh"





int main(int argc, char ** argv){
    unsigned int ReadingChoice;
    std::cout << "Enter 0 if you already have an input_file, otherwise enter 1 " <<std::endl;
    std::cin>>ReadingChoice;
    if (ReadingChoice==0) {
        std::cout << "Enter the path of the input_file.txt " << std::endl;
        std::string path;
        std::cin >> path;
        TextReader text_reader(path);
        DataIn data_in(text_reader.Read());
        DataOut data_out(data_in.GetNumberNodes(), data_in.GetInitialCondition(), data_in.GetInterval()[0],
                         data_in.GetDimension());

        int step = data_in.GetStep();

        if (data_in.GetIntegrationMethod() == "AdamsBashforth") {

            if (step == 1) {
                RK1 adams_basforth_1;
                adams_basforth_1.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(),
                                                data_in.GetFunction(), step, data_in.GetDimension());

            }
            if (step == 2) {
                AdamsBashforth2 adams_basforth_2;
                adams_basforth_2.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(),
                                                data_in.GetFunction(), step, data_in.GetDimension());
            }
            if (step == 3) {
                AdamsBashforth3 adams_basforth_3;
                adams_basforth_3.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(),
                                                data_in.GetFunction(), step, data_in.GetDimension());
            }
            if (step == 4) {
                AdamsBashforth4 adams_basforth_4;
                adams_basforth_4.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(),
                                                data_in.GetFunction(), step, data_in.GetDimension());
            }
        }

        if (data_in.GetIntegrationMethod() == "ForwardEuler") {
            RK1 forward_euler;
            forward_euler.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), 1,
                                         data_in.GetDimension());
        }

        if (data_in.GetIntegrationMethod() == "BackwardEuler") {
            BackwardDifferentiation1 backward_euler;
            backward_euler.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), 1,
                                          data_in.GetDimension());
        }

        if (data_in.GetIntegrationMethod() == "RungeKutta") {

            if (step == 1) {
                RK1 runge_kutta_1;
                runge_kutta_1.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(),
                                             step, data_in.GetDimension());

            }
            if (step == 2) {
                RK2 runge_kutta_2;
                runge_kutta_2.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(),
                                             step, data_in.GetDimension());
            }
            if (step == 3) {
                RK3 runge_kutta_3;
                runge_kutta_3.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(),
                                             step, data_in.GetDimension());
            }
            if (step == 4) {
                RK4 runge_kutta_4;
                runge_kutta_4.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(),
                                             step, data_in.GetDimension());
            }

        }

        if (data_in.GetIntegrationMethod() == "BackwardDifferentiationFormula") {

            if (step == 1) {
                BackwardDifferentiation1 bd1;
                bd1.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());

            }
            if (step == 2) {
                BackwardDifferentiation2 bd2;
                bd2.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }
            if (step == 3) {
                BackwardDifferentiation3 bd3;
                bd3.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }
            if (step == 4) {
                BackwardDifferentiation4 bd4;
                bd4.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }


        }

        if (data_in.GetIntegrationMethod() == "AdamsMoulton") {

            if (step == 1) {
                AdamsMoulton1 am1;
                am1.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());

            }
            if (step == 2) {
                AdamsMoulton2 am2;
                am2.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }
            if (step == 3) {
                AdamsMoulton3 am3;
                am3.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }
            if (step == 4) {
                AdamsMoulton4 am4;
                am4.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }

        }


        TextWriter text_writer;
        text_writer.write(data_out);
    } else{

        TerminalReader terminal_reader;
        DataIn data_in(terminal_reader.Read());
        DataOut data_out(data_in.GetNumberNodes(), data_in.GetInitialCondition(), data_in.GetInterval()[0], data_in.GetDimension());

        int step = data_in.GetStep();

        if (data_in.GetIntegrationMethod() == "AdamsBashforth") {

            if (step == 1) {
                RK1 adams_basforth_1;
                adams_basforth_1.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(),
                                                data_in.GetFunction(), step, data_in.GetDimension());

            }
            if (step == 2) {
                AdamsBashforth2 adams_basforth_2;
                adams_basforth_2.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(),
                                                data_in.GetFunction(), step, data_in.GetDimension());
            }
            if (step == 3) {
                AdamsBashforth3 adams_basforth_3;
                adams_basforth_3.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(),
                                                data_in.GetFunction(), step, data_in.GetDimension());
            }
            if (step == 4) {
                AdamsBashforth4 adams_basforth_4;
                adams_basforth_4.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(),
                                                data_in.GetFunction(), step, data_in.GetDimension());
            }
        }

        if (data_in.GetIntegrationMethod() == "ForwardEuler") {
            RK1 forward_euler;
            forward_euler.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), 1,
                                         data_in.GetDimension());
        }

        if (data_in.GetIntegrationMethod() == "BackwardEuler") {
            BackwardDifferentiation1 backward_euler;
            backward_euler.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), 1,
                                          data_in.GetDimension());
        }

        if (data_in.GetIntegrationMethod() == "RungeKutta") {

            if (step == 1) {
                RK1 runge_kutta_1;
                runge_kutta_1.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(),
                                             step, data_in.GetDimension());

            }
            if (step == 2) {
                RK2 runge_kutta_2;
                runge_kutta_2.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(),
                                             step, data_in.GetDimension());
            }
            if (step == 3) {
                RK3 runge_kutta_3;
                runge_kutta_3.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(),
                                             step, data_in.GetDimension());
            }
            if (step == 4) {
                RK4 runge_kutta_4;
                runge_kutta_4.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(),
                                             step, data_in.GetDimension());
            }

        }

        if (data_in.GetIntegrationMethod() == "BackwardDifferentiationFormula") {

            if (step == 1) {
                BackwardDifferentiation1 bd1;
                bd1.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());

            }
            if (step == 2) {
                BackwardDifferentiation2 bd2;
                bd2.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }
            if (step == 3) {
                BackwardDifferentiation3 bd3;
                bd3.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }
            if (step == 4) {
                BackwardDifferentiation4 bd4;
                bd4.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }


        }

        if (data_in.GetIntegrationMethod() == "AdamsMoulton") {

            if (step == 1) {
                AdamsMoulton1 am1;
                am1.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());

            }
            if (step == 2) {
                AdamsMoulton2 am2;
                am2.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }
            if (step == 3) {
                AdamsMoulton3 am3;
                am3.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }
            if (step == 4) {
                AdamsMoulton4 am4;
                am4.TotalIntegrate(data_out, data_in.GetNumberNodes(), data_in.GetDt(), data_in.GetFunction(), step,
                                   data_in.GetDimension());
            }

        }
        TextWriter text_writer;
        text_writer.write(data_out);
    }

    return EXIT_FAILURE;
}
