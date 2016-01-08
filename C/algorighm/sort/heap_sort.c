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

void heap_sort(int* arr, int len);
void heapify(int* ptr, int now, int last);
void swap(int* i, int* j);

int main()
{
    int a[17] = {1, 4, 2, 3, 2, 12, 6, 234, 2, 254356, 44, 21, 2, 456767, 1, 8, 10};
    heap_sort(a, 17);
    int i;
    for(i = 0; i < pow(17, 1/2); ++i)
    {
        int j;
        for(j = 0; j < pow(2, i); ++j)
            printf("%d ", a[j]);
        printf("\n");
    }
    return 0;
}

void heap_sort(int* arr, int len)
{
    heapify(arr, len/2, len);
    return;
}

void heapify(int* ptr, int now, int last)
{
    if(now == last)
        return;
    if(ptr[now] > ptr[now/2] && ptr[now] > ptr[now/2+1])
        heapify(ptr, now-1, last);
    else
    {
        int max = (ptr[now/2] > ptr[now/2+1]) ? now/2 : now/2+1;
        swap(&ptr[now], &ptr[max]); 
        if(max < last/2)
            heapify(ptr, max, last);
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

