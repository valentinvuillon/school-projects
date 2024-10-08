#ifndef __TEXT_READER__HH__
#define __TEXT_READER__HH__

/* -------------------------------------------------------------------------- */
#include <string>
#include "reader.hh"

//A class which allows to read input from text files

class TextReader: public Reader{

public:

    TextReader(std::string path_){
        path=path_;
    }


    //A method which allows to read input from text files. path is the path of the text file.
    DataIn Read() override;

    //the path of the text file to read
    std::string path;

};

/* -------------------------------------------------------------------------- */
#endif //__TEXT_READER__HH__
