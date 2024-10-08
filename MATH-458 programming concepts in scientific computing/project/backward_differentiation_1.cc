#include "backward_differentiation_1.hh"
/* -------------------------------------------------------------------------- */

BackwardDifferentiation1::BackwardDifferentiation1()
{

    Allocate_v(mWeight_bd_y,1);
    mWeight_bd_y[0]=1.0;

    mWeight_bd_f=1.0;


}

BackwardDifferentiation1::~BackwardDifferentiation1()
{
    Delete_v(mWeight_bd_y);

}

