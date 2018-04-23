//
// Created by Austin Clyde on 4/6/18.
//

#ifndef CS28515PROJ1_PDESOLVER_H
#define CS28515PROJ1_PDESOLVER_H

#include "numvec.h"
#include "tridiag.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iterator>

TriDiag generateStiffnessMatrixMidpoint(std::function<double(double)> k, int N, double dx, double x_0);
TriDiag generateMassMatrixMidpoint(std::function<double(double)> d, int N, double dx, double x_0);
TriDiag linearizeDF(NumVec U, NumVec F, double x_i, double dx, double t_i, double dt);
NumVec linearizeF(NumVec U, double x_i, double dx, double t_i, double dt);
void solveMassStiff(std::function<double(double)> k, std::function<double(double)> c, double x_0,
                    double x_nx,
                    int nx,
                    int nt,
                    double tmax,
                    std::function<double(double)> init);

void solveHeatEquation1d(double x_0,
                         double x_nx,
                         int nx,
                         int nt,
                         double tmax,
                         double alpha,
                         std::function<double(double)> init);
void solveHeatEquation1dStepDoubling(double x_0,
                                     double x_nx,
                                     int nx,
                                     int nt,
                                     double tmax,
                                     double alpha,
                                     std::function<double(double)> init);

double simpson_integration(std::function<double(double)> f, double a, double b, int n_intervals);
void writeParams(std::string name, std::vector<std::string> params);
void writeUpdateStep(std::string name, NumVec a);

#endif //CS28515PROJ1_PDESOLVER_H