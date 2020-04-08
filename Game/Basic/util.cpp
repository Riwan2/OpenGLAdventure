#include "util.h"

void Util::InitRandom() {
    srand(time(NULL));
}

int Util::getInt(const int& nbValue)
{
    return rand() % nbValue;
}

