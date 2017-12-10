#ifndef POLYNOMIALMUTATION_H
#define POLYNOMIALMUTATION_H
#include "realmutation.h"

class PolynomialMutation : public RealMutation
{
protected:
    double U;
    double L;
    double nm;
    double d;
public:
    PolynomialMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, double U, double L, double nm);
    ~PolynomialMutation();
    void mutation(const uint &gene);
    double dl();
    double dr();
    double getU() const;
    void setU(double value);
    double getL() const;
    void setL(double value);
    double getNm() const;
    void setNm(double value);
};

#endif // POLYNOMIALMUTATION_H
