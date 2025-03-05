/*
01  02  03  04     (0,0) (0,1) (0,2) (0,3)

12  13  14  05     (1,0) (1,1) (1,2) (1,3)

11  16  15  06     (2,0) (2,1) (2,2) (2,3)

10  09  08  07     (3,0) (3,1) (3,2) (3,3)
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>

void SpiralMatrix(int size, int Matrix[size][size]);

void PrintMatrix(int size, int Matrix[size][size]);
void InitMatrix(int size, int Matrix[size][size]);

void main()
{
    int size;

    printf("Enter Size: ");
    scanf("%d", &size);

    int Matrix[size][size];

    InitMatrix(size, Matrix);
    SpiralMatrix(size, Matrix);
    
}

void InitMatrix(int size, int Matrix[size][size]) 
{

    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {    
            Matrix[i][j] = 0;
        }
    }
    
}

void PrintMatrix(int size, int Matrix[size][size])
{

    system("clear");
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {    
            if(Matrix[i][j] == 0)
                printf("    ");
            else
                printf(" %02d ", Matrix[i][j]);
        }
        printf("\n\n");
    }

}

void SpiralMatrix(int size, int Matrix[size][size])
{

    int top = 0, bottom = size - 1, left = 0, right = size - 1;
    int direction = 0, value = 1;

    while(left <= right && top <= bottom)
    {
        if(direction == 0)
        {
            for(int i = left ; i <= right ; i++)
            {
                Matrix[top][i] = value++;
                PrintMatrix(size, Matrix);
                sleep(1);
            }
            top++;
        }

        else if(direction == 1)
        {
            for(int j = top ; j <= bottom ; j++)
            {
                Matrix[j][right] = value++;
                PrintMatrix(size, Matrix);
                sleep(1);
            }
            right--;
        }

        else if(direction == 2)
        {
            for(int x = right ; x >= left ; x--)
            {
                Matrix[bottom][x] = value++;
                PrintMatrix(size, Matrix);
                sleep(1);
            }
           bottom--;
        }

        else
        {
            for(int y = bottom ; y >= top ; y--)
            {
                Matrix[y][left] = value++;
                PrintMatrix(size, Matrix);
                sleep(1);
            }
            left++;
        }
        
        direction = (direction+1) % 4;
        
        
    }

}