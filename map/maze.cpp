#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include "maze.h"
#include "../battle.cpp"
using namespace std;

maze::maze(const string &filename, int l)
{
    level = l;
    ifstream ifs(filename, ios::in);
    string str, str1;

    //讀取檔案第一行
    getline(ifs, str);
    str1 = str.substr(0, str.find_first_of(','));
    col = std::__1::stoi(str1);
    str1 = str.substr(str.find_first_of(',') + 1, str.size());
    row = stoi(str1);

    //分配空間
    map = new int *[row];
    for (int i = 0; i < row; i++)
    {
        map[i] = new int[col];
    }

    //繼續讀取地圖 放進二維陣列
    int indexRow = 0;
    int indexCol = 0;
    string p;
    while (getline(ifs, str))
    {
        char *line = (char *)str.c_str();
        while (*line != '\0')
        {
            if (*line == '0' || *line == '1')
            {
                map[indexRow][indexCol++] = *line - '0';
                line++;
            }
            else if (*line == '2')
            {
                p = p + *line + (*(line + 1)) + (*(line + 2));
                line = line + 3;
                map[indexRow][indexCol++] = stoi(p);
                //設定起點
                if (map[indexRow][indexCol - 1] == 200)
                {
                    x = indexRow;
                    y = indexCol - 1;
                }
            }
            else //*line==','
                line++;
        }
        p.clear();
        indexRow++;
        indexCol = 0;
    }
    bonusPoint();
    monsterPoint();
};

void maze::print()
{
    cout << endl;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (map[i][j] == 1)
            {
                cout << "⚘"
                     << "\t";
            }
            else if (map[i][j] == 3 || map[i][j] == 2 || map[i][j] == 0)
            {
                cout << " "
                     << "\t";
            }
            else if (map[i][j] == 200)
            {
                cout << "Start"
                     << "\t";
            }
            else if (map[i][j] == 201)
            {
                cout << "Exit"
                     << "\t";
            }
            else if (map[i][j] > 201 && map[i][j] < 300)
            {
                cout << "⭐︎"
                     << "\t";
            }
            else if (map[i][j] == 300)
            {
                cout << "🧟"
                     << "\t";
            }
            else if (map[i][j] == 301)
            {
                cout << "👾"
                     << "\t";
            }
            else if (map[i][j] == 302)
            {
                cout << "😈"
                     << "\t";
            }
            else if (map[i][j] < 0)
            {
                cout << "🧙"
                     << "\t";
            }
            else
                cout << map[i][j] << "\t";
        }
        cout << endl;
    }
}

//隨機產生bonus點數量以及座標
void maze::bonusPoint()
{
    srand(time(0));
    int boCount = rand() % (3) + 1;
    int boX, boY;

    for (size_t i = 0; i < boCount; i++)
    {
        do
        {
            boX = rand() % (col);
            boY = rand() % (row);
        } while (map[boY][boX] != 0);

        //因為終點是201 所以bonus從202開始
        map[boY][boX] = 202 + i;
    }
}

//隨機產生monster點座標
void maze::monsterPoint()
{
    srand(time(0));
    int moX, moY, mo;
    int count = level * 2 + 1;
    for (size_t i = 0; i < count; i++)
    {
        do
        {
            moX = rand() % (col);
            moY = rand() % (row);
        } while (map[moY][moX] != 0);
        int t = rand() % 2;
        if (t == 1)
        {
            map[moY][moX] = 300;
        }
        else if (t == 2)
        {
            map[moY][moX] = 301;
        }
        else
        {
            map[moY][moX] = 302;
        }
    }
}

int maze::move(char m, playerBase *player, vector<playerBase *> partner)
{
    int count = level * 2 + 1;
    if (m == 'w' || m == 'W')
    {
        if (map[x - 1][y] == 1 || map[x - 1][y] == 201)
        {
            print();
            return map[x][y];
        }
        else if (map[x - 1][y] >= 300)
        {
            if (battle(map[x - 1][y], player, level, partner))
            {
                map[x][y] = 0;
                map[--x][y] = -1;
                print();
            };
        }
        else
        {
            map[x][y] = 0;
            map[--x][y] = -1;

            print();
        }
    }
    else if (m == 's' || m == 'S')
    {
        if (map[x + 1][y] == 1 || map[x + 1][y] == 201)
        {
            if (map[x + 1][y] == 201)
            {
                return map[x + 1][y];
            }

            print();
            return map[x][y];
        }
        else if (map[x + 1][y] >= 300)
        {
            if (battle(map[x + 1][y], player, level, partner))
            {
                map[x][y] = 0;
                map[++x][y] = -1;
                print();
            }
        }
        else
        {

            map[x][y] = 0;
            map[++x][y] = -1;
            print();
        }
    }
    else if (m == 'a' || m == 'A')
    {
        if (map[x][y - 1] == 1 || map[x][y - 1] == 201)
        {
            if (map[x][y - 1] == 201)
            {
                return map[x][y - 1];
            }

            print();
            return map[x][y];
        }
        else if (map[x][y - 1] >= 300)
        {
            if (battle(map[x][y - 1], player, level, partner))
            {
                map[x][y] = 0;
                map[x][--y] = -1;
                print();
            }
        }
        else
        {
            map[x][y] = 0;
            map[x][--y] = -1;
            print();
        }
    }
    else if (m == 'd' || m == 'D')
    {
        if (map[x][y + 1] == 1 || map[x][y + 1] == 201)
        {
            if (map[x][y + 1] == 201)
            {
                return map[x][y + 1];
            }

            print();
            return map[x][y];
        }
        else if (map[x][y + 1] >= 300)
        {
            if (battle(map[x][y + 1], player, level, partner))
            {
                map[x][y] = 0;
                map[x][++y] = -1;
                print();
            }
        }
        else
        {
            map[x][y] = 0;
            map[x][++y] = -1;
            print();
        }
    }

    return map[x][y];
}