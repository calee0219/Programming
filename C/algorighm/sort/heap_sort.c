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
void print_tri(int* arr, int len);

int main()
{
    //int a[15] = {1, 2, 12, 6, 234, 2, 254, 44, 21, 2, 4767, 1, 8, 10, 66};
    int a[63];
    int i;
    for(i = 0; i < 63; ++i)
        a[i] = i;
    heap_sort(a, 63);
    print_tri(a, 63);
    return 0;
}

void heap_sort(int* arr, int len)
{
    //heapify(arr, len/2-1, len);
    return;
}

void heapify(int* ptr, int now, int last)
{
    if(now == last || now < 0)
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

void print_tri(int* arr, int len)
{
    int layer = 0;
    while(len)
    {
        len >>= 1;
        layer++;
    }
    int ord = 0;
    int i;
    for(i = 0; i < layer; ++i)
    {
        int k;
        for(k = 0; k < pow(2, layer-i-2)-1; ++k)
            printf("  ");
        int j;
        for(j = 0; j < pow(2, i); ++j)
        {
            if(i != layer-1)
                printf(" /");
            for(k = 0; k < pow(2, layer-i-2)-1; ++k)
                printf("--");
            printf("%02d", arr[ord]);
            ord++;
            for(k = 0; k < pow(2, layer-i-2)-1; ++k)
                printf("--");
            if(i != layer-1)
                printf("\\ ");
            else
                printf("  ");
            for(k = 0; k < pow(2, layer-i-1)-1; ++k)
                printf("  ");
        }
        printf("\n");
    }
    return;
}

