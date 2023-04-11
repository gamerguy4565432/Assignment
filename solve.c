#include <stdio.h>
#include <stdbool.h>
#include "solve.h"



// write your code here
// note that solve.h is included. Look at that file
// to see what values are already defined for you and
// what your function signatures should match. You do not
// need to copy anything from main.c or solve.h into this file.


void print_maze(char field[SIZE_Y][SIZE_X])
{
    int i;
    int j;

    for(i = 0; i < SIZE_Y; i++)
    {
        for(j = 0; j < SIZE_X;j++)
        {
            printf("%c", field[i][j]);

        }
        printf("\n");
    }

}
void solve_maze(char field[SIZE_Y][SIZE_X])
{
    bool changeY = true;
    
    int y = 1;
    int x;



    while(y < SIZE_Y -1)
    {
        for(x = 1;x < SIZE_X - 1;x++)
        {
            changeY = true;
            if(field[y][x] == 46)
            {
                if(field[y + 1][x] == 64 && field[y][x + 1] == 64 && field[y - 1][x] == 64)
                {
                    int i = x;
                    while(true)
                    {
                    if(field[y + 1][i] != 64 || field[y - 1][i] != 64)
                        break;
                    field[y][i] = 64;
                    i--;
                    }
                    changeY = false;

                }

                if(field[y + 1][x] == 64 && field[y][x - 1] == 64 && field[y - 1][x] == 64)
                {
                    int i = x;
                    while(true)
                    {
                    if(field[y + 1][i] != 64 || field[y - 1][i] != 64)
                        break;
                    field[y][i] = 64;
                    i++;
                    }
                    changeY = false;

                }

                if(field[y + 1][x] == 64 && field[y][x + 1] == 64 && field[y][x - 1] == 64)
                {
                    int i = y;
                    while(true)
                    {
                    if(field[i][x + 1] != 64 || field[i][x - 1] != 64)
                        break;
                    field[i][x] = 64;
                    i--;
                    }
                    changeY = false;

                }    

                if(field[y - 1][x] == 64 && field[y][x + 1] == 64 && field[y][x - 1] == 64)
                {
                    int i = y;
                    while(true)
                    {
                    if(field[i][x + 1] != 64 || field[i][x - 1] != 64)
                        break;
                    field[i][x] = 64;
                    i++;
                    }
                    changeY = false;

                }    
                    

                
            }
            
        }
        if(changeY)
            y++;
    }

    
}
