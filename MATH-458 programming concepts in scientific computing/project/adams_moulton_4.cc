#include "adams_moulton_4.hh"
/* -------------------------------------------------------------------------- */

AdamsMoulton4::AdamsMoulton4()
{

    Allocate_v(mWeight_am_f,4);
    mWeight_am_f[0]=9.0/24.0;
    mWeight_am_f[1]=19.0/24.0;
    mWeight_am_f[2]=-5.0/24.0;
    mWeight_am_f[3]=1.0/24.0;

}

AdamsMoulton4::~AdamsMoulton4()
{
    Delete_v(mWeight_am_f);
}
