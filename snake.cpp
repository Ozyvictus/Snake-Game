#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
// #include <unistd.h>
using namespace std;

int row = 20 / 2;
int column = 40 / 2;

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
                cout << " ";
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

int main()
{
    int i;
    while (1)
    {
        draw();
        system("cls");
        // usleep(1000);
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'x':
                return 0;
                break;
            case 'w':
                row--;
                break;
            case 'a':
                column--;
                break;
            case 's':
                row++;
                break;
            case 'd':
                column++;
                break;
            }
        }
    }
    return 0;
}