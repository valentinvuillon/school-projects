#ifndef __SIMPLE_FUNCTION__HH__
#define __SIMPLE_FUNCTION__HH__

/* -------------------------------------------------------------------------- */
#include "function.hh"


//A class used to implement a set of simple functions to test the code

class SimpleFunction: public Function{


public:
    //constructor of a simple function. We implement different types of functions.
    //FunctionChoice: we implemented different types of simple functions. This integer allows us to choose the function we want.

    SimpleFunction(int FunctionChoice);

    //We call this method to evaluate the function f at the time t with the value of y at this time t
    virtual Eigen::VectorXd evaluate(double t, Eigen::VectorXd y) override;
    virtual double evaluate_partial_derivative_with_respect_to_time(double t, double y) override;



public:

    //We implemented different types of simple functions. This integer allows us to choose the function we want.
    int FunctionChoice;

};

/* -------------------------------------------------------------------------- */
#endif //__SIMPLE_FUNCTION__HH__
