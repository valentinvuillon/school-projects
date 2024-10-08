#ifndef __TERMINAL_READER__HH__
#define __TERMINAL_READER__HH__

/* -------------------------------------------------------------------------- */
#include "reader.hh"

class TerminalReader: public Reader{


public:

    DataIn Read() override;

};

/* -------------------------------------------------------------------------- */
#endif //__TERMINAL_READER__HH__
