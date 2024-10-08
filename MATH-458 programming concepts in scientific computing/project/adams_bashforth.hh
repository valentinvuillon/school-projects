#ifndef __ADAMS_BASHFORTH__HH__
#define __ADAMS_BASHFORTH__HH__

/* -------------------------------------------------------------------------- */
#include "explicit_integrator.hh"

/**
  * @class AdamBashforth
  * @brief Implementation in the method "integrate" of Adams-Bashforth methods
  * This class permit to implement Adams-Bashforth methods up to 4 steps.
  */

class AdamsBashforth: public ExplicitIntegrator{


public:

    /*!
     * @brief Override of the method Integrate
     * This method perform the Adams-Bashforth with "Chosen Stage" steps. The Parameters are described in the pure virtual method defined in the class Integrator.
     */

    void Integrate(DataOut &t_y, int It, double Delta_t,Function *f, int ChosenStage, int Dimension) override;

/* ------------------------------------------------------------------------ */

protected:
    //! Protected Pointers vector of Weights  used in the implementation of Adams-Bashforth methods
    /*! Here, the Weights are just defined. The allocation and assignation are provided in sub-classes of AdamsBashforth */

    double *mWeight_ab;

};

/* -------------------------------------------------------------------------- */
#endif //__ADAMS_BASHFORTH__HH__
