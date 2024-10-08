#include "adams_bashforth_3.hh"
/* -------------------------------------------------------------------------- */

//Constructor
AdamsBashforth3::AdamsBashforth3()
{
    //Allocate memory for vectors Weight_ab
    Allocate_v(mWeight_ab,3);

    mWeight_ab[0]=23.0/12.0;
    mWeight_ab[1]=-16.0/12.0;
    mWeight_ab[2]=5.0/12.0;
}

// Destructor
AdamsBashforth3::~AdamsBashforth3()
{
    Delete_v(mWeight_ab);
}
