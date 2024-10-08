#include "adams_bashforth_2.hh"
/* -------------------------------------------------------------------------- */

//Constructor
AdamsBashforth2::AdamsBashforth2()
{
    //Allocate memory for vectors Weight_ab
    Allocate_v(mWeight_ab,2);

    mWeight_ab[0]=3.0/2.0;
    mWeight_ab[1]=-1.0/2.0;
}

// Destructor
AdamsBashforth2::~AdamsBashforth2()
{
    Delete_v(mWeight_ab);
}

