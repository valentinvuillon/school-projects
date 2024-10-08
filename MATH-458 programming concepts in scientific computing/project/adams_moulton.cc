#include "adams_moulton.hh"
#include "r_k_4.hh"
#include "Newton.hh"
/* -------------------------------------------------------------------------- */

void AdamsMoulton::Integrate(DataOut &t_y, int It, double Delta_t, Function *f, int ChosenStage, int Dimension){
    if (It<ChosenStage)
    {
        //calcul des première itération avec RK4
        RK4 first_iterations;
        first_iterations.TotalIntegrate(t_y,ChosenStage,Delta_t,f,4,Dimension);
    }
    else
    {
        double A=mWeight_am_f[0]*Delta_t;
        double B=t_y.Gety()(0,It-1);

        for (int i = 1; i < ChosenStage; ++i)
        {
            B+= Delta_t*mWeight_am_f[i]*f->evaluate(t_y.Gett()[It-i], t_y.Gety().col(It-i))(0);
        }

        double tNew = t_y.Gett()[0]+It*Delta_t;

        Eigen::VectorXd yNew(Dimension);
        yNew(0)= Newton(A, B, f, t_y.Gety()(0,It-1), tNew);



        t_y.Sett(It,tNew);
        t_y.Sety_i(It,yNew);
    }
}


/* --------------------------------------------------------------------------- */
