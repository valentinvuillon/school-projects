#include "integrator.hh"
/* -------------------------------------------------------------------------- */


void Integrator::TotalIntegrate(DataOut &t_y, int NbrNodes, double Delta_t, Function *f, int ChosenStage, int Dimension)
{
    for (int i = 1; i < NbrNodes; ++i)
    {
        Integrate(t_y, i, Delta_t, f, ChosenStage, Dimension);
    }
}