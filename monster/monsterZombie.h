#ifndef MONSTERZOMBIE_H
#define MONSTERZOMBIE_H
#include <iostream>
#include "monsterBase.h"
using namespace std;

class monsterZombie : public monsterBase
{
public:
    monsterZombie(string, int, int, const int, int, int); // default
    virtual void setLevel(int);
    const int money;
};
#endif