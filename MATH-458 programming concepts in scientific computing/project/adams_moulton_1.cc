#include "adams_moulton_1.hh"
/* -------------------------------------------------------------------------- */

AdamsMoulton1::AdamsMoulton1()
{

    Allocate_v(mWeight_am_f,1);
    mWeight_am_f[0]=1.0;

}

AdamsMoulton1::~AdamsMoulton1()
{
    Delete_v(mWeight_am_f);
}
