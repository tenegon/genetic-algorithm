#include "valuerbuilder.h"

ValuerBuilder::ValuerBuilder()
{

}

Valuer *ValuerBuilder::build(uint *evaluations, Function *function)
{
    return new Valuer(evaluations, function);
}
