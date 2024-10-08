#ifndef __R_K_3__HH__
#define __R_K_3__HH__

/* -------------------------------------------------------------------------- */
#include "r_k.hh"

/** @brief Runge Kutta order 3
  * This class allows to implement the Runge Kutta of order 3 with respect of its weights. The weights are defined by the constructor.
  */

class RK3: public RK{


public:
    //! Constructor of class RK3
    /*! The Constructor of RK3 allows to allocate and assign value to the weights that are present in the Butcher tableau */
    RK3();

    //! Destructor of class RK3
    /*! The Destructor of RK3 allows to deallocate the memory that was allocate dynamically for the weights */
    ~RK3();


};

/* -------------------------------------------------------------------------- */
#endif //__R_K_3__HH__
