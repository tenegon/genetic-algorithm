#include "parallelcrossover.h"

ParallelCrossover::ParallelCrossover(double rate, Generation *generation, IndividualConstraint *individualConstraint, uint threadsNumber, CODIFICATION codification, CROSSOVER crossover, GeneticOperatorParameter *geneticOperatorParameter): Parallel<GeneticOperator>(threadsNumber), GeneticOperator(rate, generation), codification(codification), crossover(crossover)
{
    CrossoverBuilder *crossoverBuilder = new CrossoverBuilder();
    uint u = generation->getChilds()->getT();
    for(uint i = 0, begin = 0, end = 0; end < u - 1; i++){
        begin = (i * (u / threadsNumber));
        end = std::min(u - 1, ((i + 1) * (u / threadsNumber) - 1));
        GeneticOperator *go = 0;
        switch (codification) {
        case CODIFICATION::Boolean:
            go = 0;
            break;
        case CODIFICATION::Hybrid:
            go = 0;
            break;
        case CODIFICATION::Integer:
            go = 0;
            break;
        case CODIFICATION::Real:
            switch (crossover) {
            case CROSSOVER::Arithmetic:
                go = crossoverBuilder->buildArithmeticCrossover(rate, generation, individualConstraint);
                break;
            case CROSSOVER::Blx:
                go = crossoverBuilder->buildBlxCrossover(rate, generation, individualConstraint, geneticOperatorParameter->numericConstraint);
                break;
            case CROSSOVER::Geometric:
                go = crossoverBuilder->buildGeometricCrossover(rate, generation, individualConstraint);
                break;
            case CROSSOVER::Mean:
                go = 0;
                break;
            case CROSSOVER::Linear:
                go = crossoverBuilder->buildLinearCrossover(rate, generation, individualConstraint, geneticOperatorParameter->valuer);
                break;
            case CROSSOVER::Sbx:
                go = crossoverBuilder->buildSbxCrossover(rate, generation, individualConstraint);
                break;
            }
            break;
        }
        go->setRange(begin, end);
        tasks->push_back(go);
        threads->push_back(new std::thread);
    }
    delete crossoverBuilder;
}

ParallelCrossover::~ParallelCrossover()
{

}

void ParallelCrossover::apply()
{
    for(uint i = 0; i < threads->size(); i++){
        GeneticOperator *go = tasks->at(i);
        RealCrossover *cgo = dynamic_cast<RealCrossover*>(go);
        delete threads->at(i);
        threads->at(i) = new std::thread(&RealCrossover::apply, cgo);
    }
    Parallel<GeneticOperator>::execute();
}

void ParallelCrossover::print(std::ostream &os) const
{
    Parallel<GeneticOperator>::print(os);
    os << " " << *tasks->front();
}
