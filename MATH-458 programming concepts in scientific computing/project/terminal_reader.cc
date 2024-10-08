#include "terminal_reader.hh"
/* -------------------------------------------------------------------------- */

DataIn TerminalReader::Read(){

    // Recuperation of the parameters
    std::cout<< "Enter your function choice : "<< std::endl;
    std::cin>> function_f_choice;

    std::cout<< "Enter the interval in which you want to solve the system of ODE's : "<< std::endl;
    std::cin>> Interval[0] >> Interval[1] ;

    std::cout<< "Enter the Dimension of the system of ODE's : "<< std::endl;
    std::cin>> Dimension;

    InitialCondition.resize(Dimension);
    for (int i = 0; i < Dimension; ++i)
    {
        std::cout<<"Enter the initial condition for y_"<<i+1<<std::endl;
        std::cin>>InitialCondition[i];
    }

    std::cout<< "Enter the Integration Method you want : "<< std::endl;
    std::cin>> IntegrationMethod;

    std::cout<< "Enter the number of Step/Stage you want for this latter : "<< std::endl;
    std::cin>> Step;

    std::cout<< "Enter the time step size in [s]"<< std::endl;
    std::cin>> dt;


    Print_Input();

    //Initialization of Data in with all chosen parameters
    Function* f(new SimpleFunction(function_f_choice));
    DataIn data_in(InitialCondition, Interval, dt, IntegrationMethod, Step,f, Dimension);
    return data_in;


}



/* --------------------------------------------------------------------------- */


