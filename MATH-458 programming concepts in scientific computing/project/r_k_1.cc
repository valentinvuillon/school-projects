#include "r_k_1.hh"
/* -------------------------------------------------------------------------- */

//Constructor
RK1::RK1()
{
    //Allocate memory for vectors c and b and matrix a
    Allocate_M(mWeight_a,1,1);
    Allocate_v(mWeight_b,1);
    Allocate_v(mWeight_c,1);

    mWeight_a[0][0]=0.0;
    mWeight_b[0]=1.0;
    mWeight_c[0]=0.0;
}

// Destructor
RK1::~RK1()
{
    Delete_M(mWeight_a,1);
    Delete_v(mWeight_b);
    Delete_v(mWeight_c);

}