#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int row = 20 / 2;
int column = 40 / 2;
int rows[10] = {row, row, row, row, row, row, row, row, row, row};
int cols[10] = {column, 19, 18, 17, 16, 15, 14, 13, 12, 11};
bool body = false;
int decoy = 2409;
enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

Direction dir = RIGHT;

void draw()
{
    for (int i = 1; i <= 20; i++)
    {
        cout << "# ";
    }
    cout << endl;
    for (int i = 2; i <= 19; i++)
    {
        for (int j = 1; j <= 40; j++)
        {
            if (j == 1 || j == 40)
            {
                cout << "#";
            }
            else if (i == row && j == column)
            {
                cout << "0";
            }
            else
            {
                for (int k = 1; k < sizeof(rows) / sizeof(int); k++)
                {
                    if (i == rows[k] && j == cols[k])
                    {
                        cout << "0";
                        body = true;
                    }
                }
                if (body)
                {
                    body = false;
                    continue;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    for (int i = 1; i <= 20; i++)
    {
        cout << "# ";
    }
}

void logic()
{
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'x':
            dir = STOP;
            break;
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        }
    }
}

int main()
{
    int i;
    while (1)
    {
        Sleep(60);
        system("cls");
        draw();
        input();
        switch (dir)
        {
        case STOP:
            return 0;
            break;
        case UP:
            row--;
            break;
        case LEFT:
            column--;
            break;
        case DOWN:
            row++;
            break;
        case RIGHT:
            column++;
            break;
        }
        for (int i = (sizeof(rows) / 4) - 1; i >= 0; i--)
        {
            rows[i + 1] = rows[i];
            cols[i + 1] = cols[i];
        }
        rows[0] = row;
        cols[0] = column;
    }
    return 0;
}