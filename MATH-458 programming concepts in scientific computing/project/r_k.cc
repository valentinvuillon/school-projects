#include "r_k.hh"
/* -------------------------------------------------------------------------- */


Eigen::MatrixXd RK::GenerateK(Function *f, DataOut t_y, int It, double Delta_t, int ChosenStage, int Dimension) // dimension, je pourrais le recupérer avec DataOut en vrai !
{
    Eigen::MatrixXd K(Dimension, ChosenStage);
    K.col(0) = (*f).evaluate(t_y.Gett()[It-1], t_y.Gety().col(It-1));

    if (ChosenStage > 1)
    {
        for (int i = 1; i < ChosenStage ; ++i)
        {
            Eigen::VectorXd Sum(Dimension);
            Sum.setZero();
            for (int j = 0; j < i ; ++j)
            {
                Sum+= K.col(j)*mWeight_a[i-1][j];
            }

            K.col(i)=(*f).evaluate(t_y.Gett()[It-1]+mWeight_c[i]*Delta_t,t_y.Gety().col(It-1) + Sum*Delta_t);
        }
    }
    return K;
}

/* --------------------------------------------------------------------------- */

void RK::Integrate(DataOut &t_y, int It, double Delta_t,Function *f, int ChosenStage, int Dimension)
{
    Eigen::MatrixXd K = GenerateK(f, t_y, It, Delta_t, ChosenStage, Dimension);
    Eigen::VectorXd Sum_b_k (Dimension);
    Sum_b_k.setZero();
    for (int i = 0; i < ChosenStage; ++i) 
    {
        Sum_b_k+= mWeight_b[i]*K.col(i);
    }

    Eigen::VectorXd yNew = t_y.Gety().col(It-1) + Delta_t*Sum_b_k;
    double tNew = It*Delta_t + t_y.Gett()[0];

    t_y.Sett(It,tNew);
    t_y.Sety_i(It,yNew);


}


/* --------------------------------------------------------------------------- */


