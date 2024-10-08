#ifndef __DATA_IN__HH__
#define __DATA_IN__HH__
#include "function.hh"

/* -------------------------------------------------------------------------- */

#include "function.hh"
#include <string>

/**
 * A class used to store the input data given by the user
 */

class DataIn{

public:


    //! constructor of DataIn
    /*!
     *
     * @param InitialCondition the initial condition(s) of the ODE
     * @param Interval the interval of integration of the ODE
     * @param dt the time step for the integration
     * @param IntegrationMethod the type of integration method (example forward euler)
     * @param Step is the number of steps of the multistep integration method. For Runge Kutta methods, step correspond to the number of stages
     * @param f the function which defines the ODE we solve
     * @param Dimension_ The dimension n of the linear system of ODE (R^n --> R^n)
     * @warning Be careful, the implicit methods (Adams Moulton and Backward Differentiation) only work with dimension = 1, so the parameter f have to be chosen also carefully. Only function that 1D work for these latter
     */
    DataIn(Eigen::VectorXd InitialCondition , double Interval[2] , double dt, std::string IntegrationMethod, int Step, Function* f, int Dimension_);


    ///Destructor of the class DataIn
    ~DataIn(){
        delete f;
    };

public:

    ///A getter to get the initial condition
    Eigen::VectorXd  GetInitialCondition();
    ///A getter to get the dt
    double GetDt();
    ///A getter to get the function
    Function* GetFunction();
    ///A getter for the number of nodes in the interval
    int GetNumberNodes();
    ///A getter to get the function
    std::string GetIntegrationMethod();
    ///A getter to get the integration method
    int GetStep();
    ///A getter to get the integration interval
    double* GetInterval();
    /// A getter to get the dimension of the ODE
    int GetDimension();


private:
    /**@brief The initial condition
     * Initial condition for solving the ODE is represented by a vector
     */
    Eigen::VectorXd InitialCondition;
    /**@brief The integration interval
     * The integration interval is an array[2] of double
     */
    double Interval[2];
    ///The time step for the integration
    double dt;
    /**@brief The number of nodes in the interval
     * The number of nodes is performed by the Euclidian division.
     * @warning If there is a rest by performing the Euclidian division between the Interval length and dt, be aware that the interval will not be totally recovered.
     */
    int number_of_nodes;
    /// The type of integration method example forward euler
    std::string IntegrationMethod;
    /**@brief The number of steps of the integration method.
     * @warning For Runge Kutta methods, this number correspond to the number of stage
     */
    int Step;
    /// A pointer of a Function object
    Function *f;
    /// The dimension of the system of ODE (R^n-->R^n.)
    int Dimension;


};

/* -------------------------------------------------------------------------- */
#endif //__DATA_IN__HH__
