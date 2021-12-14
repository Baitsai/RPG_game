#include <iostream>
#include <cmath>
#include "monsterGoblin.h"
using namespace std;

monsterGoblin::monsterGoblin(string s, int i1, int i2, int i3, int i4, int i5)
    : money(30), monsterBase("Goblin", 60, 40, 12, 100, 50){};

void monsterGoblin::setLevel(int i)
{
    level = i;
    max_hp = 100 + 25 * level;
    max_mp = 50 + 10 * level;
    attack = 60 + 10 * level;
    defense = 40 + 12 * level;
    setExp(10);
    setHp(max_hp);
    setMp(max_mp);
};
