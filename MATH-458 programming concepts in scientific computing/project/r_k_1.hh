#ifndef __R_K_1__HH__
#define __R_K_1__HH__

/* -------------------------------------------------------------------------- */
#include "r_k.hh"

/** @brief Runge Kutta order 1
  * This class allows to implement the Runge Kutta of order 1 with respect of its weights. The weights are defined by the constructor.
  */

class RK1: public RK{


public:
    //! Constructor of class RK1
    /*! The Constructor of RK1 allows to allocate and assign value to the weights that are present in the Butcher tableau */
    RK1();

    //! Destructor of class RK1
    /*! The Destructor of RK1 allows to deallocate the memory that was allocate dynamically for the weights */
    ~RK1();


};

/* -------------------------------------------------------------------------- */
#endif //__R_K_1__HH__
