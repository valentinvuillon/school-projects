#include "backward_differentiation_4.hh"
/* -------------------------------------------------------------------------- */



BackwardDifferentiation4::BackwardDifferentiation4()
{

    Allocate_v(mWeight_bd_y,4);
    mWeight_bd_y[0]=48.0/25.0;
    mWeight_bd_y[1]=-36.0/25.0;
    mWeight_bd_y[2]=16.0/25.0;
    mWeight_bd_y[3]=-3.0/25.0;

    mWeight_bd_f=12.0/25.0;

}

BackwardDifferentiation4::~BackwardDifferentiation4()
{
    Delete_v(mWeight_bd_y);
}
