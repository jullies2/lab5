#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int *create()
{
    int i=0;
	int *arr = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
    	arr[i] = rand() % 100 - 50;

	return arr;
}

int zsqr(int *arr)
{
    int i=0;
    int sum=0;
    int k=-51;
	for (i = 0; i < N; i++)
        	if (arr[i] >= k && arr[i]<0)
            	k=arr[i];
    for (i=0;i<N;i++){
        if(arr[i]==k){
            sum=sum+k;
        }
    }
    //printf("%d",sum);
    return sum;
}

void print(int *arr)
{
    int i=0;
	for (i = 0; i < N; i++)
        printf("%d  ",arr[i]);
        	
}
