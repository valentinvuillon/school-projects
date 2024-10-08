#ifndef __ADAMS_MOULTON__HH__
#define __ADAMS_MOULTON__HH__

/* -------------------------------------------------------------------------- */
#include "implicit_integrator.hh"

/**
  * Documentation TODO
  */

class AdamsMoulton: public ImplicitIntegrator{

    /* ------------------------------------------------------------------------ */
    /* Methods                                                                  */
    /* ------------------------------------------------------------------------ */

public:

    //! Documentation TODO
    void Integrate(DataOut &t_y, int It, double Delta_t, Function *f, int ChosenStage, int Dimension);

protected:
    double *mWeight_am_f;

};

/* -------------------------------------------------------------------------- */
#endif //__ADAMS_MOULTON__HH__
