#include "numericconstraint.h"

NumericConstraint::NumericConstraint(double minimum, double maximum, double *value): minimum(minimum), maximum(maximum), value(value)
{

}

bool NumericConstraint::isFeasible()
{
    return (minimum >= *value) && (maximum <= *value);
}

bool NumericConstraint::isFeasible(const double &value)
{
    return (minimum >= value) && (maximum <= value);
}

double NumericConstraint::getMinimum() const
{
    return minimum;
}

void NumericConstraint::setMinimum(double value)
{
    minimum = value;
}

double NumericConstraint::getMaximum() const
{
    return maximum;
}

void NumericConstraint::setMaximum(double value)
{
    maximum = value;
}
