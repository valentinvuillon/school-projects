#include "backward_differentiation_2.hh"
/* -------------------------------------------------------------------------- */

BackwardDifferentiation2::BackwardDifferentiation2()
{

    Allocate_v(mWeight_bd_y,2);
    mWeight_bd_y[0]=4.0/3.0;
    mWeight_bd_y[1]=-1.0/3.0;

    mWeight_bd_f=2.0/3.0;

}

BackwardDifferentiation2::~BackwardDifferentiation2()
{
    Delete_v(mWeight_bd_y);
}
