//
// Created by igomes on 06.11.23.
//
/*
//-------------------List of useful methods for vectors and matrices ----------------
//-------------------------------------------------------------
 * <--- Description of the program goes here.
 *
 * 	   Author: Ismaël Gomes <ismael.gomesalmadaguillemin@epfl.ch>
 */

/*
 * Any headers you need to include should be specified on the next lines
 */

#include <iostream>
#include <cassert>
#include <cmath>

#include "usefull_function.hpp"
//Allocate memory for matrices
void Allocate_M(double** &M, int n_row, int n_col)
{
    M = new double* [n_row];
    for (int i = 0; i < n_row; ++i)
    {
        M[i] = new double [n_col];
    }
}

//Allocate memory for vectors
void Allocate_v(double* &v, int n_comp)
{
    v= new double [n_comp];
}


// Delete memory allocate of Matrices
void Delete_M (double** &M, int n_row)
{
    for (int i = 0; i < n_row; ++i)
    {
        delete[] M[i];
    }
    delete M;
}

// Delete memory allocate of Matrices
void Delete_v (double *&v)
{
    delete[] v;
}

// print matrices
void Print_M(double **M, int n_row, int n_col)
{
    for (int i = 0; i < n_row; ++i)
    {
        for (int j = 0; j < n_col; ++j)
        {
            std::cout<< M[i][j]<<" ";
        }
        std::cout << std::endl;

    }
}

// print vectors
void Print_v(double *v, int n_comp)
{
    for (int j = 0; j < n_comp; ++j)
    {
        std::cout<< v[j] << std::endl;
    }
}
