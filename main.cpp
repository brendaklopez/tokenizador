#include <iostream>
#include "AlphabetTestSuite.h"
#include "OcurrenceCounterTestSuite.h"

int main()
{
    AlphabetTestSuite::RunAlphabetTestSuite();
    OcurrenceCounterTestSuite::RunOcurrenceCounterTestSuite();

    return 0;
}

