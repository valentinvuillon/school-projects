#ifndef __BACKWARD_DIFFERENTIATION__HH__
#define __BACKWARD_DIFFERENTIATION__HH__

/* -------------------------------------------------------------------------- */
#include "implicit_integrator.hh"


class BackwardDifferentiation: public ImplicitIntegrator{

public:

    void Integrate(DataOut &t_y, int It, double Delta_t, Function *f, int ChosenStage, int Dimension);

protected:
    double *mWeight_bd_y;
    double mWeight_bd_f;


};

/* -------------------------------------------------------------------------- */
#endif //__BACKWARD_DIFFERENTIATION__HH__

