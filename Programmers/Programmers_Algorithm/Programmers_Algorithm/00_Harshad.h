#pragma once
#include "Useful.h"

bool solution0(int x)
{
    return (x % AddAllDigit(x) == 0);
}