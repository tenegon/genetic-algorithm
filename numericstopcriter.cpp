#include "numericstopcriter.h"

NumericStopCriter::NumericStopCriter(NumericConstraint *numericConstraint): numericConstraint(numericConstraint)
{

}

bool NumericStopCriter::meets()
{
    return numericConstraint->isFeasible();
}
