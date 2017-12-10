#include "mutationbuilder.h"

MutationBuilder::MutationBuilder()
{

}

MutationBuilder::~MutationBuilder()
{

}

GeneticOperator *MutationBuilder::buildMultipleBoundaryMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::Boundary, MUTATIONMODE::Multiple);
        break;
    case PROGRAMATION::Sequential:
        mut = new MultipleBoundaryMutation(rate, generation, individualConstraint);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildMultipleHeuristicMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, Valuer *valuer, NumericConstraint<uint> *attemptsConstraint, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::Heuristic, MUTATIONMODE::Multiple, new GeneticOperatorParameter{valuer}, new GeneticOperatorParameter{attemptsConstraint});
        break;
    case PROGRAMATION::Sequential:
        mut = new MultipleHeuristicMutation(rate, generation, individualConstraint, valuer, attemptsConstraint);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildMultipleNonUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, NumericConstraint<uint> *iterationsConstraint, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::NonUniform, MUTATIONMODE::Multiple, new GeneticOperatorParameter{iterationsConstraint});
        break;
    case PROGRAMATION::Sequential:
        mut = new MultipleNonUniformMutation(rate, generation, individualConstraint, iterationsConstraint);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildMultiplePolynomialMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, double U, double L, double nm, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::Polynomial, MUTATIONMODE::Multiple);
        break;
    case PROGRAMATION::Sequential:
        mut = new MultiplePolynomialMutation(rate, generation, individualConstraint, U, L, nm);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildMultipleUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::Uniform, MUTATIONMODE::Multiple);
        break;
    case PROGRAMATION::Sequential:
        mut = new MultipleUniformMutation(rate, generation, individualConstraint);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildUnaryBoundaryMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::Boundary, MUTATIONMODE::Unary);
        break;
    case PROGRAMATION::Sequential:
        mut = new UnaryBoundaryMutation(rate, generation, individualConstraint);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildUnaryHeuristicMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, Valuer *valuer, NumericConstraint<uint> *attemptsConstraint, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::Heuristic, MUTATIONMODE::Unary, new GeneticOperatorParameter{valuer}, new GeneticOperatorParameter{attemptsConstraint});
        break;
    case PROGRAMATION::Sequential:
        mut = new UnaryHeuristicMutation(rate, generation, individualConstraint, valuer, attemptsConstraint);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildUnaryNonUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, NumericConstraint<uint> *iterationsConstraint, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::NonUniform, MUTATIONMODE::Unary, new GeneticOperatorParameter{iterationsConstraint});
        break;
    case PROGRAMATION::Sequential:
        mut = new UnaryNonUniformMutation(rate, generation, individualConstraint, iterationsConstraint);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildUnaryPolynomialMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, double U, double L, double nm, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::Polynomial, MUTATIONMODE::Unary);
        break;
    case PROGRAMATION::Sequential:
        mut = new UnaryPolynomialMutation(rate, generation, individualConstraint, U, L, nm);
        break;
    }
    return mut;
}

GeneticOperator *MutationBuilder::buildUnaryUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *mut = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        mut = new ParallelMutation(rate, generation, individualConstraint, threadsNumber, CODIFICATION::Real, MUTATION::Uniform, MUTATIONMODE::Unary);
        break;
    case PROGRAMATION::Sequential:
        mut = new UnaryUniformMutation(rate, generation, individualConstraint);
        break;
    }
    return mut;
}
