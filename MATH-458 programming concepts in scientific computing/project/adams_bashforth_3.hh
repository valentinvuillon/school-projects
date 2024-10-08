#ifndef __ADAMS_BASHFORTH_3__HH__
#define __ADAMS_BASHFORTH_3__HH__

/* -------------------------------------------------------------------------- */
#include "adams_bashforth.hh"

/** @brief Adams-Bashforth methods with 3 steps
  * This class allows to implement the Adams-Bashforth methods with 3 steps with respect of its weights. The weights are defined by the constructor.
  */

class AdamsBashforth3: public AdamsBashforth{

public:
    //! Constructor of class AdamsBashforth3
    /*! The Constructor of AdamsBashforth3 allows to allocate dynamically and assign values to the weights associated to number of steps = 3 */
    AdamsBashforth3();

    //! Destructor of class AdamsBashforth3
    /*! The Destructor of AdamsBashforth3 allows to deallocate the memory that was allocate dynamically for the weights */
    ~AdamsBashforth3();


};

/* -------------------------------------------------------------------------- */
#endif //__ADAMS_BASHFORTH_3__HH__
