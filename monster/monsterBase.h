#ifndef MONSTERBASE_H
#define MONSTERBASE_H
#include <iostream>

using namespace std;

class monsterBase
{
public:
    monsterBase(string, int, int, int, int, int); // default
    void setName(string);
    string getName(void) const;
    virtual void setLevel(int);
    int getLevel(void) const;
    void setHp(int);
    int getHp(void) const;
    void setMp(int);
    int getMp(void) const;
    void setExp(int);
    int getExp(void) const;
    void printBeAtt(int);
    void print(void);
    int attack;  // attack of the monster
    int defense; // defense of the monster
private:
    string name; // name of the monster
    int hp;      // current HP of the monster,range:[0,max_hp]
    int mp;      // current MP of the monster,range:[0,max_mp]
    int exp;     // experience earned by the player after beating this monster

protected:
    int level; // the level of the monster, >=1

    int max_hp; // max HP of the monster
    int max_mp; // max MP of the monster
};
#endif