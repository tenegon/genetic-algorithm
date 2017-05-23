#ifndef FUNCTIONBUILDER_H
#define FUNCTIONBUILDER_H
#include "dixonpricefunction.h"
#include "griewankfuntion.h"
#include "levyfunction.h"
#include "michaelewiczfunction.h"
#include "rastriginfunction.h"
#include "rosenbrockfunction.h"
#include "zakharovfunction.h"

class FunctionBuilder
{
public:
    FunctionBuilder();
    DixonPriceFunction *buildDixonPriceFunction();
    GriewankFuntion *buildGriewankFuntion();
    LevyFunction *buildLevyFunction();
    MichaelewiczFunction *buildMichaelewiczFunction();
    RastriginFunction *buildRastriginFunction();
    RosenbrockFunction *buildRosenbrockFunction();
    ZakharovFunction *buildZakharovFunction();
};

#endif // FUNCTIONBUILDER_H
