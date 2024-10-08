#include "adams_moulton_2.hh"
/* -------------------------------------------------------------------------- */
AdamsMoulton2::AdamsMoulton2()
{

    Allocate_v(mWeight_am_f,2);
    mWeight_am_f[0]=1.0/2.0;
    mWeight_am_f[1]=1.0/2.0;


}

AdamsMoulton2::~AdamsMoulton2()
{
    Delete_v(mWeight_am_f);
}
