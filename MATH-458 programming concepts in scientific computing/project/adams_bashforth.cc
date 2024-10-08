#include "adams_bashforth.hh"
#include "r_k_4.hh"
/* -------------------------------------------------------------------------- */

void AdamsBashforth::Integrate(DataOut &t_y, int It, double Delta_t,Function *f, int ChosenStage, int Dimension)
{
    if (It<ChosenStage)
    {
        //Calcul of the very firsts iterations with Runge Kutta of Order 4 methods
        RK4 first_iterations;
        first_iterations.TotalIntegrate(t_y,ChosenStage,Delta_t,f,4, Dimension);
    }
    else // It>= ChosenStage
    {
        Eigen::VectorXd Sum_f_b(Dimension);
        Sum_f_b.setZero();
        for (int i = 1; i < ChosenStage+1; ++i)
        {
            Sum_f_b+= mWeight_ab[i-1]*f->evaluate(t_y.Gett()[It-i], t_y.Gety().col(It-i));
        }
        Eigen::VectorXd yNew = t_y.Gety().col(It-1)+Delta_t*Sum_f_b;
        double tNew = It*Delta_t + t_y.Gett()[0];

        t_y.Sett(It,tNew);
        t_y.Sety_i(It,yNew);
    }
}

/* --------------------------------------------------------------------------- */


