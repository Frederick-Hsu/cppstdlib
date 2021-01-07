#include "Curious.h"

#include <stdlib.h>
#include <time.h>
#include <random>

const int Curious::c1;
const int Curious::c4 = myrandom(17);
const float Curious::c5 = 7.0;

int myrandom(int x)
{
    srand(time(NULL));
    return ((x * 10000) % rand());
}

Curious::Curious() : ptr(&c1)
{
}