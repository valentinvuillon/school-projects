#include "r_k_3.hh"
/* -------------------------------------------------------------------------- */

//Constructor
RK3::RK3()
{
    //Allocate memory for vectors c and b and matrix a
    Allocate_M(mWeight_a,2,2);
    Allocate_v(mWeight_b,3);
    Allocate_v(mWeight_c,3);

    mWeight_a[0][0]=1.0/3.0;
    mWeight_a[0][1]=0.0;
    mWeight_a[1][0]=0.0;
    mWeight_a[1][1]=2.0/3.0;

    mWeight_b[0]=1.0/4.0;
    mWeight_b[1]=0.0;
    mWeight_b[2]=3.0/4.0;

    mWeight_c[0]=0.0;
    mWeight_c[1]=1.0/3.0;
    mWeight_c[2]=2.0/3.0;
}

// Destructor
RK3::~RK3()
{
    Delete_M(mWeight_a,2);
    Delete_v(mWeight_b);
    Delete_v(mWeight_c);

}