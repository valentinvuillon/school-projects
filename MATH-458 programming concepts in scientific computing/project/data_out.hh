#ifndef __DATA_OUT__HH__
#define __DATA_OUT__HH__

/* -------------------------------------------------------------------------- */

#include <vector>
#include <Eigen/Dense>

/**
 * A class dedicated to store the result of the computations --> (matrix y and vector t)
 */

class DataOut{


public:
    //! Constructor of an object of the class DataOut.
    /*!
     * @param Nnodes Number of nodes
     * @param y0 Initial Condition(s)
     * @param InitialTime Initial time
     * @param Dimension The Dimension of the system of ODE
     */
    //t: A vector containing the times t of the integration
    //y: A vector containing the values of the unknown function y at each time t
    DataOut(int Nnodes, Eigen::VectorXd y0, double InitialTime, int Dimension);
    ///A method to get the vector of times t
    std::vector<double> Gett();
    ///A method to get the matrix y
    Eigen::MatrixXd Gety();

    //! Method to set the calculated t at iteration "Iteration" in the private member vector t of DataOut
    /*!
     * @param Iteration Number of the current iteration ones are.
     * @param tNext value of t to set
     */
    void Sett(int Iteration, double tNext);
    //! Method to set the calculated t at iteration "Iteration" in the private member vector t of DataOut
    /*!
     * @param Iteration Number of the current iteration ones are.
     * @param y_iNext Calculated vector y at Iteration ones are
     */
    void Sety_i(int Iteration,  Eigen::VectorXd y_iNext);

private:

    ///A vector containing the times t of the integration
    std::vector<double> t;

    /** @brief Matrix containing all values of calculated y
     * The Matrix is of size (Dimension * number of nodes). The column_i correspond the estimated solution vector y at time i
     */
    Eigen::MatrixXd y;


};

/* -------------------------------------------------------------------------- */
#endif //__DATA_OUT__HH__
