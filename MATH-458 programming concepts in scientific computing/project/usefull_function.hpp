//
// Created by ismael gomes on 06.11.23.
//
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------Useful methods for vectors and matrices---------------------------------------------
//---------------------------------------------------------------------------------------------------------------------


#ifndef PROJECTODE_USEFULL_FUNCTION_HPP
#define PROJECTODE_USEFULL_FUNCTION_HPP

#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>

void Allocate_M(double** &M, int n_row, int n_col);

//Allocate memory for vectors of n_comp (Must to use the function delete_v when we finish the application)
void Allocate_v(double* &v, int n_comp);

// Delete memory allocate of Matrices of size n_row x n_col
void Delete_M (double** &M, int n_row);

// Delete memory allocate of vectors of n_comp
void Delete_v (double *&v);

// print matrices in the monitor
void Print_M(double **M, int n_row, int n_col);

// print vectors in the monitor
void Print_v(double *v, int n_comp);

#endif //PROJECTODE_USEFULL_FUNCTION_HPP
