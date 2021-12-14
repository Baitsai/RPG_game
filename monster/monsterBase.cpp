#include <iostream>
#include <cmath>
#include "monsterBase.h"
using namespace std;

monsterBase::monsterBase(string s, int i1, int i2, int i3, int i4, int i5)
{
    name = s;
    attack = i1;
    defense = i2;
    exp = i3;
    max_hp = i4;
    max_mp = i5;
    setHp(max_hp);
    setMp(max_mp);
};

void monsterBase::setName(string s)
{
    name = s;
};

string monsterBase::getName() const
{
    return name;
};

void monsterBase::setLevel(int i)
{
    level = i;
    max_hp = 100 + 10 * level;
    max_mp = 40 + 5 * level;
    attack = 20 + 5 * level;
    defense = 20 + 5 * level;
};

int monsterBase::getLevel(void) const
{
    return level;
};

void monsterBase::setHp(int i)
{
    hp = i;
};

int monsterBase::getHp(void) const
{
    return hp;
};

void monsterBase::setMp(int i)
{
    mp = i;
};

int monsterBase::getMp(void) const
{
    return mp;
};

void monsterBase::setExp(int i)
{
    exp = i;
};

int monsterBase::getExp(void) const
{
    return exp;
};

void monsterBase::printBeAtt(int hurt)
{
    if ((defense - hurt) > 0)
    {
        defense = defense - hurt;
        cout << "\n\n[怪獸" << getName() << "]受到傷害，防禦力下降" << hurt;
        cout << "\nHp值：" << getHp();
        cout << "\tMp值：" << getMp();
        cout << "\t攻擊力：" << attack;
        cout << "\n防禦力：" << defense;
        cout << "\t經驗值：" << getExp();
    }
    else
    {
        setHp(getHp() - hurt + defense);
        defense = 0;
        cout << "\n\n[怪獸" << getName() << "]無法招架了！Hp值下降" << hurt;
        cout << "\nHp值：" << getHp();
        cout << "\tMp值：" << getMp();
        cout << "\t攻擊力：" << attack;
        cout << "\n防禦力：" << defense;
        cout << "\t經驗值：" << getExp();
    }
}

void monsterBase::print()
{
    cout << getName() << "(等級" << getLevel() << ")";
    cout << "\nHp值：" << getHp();
    cout << "\tMp值：" << getMp();
    cout << "\t攻擊力：" << attack;
    cout << "\n防禦力：" << defense;
    cout << "\t經驗值：" << getExp();
};
