#define _CRT_SECURE_NO_WARNINGS 1
#include "my_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define M 11
#define N 15
#include "maze.h"
void ScanMaze(int maze[M + 2][N + 2])
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int result = scanf("%d", &maze[i][j]);
            if (result == EOF)
            {
                return;
            }
        }
    }
}
void PrintMaze(int maze[M + 2][N + 2], STACK* s)
{
    system("cls");
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k <= s->top; k++)
            {
                if (i == s->element[k].x && j == s->element[k].y)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);//红色
                    break;
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//白色
                }
            }
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void MouseMove(int maze[M + 2][N + 2], STACK* s, int mark[M + 2][N + 2])
{
    int i;
    for (i = 1; i <= 8; i++)
    {
        Posision p = Switch(i, top(*s));
        if (p.x < 0 || p.x > M + 2 || p.y < 0 || p.y > N + 2)
        {
            continue;
        }
        else if (mark[p.x][p.y] == 1)
        {
            continue;
        }
        else if (maze[p.x][p.y] == 1)
        {
            mark[p.x][p.y] = 1;
            continue;
        }
        else
        {
            mark[p.x][p.y] = 1;
            push(p, s);
            return;
        }
    }
    pop(s);
    return;
}
int GameOver(Posision p)
{
    if (p.x == M && p.y == N)
    {
        return 1;
    }
    return 0;
}
Posision Switch(int n, Posision p)
{
    switch (n)
    {
    case 1:
        p.y += 1;
        return p;
        break;
    case 2:
        p.x += 1;
        return p;
        break;
    case 3:
        p.y -= 1;
        return p;
        break;
    case 4:
        p.x -= 1;
        return p;
        break;
    case 5:
        p.x -= 1;
        p.y += 1;
        return p;
        break;
    case 6:
        p.x += 1;
        p.y += 1;
        return p;
        break;
    case 7:
        p.x -= 1;
        p.y -= 1;
        return p;
        break;
    case 8:
        p.x += 1;
        p.y -= 1;
        return p;
        break;
    default:
        printf("Error!");
        break;
    }
    return p;
}
//本格：maze[i][j]
//东：  maze[i][j + 1]
//南：  maze[i + 1][j]
//西：  maze[i][j - 1]
//北：  maze[i - 1][j]
//东北：maze[i - 1][j + 1]
//东南：maze[i + 1][j + 1]
//西北：maze[i - 1][j - 1]
//西南：maze[i + 1][j - 1]


