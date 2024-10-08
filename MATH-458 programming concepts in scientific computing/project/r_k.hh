#ifndef __R_K__HH__
#define __R_K__HH__

/* -------------------------------------------------------------------------- */
#include "explicit_integrator.hh"

/**
  * @class RK
  * @brief Implementation in the method "integrate" of Runge Kutta method
  * This class permit to implement the Runge Kutta method up to order 4.
  */

class RK: public ExplicitIntegrator{


public:

    /*!
     * @brief Override of the method Integrate
     * This method perform the Runge Kutta of Order "Chosen Stage". The Parameters are described in the pure virtual method defined in the class Integrator.
     */

    void Integrate(DataOut &t_y, int It, double Delta_t,Function *f, int ChosenStage, int Dimension) override;

    /*!
     * @brief Compute the parameters K
     * Methods that permit to compute the parameters K that are needed for Runge Kutta integrator. This methods is called in the overridden methods "Integrate" of the class "RK"
     * The Parameters are the same as those described in the pure virtual method defined in the class Integrator.
     * @return The Matrix K. Cols of K represent the vector K_n, where n = 1,2,...,ChosenStage
     */

    Eigen::MatrixXd  GenerateK(Function *f, DataOut t_y, int It, double Delta_t, int ChosenStage, int Dimension);

protected:
    //! Protected Pointers Weights with respect of Butcher tableau  used in the implementation of Runge Kutta methods
    /*! Here, the Weights are just defined. The allocation and assignation are provided in sub-classes of RK */

    double **mWeight_a;

    double *mWeight_b;

    double *mWeight_c;

private:

};


/* -------------------------------------------------------------------------- */
#endif //__R_K__HH__
