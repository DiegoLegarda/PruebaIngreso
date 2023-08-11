#ifndef MODELO_H
#define MODELO_H
#include <iostream>
#include "matrices.h"
#include <vector>
#include <cmath>

class modelo{

static matriz jacobian(const std::vector<std::function<double(const std::vector<double>&)>>& funcs, const std::vector<double>& vars) {
        int numFunctions = funcs.size();
        int numVariables = vars.size();

        matriz result(numFunctions, numVariables);

};

#endif // MODELO_H