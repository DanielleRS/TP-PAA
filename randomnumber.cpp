#include <cstdlib>
#include <climits>
#include <time.h>
#include <unistd.h>

#include "randomnumber.h"

RandomNumber::RandomNumber()
{
  srand(time(nullptr));

  this->superiorLimit = UINT_MAX;
}

RandomNumber::RandomNumber(unsigned int superiorLimit)
{
  srand(time(nullptr));

  this->superiorLimit = superiorLimit;
}

unsigned int RandomNumber::generate()
{
  return rand() % this->superiorLimit;
}
