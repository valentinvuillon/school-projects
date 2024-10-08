#include "simple_function.hh"
/* -------------------------------------------------------------------------- */

SimpleFunction::SimpleFunction(int FunctionChoice_){
    FunctionChoice=FunctionChoice_;
}



/* --------------------------------------------------------------------------- */

Eigen::VectorXd SimpleFunction::evaluate(double t, Eigen::VectorXd y){

    if(FunctionChoice==0){
        Eigen::VectorXd f(1);
        f[0]= 5;
        return f;
    }
    if(FunctionChoice==1){
        Eigen::VectorXd f(1);
        f[0]= t;
        return f;
    }
    if(FunctionChoice==2){
        Eigen::VectorXd f(1);
        f[0]= y[0];
        return f;
    }
    if(FunctionChoice==3){
        Eigen::VectorXd f(2);
        f[0]= t+y[0]+y[1];
        f[1]= 2*t+3*y[0]+y[1];

        return f;
    }

}



/* --------------------------------------------------------------------------- */

double SimpleFunction::evaluate_partial_derivative_with_respect_to_time(double t, double y){
    if(FunctionChoice==0){
        return 0;
    }
    if(FunctionChoice==1){
        return 1;
    }
    if(FunctionChoice==2){
        return 0;
    }
}



