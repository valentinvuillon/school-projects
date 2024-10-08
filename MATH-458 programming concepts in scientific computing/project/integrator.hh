#ifndef __INTEGRATOR__HH__
#define __INTEGRATOR__HH__

/* -------------------------------------------------------------------------- */

#include "data_out.hh"
#include "Eigen/Core"
#include "function.hh"
#include <vector>
#include "usefull_function.hpp"


/**@brief class Integrator
 *Class that allow to solve numerically the system of ODE
  */

class Integrator{


public:

    //! Documentation TODO
    /*!
     * Methods that allowed to solve the ODE over all the interval
     * @param t_y vector t and matrix y
     * @param It Iteration index
     * @param Delta_t time step
     * @param f function choice
     * @param ChosenStage number of stage/step for the method that is used
     * @param Dimension Dimension of the system of ODE
     */
    void TotalIntegrate(DataOut &t_y, int It, double Delta_t,Function *f, int ChosenStage, int Dimension);

    /* ------------------------------------------------------------------------ */
    /*!
     * Methods that allowed to solve the ODE only for the next iteration. This method is pure virtual. Indeed the definition depend on the methods of resolution that is chosen
     * The parameter of thi method are exactly the same
     *
     */
    virtual void Integrate(DataOut &t_y, int It, double Delta_t,Function *f, int ChosenStage, int Dimension)=0;

};

/* -------------------------------------------------------------------------- */
#endif //__INTEGRATOR__HH__
