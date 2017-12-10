#include "valuerbuilder.h"

ValuerBuilder::ValuerBuilder()
{

}

ValuerBuilder::~ValuerBuilder()
{

}

Valuer *ValuerBuilder::buildValuer(uint *evaluations, Function *function, PROGRAMATION programation, uint threadsNumber, Population *population)
{
    Valuer *val = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        val =  new ParallelValuer(evaluations, function, population, threadsNumber, VALUER::Fitness);
        break;
    case PROGRAMATION::Sequential:
        val = new Valuer(evaluations, function, population);
        break;
    }
    return val;
}

Valuer *ValuerBuilder::buildPenaltyValuer(uint *evaluations, Function *function, PROGRAMATION programation, uint threadsNumber, Population *population, std::vector<PenaltyFunction *> *penality)
{
    Valuer *val = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        val =  new ParallelValuer(evaluations, function, population, threadsNumber, VALUER::WithPenalty, penality);
        break;
    case PROGRAMATION::Sequential:
        val = new PenaltyValuer(evaluations, function, population, penality);
        break;
    }
    return val;
}
