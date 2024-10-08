#ifndef __R_K_2__HH__
#define __R_K_2__HH__

/* -------------------------------------------------------------------------- */
#include "r_k.hh"

/** @brief Runge Kutta order 2
  * This class allows to implement the Runge Kutta of order 2 with respect of its weights. The weights are defined by the constructor.
  */

class RK2: public RK{


public:
    //! Constructor of class RK2
    /*! The Constructor of RK2 allows to allocate and assign value to the weights that are present in the Butcher tableau */
    RK2();

    //! Destructor of class RK2
    /*! The Destructor of RK2 allows to deallocate the memory that was allocate dynamically for the weights */
    ~RK2();


};

/* -------------------------------------------------------------------------- */
#endif //__R_K_2__HH__
