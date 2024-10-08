#include "text_reader.hh"
#include <fstream>
#include <cassert>

/* -------------------------------------------------------------------------- */

DataIn TextReader::Read(){

    std::ifstream input_file(path);
    assert(input_file.is_open());

    input_file >> function_f_choice;
    input_file >> Interval[0] >> Interval[1] ;
    input_file >> Dimension ;
    InitialCondition.resize(Dimension);
    for (int i = 0; i < Dimension; ++i)
    {
        input_file >> InitialCondition[i];
    }
    input_file >> IntegrationMethod;
    input_file >> Step;
    input_file>> dt;


    Print_Input();


    input_file.close();

    Function* f(new SimpleFunction(function_f_choice));

    DataIn data_in(InitialCondition, Interval, dt, IntegrationMethod, Step,f, Dimension);

    return data_in;

}



/* --------------------------------------------------------------------------- */


