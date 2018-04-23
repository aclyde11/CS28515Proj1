#include <iostream>
#include "tridiag.h"
#include "parabolicsolver.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
#include <ctime>
#include <string>

#define PI 3.141592653

int main() {
  std::function<double(double)> f = [](double x) { return 0; };
  std::function<double(double)> one = [](double x) { return 1; };
  std::function<double(double)> zero = [](double x) { return 0; };
  std::function<double(double)> negOne = [](double x) { return -1; };
  std::function<double(double)> id = [](double x) { return x; };

  // c(x)u_t - k(x)u_xx + f(x,u)=0
  /*
  TriDiag M = generateMassMatrixMidpoint(zero, 5, 0.25, 0); //c(x)
  std::cout << "mass: " << std::endl << M << std::endl;

  TriDiag S = generateStiffnessMatrixMidpoint(one, 5, 0.25, 0); //k(x)
  std::cout << "stiff: " << std::endl << S << std::endl;
  */

  double x_0 = 0;
  double x_nx = 1;
  double L = (x_nx - x_0);
  int nx = 15;
  int nt = 1000;
  double tmax = 0.5;

  std::function<double(double)> init;

  init = [L](double x) -> double {
    return sin(PI * x / L);
  };

  /*init = [](double x) -> double {
    return 1;
  };*/

  //k, c
  solveMassStiff(one, one, x_0, x_nx, nx, nt, tmax, init);

  return 0;
}