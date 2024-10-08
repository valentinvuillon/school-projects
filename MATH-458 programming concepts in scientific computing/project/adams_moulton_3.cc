#include "adams_moulton_3.hh"
/* -------------------------------------------------------------------------- */

AdamsMoulton3::AdamsMoulton3()
{

    Allocate_v(mWeight_am_f,3);
    mWeight_am_f[0]=5.0/12.0;
    mWeight_am_f[1]=+8.0/12.0;
    mWeight_am_f[2]=-1.0/12.0;

}

AdamsMoulton3::~AdamsMoulton3()
{
    Delete_v(mWeight_am_f);
}
