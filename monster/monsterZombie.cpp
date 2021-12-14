#include <iostream>
#include "monsterZombie.h"
using namespace std;

monsterZombie::monsterZombie(string s, int i1, int i2, int i3, int i4, int i5)
    : money(65), monsterBase("Zombie", 50, 65, 17, 150, 30){};

void monsterZombie::setLevel(int i)
{
    level = i;
    max_hp = 150 + 25 * level;
    max_mp = 30 + 10 * level;
    attack = 50 + 10 * level;
    defense = 65 + 12 * level;
    setExp(17);
    setHp(max_hp);
    setMp(max_mp);
};
