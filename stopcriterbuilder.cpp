#include "stopcriterbuilder.h"

StopCriterBuilder::StopCriterBuilder()
{

}

StopCriter *StopCriterBuilder::buildNumericStopCriter(double minimum, double maximum, double *value)
{
    return new NumericStopCriter(new NumericConstraint(minimum, maximum, value));
}
