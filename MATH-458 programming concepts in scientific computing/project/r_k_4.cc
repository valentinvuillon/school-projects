#include "r_k_4.hh"
/* -------------------------------------------------------------------------- */

//Constructor
RK4::RK4()
{
    //Allocate memory for vectors c and b and matrix a
    Allocate_M(mWeight_a,3,3);
    Allocate_v(mWeight_b,4);
    Allocate_v(mWeight_c,4);

    mWeight_a[0][0]=1.0/2.0;
    mWeight_a[0][1]=0.0;
    mWeight_a[0][2]=0.0;
    mWeight_a[1][0]=0.0;
    mWeight_a[1][1]=1.0/2.0;
    mWeight_a[1][2]=0.0;
    mWeight_a[2][0]=0.0;
    mWeight_a[2][1]=0.0;
    mWeight_a[2][2]=1.0;

    mWeight_b[0]=1.0/6.0;
    mWeight_b[1]=1.0/3.0;
    mWeight_b[2]=1.0/3.0;
    mWeight_b[3]=1.0/6.0;

    mWeight_c[0]=0.0;
    mWeight_c[1]=1.0/2.0;
    mWeight_c[2]=1.0/2.0;
    mWeight_c[3]=1.0;
}

// Destructor
RK4::~RK4()
{
    Delete_M(mWeight_a,3);
    Delete_v(mWeight_b);
    Delete_v(mWeight_c);

}