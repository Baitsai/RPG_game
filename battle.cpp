#include <iostream>
#include "monster/monsterBase.cpp"
#include "monster/monsterGoblin.cpp"
#include "monster/monsterKing.cpp"
#include "monster/monsterZombie.cpp"
#include "player/playerBase.cpp"
#include "player/playerKnight.cpp"
#include "player/playerMagician.cpp"
#include "player/playerOrc.cpp"
#include <ctime>
using namespace std;

template <typename T>
bool battle(int mstr, T *player, int level, vector<T *> partner)
{
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    int prtrAlive = 0;
    if (mstr == 300)
    {
        player->getHp();
        monsterZombie mon("Zombie", 50, 65, 17, 150, 30);
        mon.setLevel(level);
        cout << "遇到殭屍Zombie (Hp值:" << mon.getHp() << " Mp值:" << mon.getMp()
             << " 攻擊力:" << mon.attack << " 防禦力:" << mon.defense << ")！ " << endl;
        int finish = 0;
        int count = -1;
        while (finish == 0)
        {
            if (player->getHp() > 0)
            {
                do
                {
                    cout << "\n[" << player->getName() << "]發動攻擊👊" << endl;
                    player->print();
                    mon.printBeAtt(player->attack);
                    cout << "\n\n按Enter繼續...\n";
                } while (cin.get() != '\n');
                if (player->getHp() > 0)
                {
                    do
                    {
                        cout << "\n[" << mon.getName() << "]發動攻擊🧟" << endl;
                        mon.print();
                        player->printBeAtt(mon.attack);
                        cout << "\n\n按Enter繼續...\n";
                    } while (cin.get() != '\n');
                }
            }
            for (size_t i = 0; i < partner.size(); i++)
            {
                if (partner[i]->getHp() > 0)
                {
                    prtrAlive = 1;
                    cout << "\n[" << partner[i]->getName() << "]發動攻擊" << endl;
                    partner[i]->print();
                    do
                    {
                        mon.printBeAtt(partner[i]->attack);
                    } while (cin.get() != '\n');
                }
                if (partner[i]->getHp() > 0)
                {
                    do
                    {
                        cout << "\n[" << mon.getName() << "]發動攻擊🧟" << endl;
                        mon.print();
                        partner[i]->printBeAtt(mon.attack);
                        cout << "\n\n按Enter繼續...\n";
                    } while (cin.get() != '\n');
                }
            }

            if (mon.getHp() <= 0)
            {
                finish = 1;
                player->setExp(player->getExp() + mon.getExp());
                return true;
            }
            else if (player->getHp() < 0 && prtrAlive == 0)
            {
                return false;
            }
        }
        return true;
    }
    else if (mstr == 301)
    {

        monsterGoblin mon("Goblin", 60, 40, 12, 100, 50);
        mon.setLevel(level);
        cout << "遇到哥布林Goblin (Hp值:" << mon.getHp() << " Mp值:" << mon.getMp()
             << " 攻擊力:" << mon.attack << " 防禦力:" << mon.defense << ")！ " << endl;
        int finish = 0;
        int count = -1;
        while (finish == 0)
        {
            if (player->getHp() > 0)
            {
                do
                {
                    cout << "\n[" << player->getName() << "]發動攻擊👊" << endl;
                    player->print();
                    mon.printBeAtt(player->attack);
                    cout << "\n\n按Enter繼續...\n";
                } while (cin.get() != '\n');
                if (player->getHp() > 0)
                {
                    do
                    {
                        cout << "\n[" << mon.getName() << "]發動攻擊🧟" << endl;
                        mon.print();
                        player->printBeAtt(mon.attack);
                        cout << "\n\n按Enter繼續...\n";
                    } while (cin.get() != '\n');
                }
            }
            for (size_t i = 0; i < partner.size(); i++)
            {
                if (partner[i]->getHp() > 0)
                {
                    prtrAlive = 1;
                    cout << "\n[" << partner[i]->getName() << "]發動攻擊" << endl;
                    partner[i]->print();
                    do
                    {
                        mon.printBeAtt(partner[i]->attack);
                    } while (cin.get() != '\n');
                }
                if (partner[i]->getHp() > 0)
                {
                    do
                    {
                        cout << "\n[" << mon.getName() << "]發動攻擊🧟" << endl;
                        mon.print();
                        partner[i]->printBeAtt(mon.attack);
                        cout << "\n\n按Enter繼續...\n";
                    } while (cin.get() != '\n');
                }
            }

            if (mon.getHp() <= 0)
            {
                finish = 1;
                player->setExp(player->getExp() + mon.getExp());
                return true;
            }
            else if (player->getHp() < 0 && prtrAlive == 0)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        monsterKing mon("King", 120, 100, 42, 250, 100);
        mon.setLevel(level);
        cout << "遇到大魔王King (Hp值:" << mon.getHp() << " Mp值:" << mon.getMp()
             << " 攻擊力:" << mon.attack << " 防禦力:" << mon.defense << ")！ " << endl;
        int finish = 0;
        int count = -1;
        while (finish == 0)
        {
            if (player->getHp() > 0)
            {
                do
                {
                    cout << "\n[" << player->getName() << "]發動攻擊👊" << endl;
                    player->print();
                    mon.printBeAtt(player->attack);
                    cout << "\n\n按Enter繼續...\n";
                } while (cin.get() != '\n');
                if (player->getHp() > 0)
                {
                    do
                    {
                        cout << "\n[" << mon.getName() << "]發動攻擊🧟" << endl;
                        mon.print();
                        player->printBeAtt(mon.attack);
                        cout << "\n\n按Enter繼續...\n";
                    } while (cin.get() != '\n');
                }
            }
            for (size_t i = 0; i < partner.size(); i++)
            {
                if (partner[i]->getHp() > 0)
                {
                    prtrAlive = 1;
                    cout << "\n[" << partner[i]->getName() << "]發動攻擊" << endl;
                    partner[i]->print();
                    do
                    {
                        mon.printBeAtt(partner[i]->attack);
                    } while (cin.get() != '\n');
                }
                if (partner[i]->getHp() > 0)
                {
                    do
                    {
                        cout << "\n[" << mon.getName() << "]發動攻擊🧟" << endl;
                        mon.print();
                        partner[i]->printBeAtt(mon.attack);
                        cout << "\n\n按Enter繼續...\n";
                    } while (cin.get() != '\n');
                }
            }

            if (mon.getHp() <= 0)
            {
                finish = 1;
                player->setExp(player->getExp() + mon.getExp());
                return true;
            }
            else if (player->getHp() < 0 && prtrAlive == 0)
            {
                return false;
            }
        }
        return true;
    }
}