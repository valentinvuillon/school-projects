#ifndef __WRITER__HH__
#define __WRITER__HH__

/* -------------------------------------------------------------------------- */

#include "data_out.hh"

//A class which takes the raw result of the computations from the object DataOut
//and produces an output out of it; writing the result in a text file, in a terminal for instance

class Writer{

public:

    //The method used to write the content of the object DataOut
    virtual void write(DataOut DataOut_)=0;

};

/* -------------------------------------------------------------------------- */
#endif //__WRITER__HH__
