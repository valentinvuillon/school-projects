#ifndef __ADAMS_BASHFORTH_2__HH__
#define __ADAMS_BASHFORTH_2__HH__

/* -------------------------------------------------------------------------- */
#include "adams_bashforth.hh"

/** @brief Adams-Bashforth methods with 2 steps
  * This class allows to implement the Adams-Bashforth methods with 2 steps with respect of its weights. The weights are defined by the constructor.
  */

class AdamsBashforth2: public AdamsBashforth{

public:
    //! Constructor of class AdamsBashforth2
    /*! The Constructor of AdamsBashforth2 allows to allocate dynamically and assign values to the weights associated to number of steps = 2 */
    AdamsBashforth2();

    //! Destructor of class AdamsBashforth2
    /*! The Destructor of AdamsBashforth2 allows to deallocate the memory that was allocate dynamically for the weights */
    ~AdamsBashforth2();


};

/* -------------------------------------------------------------------------- */
#endif //__ADAMS_BASHFORTH_2__HH__
