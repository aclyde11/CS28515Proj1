//
// Created by Austin Clyde on 4/4/18.
//

#ifndef CS28515PROJ1_TRIDIAG_H
#define CS28515PROJ1_TRIDIAG_H

#include <cstdlib>
#include <iostream>
#include <vector>

#include "utility.h"
#include "numvec.h"

class TriDiag {

 public:
  int dim;
  NumVec a;
  NumVec d;
  NumVec b;

  TriDiag();
  TriDiag(int n);
  TriDiag(int n, double p);
  TriDiag(const TriDiag &A);

  double &operator()(int i, int j);
  double operator()(int i, int j) const;
  bool operator==(const TriDiag &B);
  TriDiag operator+(const TriDiag &B); // A+B
  NumVec operator*(const NumVec &v);
  TriDiag operator-(const TriDiag &B);
  void map(std::function<double(double)> func);

  double det();
  void randomize();
  void randomize(int start, int end);
  void randomizeReals(double start, double end);

 private:
  double det_f(int i);
  TriDiag binary(const TriDiag &B, std::function<double(double, double)> func);
};

TriDiag operator*(double a, const TriDiag &B); // a*B#
std::ostream &operator<<(std::ostream &os, const TriDiag A);

NumVec solveTriDiagMatrix(const TriDiag &A, const NumVec &d);


#endif //CS28515PROJ1_TRIDIAG_H
