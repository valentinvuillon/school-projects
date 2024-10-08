#include "backward_differentiation_3.hh"
/* -------------------------------------------------------------------------- */


BackwardDifferentiation3::BackwardDifferentiation3()
{

    Allocate_v(mWeight_bd_y,3);
    mWeight_bd_y[0]=18.0/11.0;
    mWeight_bd_y[1]=-9.0/11.0;
    mWeight_bd_y[2]=2.0/11.0;

    mWeight_bd_f=6.0/11.0;

}

BackwardDifferentiation3::~BackwardDifferentiation3()
{
    Delete_v(mWeight_bd_y);
}

