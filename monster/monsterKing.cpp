#include <iostream>
#include "monsterKing.h"
using namespace std;

monsterKing::monsterKing(string s, int i1, int i2, int i3, int i4, int i5)
    : money(175), monsterBase("King", 120, 100, 42, 250, 100){};

void monsterKing::setLevel(int i)
{
    level = i;
    max_hp = 250 + 25 * level;
    max_mp = 100 + 10 * level;
    attack = 120 + 10 * level;
    defense = 100 + 12 * level;
    setExp(42);
    setHp(max_hp);
    setMp(max_mp);
};
