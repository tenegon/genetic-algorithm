#include "parallelmutation.h"

ParallelMutation::ParallelMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, uint threadsNumber, CODIFICATION codification, MUTATION mutation, MUTATIONMODE mode, GeneticOperatorParameter *gop1, GeneticOperatorParameter *gop2): Parallel<GeneticOperator>(threadsNumber), GeneticOperator(rate, generation), codification(codification), mutation(mutation), mode(mode)
{
    MutationBuilder *mutationBuilder = new MutationBuilder();
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
            switch (mutation) {
            case MUTATION::Boundary:
                if(mode == MUTATIONMODE::Multiple){
                    go = mutationBuilder->buildMultipleBoundaryMutation(rate, generation, individualConstraint);
                }
                else if(mode == MUTATIONMODE::Unary){
                    go = mutationBuilder->buildUnaryBoundaryMutation(rate, generation, individualConstraint);
                }
                break;
            case MUTATION::Heuristic:
                if(mode == MUTATIONMODE::Multiple){
                    go = mutationBuilder->buildMultipleHeuristicMutation(rate, generation, individualConstraint, gop1->valuer, gop2->numericConstraint);
                }
                else if(mode == MUTATIONMODE::Unary){
                    go = mutationBuilder->buildUnaryHeuristicMutation(rate, generation, individualConstraint, gop1->valuer, gop2->numericConstraint);
                }
                break;
            case MUTATION::NonUniform:
                if(mode == MUTATIONMODE::Multiple){
                    go = mutationBuilder->buildMultipleNonUniformMutation(rate, generation, individualConstraint, gop1->numericConstraint);
                }
                else if(mode == MUTATIONMODE::Unary){
                    go = mutationBuilder->buildUnaryNonUniformMutation(rate, generation, individualConstraint, gop1->numericConstraint);
                }
                break;
            case MUTATION::Polynomial:
                if(mode == MUTATIONMODE::Multiple){
                    go = mutationBuilder->buildMultiplePolynomialMutation(rate, generation, individualConstraint, 0.0, 0.0, 20.0);
                }
                else if(mode == MUTATIONMODE::Unary){
                    go = mutationBuilder->buildUnaryPolynomialMutation(rate, generation, individualConstraint, 0.0, 0.0, 20.0);
                }
                break;
            case MUTATION::Uniform:
                if(mode == MUTATIONMODE::Multiple){
                    go = mutationBuilder->buildMultipleUniformMutation(rate, generation, individualConstraint);
                }
                else if(mode == MUTATIONMODE::Unary){
                    go = mutationBuilder->buildUnaryUniformMutation(rate, generation, individualConstraint);
                }
                break;
            }
            break;
        }
        go->setRange(begin, end);
        tasks->push_back(go);
        threads->push_back(new std::thread);
    }
    delete mutationBuilder;
}

ParallelMutation::~ParallelMutation()
{

}

void ParallelMutation::apply()
{
    for(uint i = 0; i < threads->size(); i++){
        GeneticOperator *go = tasks->at(i);
        RealMutation *rgo = dynamic_cast<RealMutation*>(go);
        delete threads->at(i);
        threads->at(i) = new std::thread(&RealMutation::apply, rgo);
    }
    Parallel<GeneticOperator>::execute();
}

void ParallelMutation::print(std::ostream &os) const
{
    Parallel<GeneticOperator>::print(os);
    os << " " << *tasks->front();
}
