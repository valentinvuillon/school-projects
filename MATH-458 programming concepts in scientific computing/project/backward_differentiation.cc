#include "backward_differentiation.hh"
#include "r_k_4.hh"
#include "Newton.hh"
/* -------------------------------------------------------------------------- */

void BackwardDifferentiation::Integrate(DataOut &t_y, int It, double Delta_t, Function *f, int ChosenStage, int Dimension){
    if (It<ChosenStage)
    {
        //calcul des première itération avec RK4
        RK4 first_iterations;
        first_iterations.TotalIntegrate(t_y,ChosenStage,Delta_t,f,4,Dimension);
    }
    else
    {
        double A=mWeight_bd_f*Delta_t;
        double B=0;


        for (int i = 1; i < ChosenStage+1; ++i)
        {
            B+= mWeight_bd_y[i-1]*t_y.Gety()(0,It-i);
        }

        double tNew = t_y.Gett()[0]+It*Delta_t;

        Eigen::VectorXd yNew(Dimension);
        yNew(0)= Newton(A, B, f, t_y.Gety()(0,It-1), tNew);



        t_y.Sett(It,tNew);
        t_y.Sety_i(It,yNew);
    }
}



/* --------------------------------------------------------------------------- */
