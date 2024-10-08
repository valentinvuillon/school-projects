#ifndef __R_K_4__HH__
#define __R_K_4__HH__

/* -------------------------------------------------------------------------- */
#include "r_k.hh"

/** @brief Runge Kutta order 4
  * This class allows to implement the Runge Kutta of order 4 with respect of its weights. The weights are defined by the constructor.
  */

class RK4: public RK{


public:
    //! Constructor of class RK4
    /*! The Constructor of RK4 allows to allocate and assign value to the weights that are present in the Butcher tableau */
    RK4();

    //! Destructor of class RK4
    /*! The Destructor of RK4 allows to deallocate the memory that was allocate dynamically for the weights */
    ~RK4();


};

/* -------------------------------------------------------------------------- */
#endif //__R_K_4__HH__
