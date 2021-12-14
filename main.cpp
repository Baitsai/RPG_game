#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include "start.cpp"
#include "map/maze.cpp"
using namespace std;

int main()
{
    playerBase *player;
    vector<playerBase *> partner;
    char s;
    cout << "是否回到上次地圖？(Y/N)";
    cin >> s;
    if (s == 'Y' || s == 'y')
    {
        player = start_unserialize(player);
    }
    else
    {
        //開局設定
        int c;
        string n;
        cout << "請輸入玩家名稱：";
        cin >> n;
        cout << "請選擇成為哪種角色(1.騎士 2.魔法師 3.獸人):";
        while (cin >> c)
        {
            if (c == 1)
            {
                player = start(1, 1, player, n, partner);
                break;
            }
            else if (c == 2)
            {
                player = start(2, 1, player, n, partner);
                break;
            }
            else if (c == 3)
            {
                player = start(3, 1, player, n, partner);
                break;
            }
            else
            {
                cout << "請再輸入一次：";
            }
        }
    }

    //遊戲開始
    int exit = 0;
    while (exit == 0)
    {
        //載入地圖
        maze *playerMap;
        int i = player->getLevel();

        if (i == 1)
        {
            playerMap = new maze("map/maze.txt", i);
        }
        else if (i == 2)
        {
            playerMap = new maze("map/maze2.txt", i);
        }
        else
        {
            playerMap = new maze("map/maze1.txt", i);
        }
        playerMap->print();
        char m;
        int finish;
        system("read");
        do
        {
            cin >> m;
            system("clear");
            finish = playerMap->move(m, player, partner);
        } while (finish != 201);

        cout << "你消滅了所有怪獸！！ 來看看升級後的能力吧" << endl;
        int levelUp = player->getLevel() + 1;
        cout << levelUp;
        player->setLevel(levelUp);

        //遊戲結束
        cout << "\n是否確定離開？(Y/N)";
        char c;
        cin >> c;
        if (c == 'Y' || 'y')
        {
            exit = 1;
        }
    }

    cout << "\n是否儲存此次戰績？(Y/N)";
    cin >> s;
    if (s == 'Y' || s == 'y')
    {
        player->serialize();
    }

    return 0;
}
