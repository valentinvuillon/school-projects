#include "data_in.hh"

/* -------------------------------------------------------------------------- */

DataIn::DataIn(Eigen::VectorXd InitialCondition_ , double Interval_[2], double dt_, std::string IntegrationMethod_, int Step_, Function* f_, int Dimension_){

    Interval[0]=Interval_[0];
    Interval[1]=Interval_[1];
    dt=dt_;
    IntegrationMethod=IntegrationMethod_;
    Step=Step_;
    f=f_;
    Dimension = Dimension_;
    InitialCondition =InitialCondition_;
    number_of_nodes=(Interval_[1]-Interval_[0])/dt_+1;

}



/* --------------------------------------------------------------------------- */

Eigen::VectorXd DataIn::GetInitialCondition(){
    return InitialCondition;
}



/* --------------------------------------------------------------------------- */

double DataIn::GetDt(){
    return dt;

}



/* --------------------------------------------------------------------------- */

Function* DataIn::GetFunction(){
    return f;
}



/* --------------------------------------------------------------------------- */

std::string DataIn::GetIntegrationMethod(){
    return IntegrationMethod;
}



/* --------------------------------------------------------------------------- */

int DataIn::GetStep(){
    return Step;
}



/* --------------------------------------------------------------------------- */

double* DataIn::GetInterval(){
    return Interval;
}



/* --------------------------------------------------------------------------- */

int DataIn::GetDimension(){
    return Dimension;
}



/* --------------------------------------------------------------------------- */

int DataIn::GetNumberNodes() {
    return number_of_nodes;

}




