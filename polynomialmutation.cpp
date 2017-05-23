#include "polynomialmutation.h"

PolynomialMutation::PolynomialMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, double U, double L, double nm): RealMutation(rate, generation, realIndividualConstraint), U(U), L(L), nm(nm)
{
    //L = individual size
    //U = ?
    //nm [20, 100]
    nm = r() * (100.0f - 20.0f) + 20.0f;
}

void PolynomialMutation::mutation(const uint &gene)
{
    double minGene = realIndividualConstraint->getMinimum()->getGene(gene);
    double maxGene = realIndividualConstraint->getMaximum()->getGene(gene);
    double p = mutant->getGene(gene);
    d = std::min(maxGene - p, p - minGene)/(maxGene - minGene);
    if(r() <= 0.5f){
        mutantGene = p + dl() * (maxGene - minGene);
    }
    else{
        mutantGene = p + dr() * (maxGene - minGene);
    }
}

double PolynomialMutation::dl()
{
    //return  pow(2.0f * r(), (1.0f/double(1.0f + nm))) - 1.0f;
    double u = r();
    return pow(pow(2.0f * u + (1.0f - 2.0f * u) * (1.0f - d), nm + 1.0f), 1.0f / (nm + 1.0f)) - 1.0f;
}

double PolynomialMutation::dr()
{
    //return 1.0f - pow(2.0f * (1.0f - r()), (1.0f/double(1.0f + nm)));
    double u = r();
    return 1.0f - pow(pow(2.0f * (1.0f - u) + 2.0f * (u - 0.5f) * (1.0f - d), nm + 1.0f), 1.0f / (nm + 1.0f));
}

double PolynomialMutation::getU() const
{
    return U;
}

void PolynomialMutation::setU(double value)
{
    U = value;
}

double PolynomialMutation::getL() const
{
    return L;
}

void PolynomialMutation::setL(double value)
{
    L = value;
}

double PolynomialMutation::getNm() const
{
    return nm;
}

void PolynomialMutation::setNm(double value)
{
    nm = value;
}
