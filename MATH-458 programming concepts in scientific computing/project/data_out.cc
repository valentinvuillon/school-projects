#include "data_out.hh"
/* -------------------------------------------------------------------------- */

DataOut::DataOut(int Nnodes, Eigen::VectorXd y0, double InitialTime, int Dimension){
    //double IntervalLength = Interval[1]-Interval[0];
    //double Nnodes= IntervalLength/Delta_t +1.0; je pense qu'il faudrait dans le constructeur dmd le nbr de noeud et non pas la taille du h, car sinon il peut avoir soucis si le n*h est différent de Interval
    t.resize(Nnodes);
    y.resize(Dimension,Nnodes);
    t[0]= InitialTime;
    y.col(0) = y0;

}

/* -------------------------------------------------------------------------- */

std::vector<double> DataOut::Gett(){

    return t;
}



/* --------------------------------------------------------------------------- */

Eigen::MatrixXd DataOut::Gety(){
    return y;
}



/* --------------------------------------------------------------------------- */


void DataOut::Sett(int Iteration, double tNext)
{
    t[Iteration] =tNext;
}


/* --------------------------------------------------------------------------- */

void DataOut::Sety_i(int Iteration,  Eigen::VectorXd y_iNext) //changer  le nom pourêtre cohérent avex le reste , soit ici, soit en haut avec les get !
{
    y.col(Iteration) = y_iNext;
}


/* --------------------------------------------------------------------------- */
// faut changer les fonctions mtn et implémenter explicite !