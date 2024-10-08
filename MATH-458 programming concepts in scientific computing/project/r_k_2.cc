#include "r_k_2.hh"
/* -------------------------------------------------------------------------- */

// Constructor
RK2::RK2()
{
    //Allocate memory for vectors c and b and matrix a
    Allocate_M(mWeight_a,1,1);
    Allocate_v(mWeight_b,2);
    Allocate_v(mWeight_c,2);

    mWeight_a[0][0]=1.0/2.0;

    mWeight_b[0]=0.0;
    mWeight_b[1]=1.0;

    mWeight_c[0]=0.0;
    mWeight_c[0]=1.0/2.0;
}

// Destructor
RK2::~RK2()
{
    Delete_M(mWeight_a,1);
    Delete_v(mWeight_b);
    Delete_v(mWeight_c);

}