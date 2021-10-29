#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int **create()
{
	int **arr = (int**) malloc(sizeof(int*) * ROW);
    int i=0;
    int j=0;
	for (i = 0; i < ROW; i++)
	{
    	*(arr + i) = (int *) malloc(sizeof(int) * COLUMN);
    	for (j = 0; j < COLUMN; j++)
        	arr[i][j] = rand() % 100 - 50;
	}
    
	return arr;
}

int zsqr(int **arr)
{
    int k=-51;
    int sum=0;
    int i=0,j=0;
	for (i = 0; i < ROW; i++)
    	for (j = 0; j < COLUMN; j++)
        	if (arr[i][j] < 0&&arr[i][j]>k)
            	k=arr[i][j];
                //arr[i][j] = k;
    for (i = 0; i < ROW; i++)
    	for (j = 0; j < COLUMN; j++)
        	if (arr[i][j] ==k)
            	sum+=k;
    return sum;
}

void print(int **arr)
{
    int i=0;
    int j=0;
	for (i = 0; i < ROW; i++)
	{
    	for (j = 0; j < COLUMN; j++)
        	printf("%d ", arr[i][j]);
    	putchar('\n');
	}
}

