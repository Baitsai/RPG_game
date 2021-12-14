#ifndef MAZE_H
#define MAZE_H
#include <string>
#include "../player/playerBase.h"
using namespace std;

class maze
{
private:
    int row, col;
    int **map;
    int x, y; // for move
    int level;

public:
    maze(const string &, int);
    void bonusPoint();
    void monsterPoint();
    void print();
    int move(char, playerBase *, vector<playerBase *>);
    ~maze()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] map[i];
        }
        delete[] map;
        cout << "destructor!" << endl;
    };
};

#endif