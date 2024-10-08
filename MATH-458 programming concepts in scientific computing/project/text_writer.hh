#ifndef __TEXT_WRITER__HH__
#define __TEXT_WRITER__HH__

/* -------------------------------------------------------------------------- */
#include "writer.hh"

//A type of writer which writes the results in the object DataOut in a text file.

class TextWriter: public Writer{

public:

    //The method which need to be called to write the content of the object DataOut in a text file
    void write(DataOut DataOut_) override;

};

/* -------------------------------------------------------------------------- */
#endif //__TEXT_WRITER__HH__
