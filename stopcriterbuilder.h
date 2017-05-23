#ifndef STOPCRITERBUILDER_H
#define STOPCRITERBUILDER_H
#include "numericstopcriter.h"

class StopCriterBuilder
{
public:
    StopCriterBuilder();
    StopCriter *buildNumericStopCriter(double minimum, double maximum, double *value);
};

#endif // STOPCRITERBUILDER_H
