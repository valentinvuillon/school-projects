#include "adams_bashforth_4.hh"
/* -------------------------------------------------------------------------- */

//Constructor
AdamsBashforth4::AdamsBashforth4()
{
    //Allocate memory for vectors Weight_ab
    Allocate_v(mWeight_ab,4);

    mWeight_ab[0]=55.0/24.0;
    mWeight_ab[1]=-59.0/24.0;
    mWeight_ab[2]=37.0/24.0;
    mWeight_ab[3]=-9.0/24.0;
}

// Destructor
AdamsBashforth4::~AdamsBashforth4()
{
    Delete_v(mWeight_ab);
}
