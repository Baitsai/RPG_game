#ifndef MONSTERKING_H
#define MONSTERKING_H
#include <iostream>
#include "monsterBase.h"
using namespace std;

class monsterKing : public monsterBase
{
public:
    monsterKing(string, int, int, int, int, int); // default
    virtual void setLevel(int);
    const int money;
};
#endif