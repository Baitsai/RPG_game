#ifndef MONSTERGOBLIN_H
#define MONSTERGOBLIN_H
#include <iostream>
#include "monsterBase.h"
using namespace std;

class monsterGoblin : public monsterBase
{
public:
    monsterGoblin(string, int, int, int, int, int); // default
    virtual void setLevel(int);
    const int money; // amount of money dropped after beating this monster
};
#endif
