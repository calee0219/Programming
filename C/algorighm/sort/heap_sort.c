/*************************************************************************
	> File Name: heap_sort.c
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月07日 (週四) 18時49分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void heapify(int* ptr, int now, int last);
void swap(int* i, int* j);

int main(int argc, char* artv[])
{
    return 0;
}

void heapify(int* ptr, int now, int last)
{
    if(now == last)
        return;
    if(ptr[now] > ptr[now/2] && ptr[now] > ptr[now/2+1])
        heapify(ptr, now-1, last);
    else
    {
        swap(&ptr[now], (ptr[now/2] > ptr[now/2+1]) ? &ptr[now/2]:&ptr[now/2+1] ); 
    }
    return;
}

void swap(int* i, int* j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
    return;
}

