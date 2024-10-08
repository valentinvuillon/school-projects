#ifndef __READER__HH__
#define __READER__HH__

/* -------------------------------------------------------------------------- */

#include "data_in.hh"
#include <iostream>
#include "simple_function.hh"



//a class used to read the input data of the program. It is an abstract class.
//Its daughters will be able to read from different input sources: text file, terminal...

class Reader{


public:
    //A method which allows to read the input data of the program. It will be redefined
    //for the class daughters
    virtual DataIn Read() = 0;
    void Print_Input();

protected:
    int function_f_choice;
    double Interval[2];
    Eigen::VectorXd InitialCondition;
    std::string IntegrationMethod;
    int Step;
    double dt;
    int Dimension;


};

/* -------------------------------------------------------------------------- */
#endif //__READER__HH__
