#include "reader.hh"
/* -------------------------------------------------------------------------- */

void Reader::Print_Input() {
    std::cout<<"function_f_choice: "<<function_f_choice<<std::endl;
    std::cout<<"integration interval: "<<Interval[0]<<"  "<<Interval[1]<<std::endl;
    std::cout<<"Dimension: "<<Dimension<<std::endl;
    std::cout<<"initial condition: "<< "\n" <<InitialCondition<<std::endl;
    std::cout<<"Integration method: "<<IntegrationMethod<<std::endl;
    std::cout<<"step: "<<Step<<std::endl;
    std::cout<<"dt: "<<dt<<std::endl;

}



