#ifndef __FUNCTION__HH__
#define __FUNCTION__HH__

#include "eigen-3.4.0/Eigen/Dense"
/* -------------------------------------------------------------------------- */

/*!
 * A class used to represent the function f in the ODE. We created a class for this to be able to have a general structure for functions
 */

class Function{

public:

    /*!
     * Method to evaluate the function f at the time t with the value of y at this time t
     * @param t double time
     * @param y vector y
     * @return Return a vector of size "Dimension"
     */
    virtual Eigen::VectorXd evaluate(double t, Eigen::VectorXd y) = 0;
    /*!
     * Method to evaluate the function df/dt(t,y) at the time t with the value of y at this time t
     * @param t double time
     * @param y  double y
     * @return Return a double
     * @warning Be careful, this function can only be used when Dimension = 1
     */

    virtual double evaluate_partial_derivative_with_respect_to_time(double t, double y) = 0;



};

/* -------------------------------------------------------------------------- */
#endif //__FUNCTION__HH__
