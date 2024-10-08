#ifndef __ADAMS_BASHFORTH_4__HH__
#define __ADAMS_BASHFORTH_4__HH__

/* -------------------------------------------------------------------------- */
#include "adams_bashforth.hh"

/** @brief Adams-Bashforth methods with 4 steps
  * This class allows to implement the Adams-Bashforth methods with 4 steps with respect of its weights. The weights are defined by the constructor.
  */

class AdamsBashforth4: public AdamsBashforth{

public:
    //! Constructor of class AdamsBashforth4
    /*! The Constructor of AdamsBashforth4 allows to allocate dynamically and assign values to the weights associated to number of steps = 4 */
    AdamsBashforth4();

    //! Destructor of class AdamsBashforth4
    /*! The Destructor of AdamsBashforth4 allows to deallocate the memory that was allocate dynamically for the weights */
    ~AdamsBashforth4();


};

/* -------------------------------------------------------------------------- */
#endif //__ADAMS_BASHFORTH_4__HH__
