#ifndef MUTATIONBUILDER_H
#define MUTATIONBUILDER_H
#include "multipleboundarymutation.h"
#include "multipleheuristicmutation.h"
#include "multiplenonuniformmutation.h"
#include "multiplepolynomialmutation.h"
#include "multipleuniformmutation.h"
#include "unaryboundarymutation.h"
#include "unaryheuristicmutation.h"
#include "unarynonuniformmutation.h"
#include "unarypolynomialmutation.h"
#include "unaryuniformmutation.h"
#include "parallelmutation.h"

class MutationBuilder
{
public:
    MutationBuilder();
    ~MutationBuilder();
    GeneticOperator *buildMultipleBoundaryMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator *buildMultipleHeuristicMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, Valuer *valuer, NumericConstraint<uint> *attemptsConstraint, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator *buildMultipleNonUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, NumericConstraint<uint> *iterationsConstraint, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator  *buildMultiplePolynomialMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, double U, double L, double nm, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator  *buildMultipleUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator  *buildUnaryBoundaryMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator  *buildUnaryHeuristicMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, Valuer *valuer, NumericConstraint<uint> *attemptsConstraint, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator  *buildUnaryNonUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, NumericConstraint<uint> *iterationsConstraint, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator  *buildUnaryPolynomialMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, double U, double L, double nm, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator  *buildUnaryUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
};

#endif // MUTATIONBUILDER_H
