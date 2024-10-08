#include "simple_function.hh"
#include <cmath>
#include <cassert>
#include <iostream>
#include "Newton.hh"


//we seek the root of the function g(x) which takes as inputs real numbers and returns real numbers
double Newton(double A, double B, Function *f, double initial_guess, double tn){
    int Nmax=1000; //maximum number of iterations in the loop
    int N=0; //number of the iteration in the loop
    double tolerance=1e-5;
    Eigen::VectorXd x_root(1);
    x_root(0)=initial_guess;
    double g_of_x=1;
    double g_prime_of_x;
    bool reached_max_number_of_iterations=false;



    while(abs(g_of_x)>=tolerance && N<Nmax) {
        g_of_x = A * (*f).evaluate(tn, x_root)(0) + B - x_root(0);
        g_prime_of_x = A * f->evaluate_partial_derivative_with_respect_to_time(tn, x_root(0)) - 1;
        x_root(0) = x_root(0) - g_of_x / g_prime_of_x;
        N += 1;



    }




    if(N>=Nmax){
        reached_max_number_of_iterations=true;
    }

    assert(!reached_max_number_of_iterations);

    return x_root(0);


}
