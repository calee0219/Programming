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
    srand(time(NULL));
    int a[63];
    int n = rand() % 64;
    printf("%d\n", n);
    int i;
    for(i = 0; i < n; ++i)
        a[i] = rand() % 100;
    print_tri(a, n);
    heap_sort(a, n);
    print_tri(a, n);
    return 0;
}

void heap_sort(int* arr, int len)
{
    heapify(arr, len/2-1, len);
    return;
}

void heapify(int* ptr, int now, int last)
{
    if(now >= last/2 || now < 0)
        return;
    if(!(ptr[now] > ptr[now*2+1] && ptr[now] > ptr[now*2+2]))
    {
        int max = (now*2+2 < last) ? (ptr[now*2+1] > ptr[now*2+2]) ? now*2+1 : now*2+2 : now*2+1;
        swap(&ptr[now], &ptr[max]); 
        if(max < last/2)
            heapify(ptr, max, last);
    }
    heapify(ptr, now-1, last);
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
    int tmp = len;
    while(tmp)
    {
        tmp >>= 1;
        layer++;
    }
    int ord = 0;
    int tmp_lay;
    for(tmp_lay = 0; tmp_lay < layer; ++tmp_lay)
    {
        int k;
        for(k = 0; k < pow(2, layer-tmp_lay-2)-1; ++k)
            printf("  ");
        int j;
        for(j = 0; j < pow(2, tmp_lay); ++j)
        {
            if(tmp_lay < layer-1)
            {
                if(ord*2+1 < len)
                    printf(" /");
                else
                    printf("  ");
            }
            for(k = 0; k < pow(2, layer-tmp_lay-2)-1; ++k)
                printf("--");
            printf("%02d", arr[ord]);
            for(k = 0; k < pow(2, layer-tmp_lay-2)-1; ++k)
                printf("--");
            if(tmp_lay < layer-1 && ord*2+2 < len)
                printf("\\ ");
            else
                printf("  ");
            ord++;
            if(ord >= pow(2, tmp_lay+1)-1 || ord >= len)
                break;
            for(k = 0; k < pow(2, layer-tmp_lay-1)-1; ++k)
                printf("  ");
        }
        printf("\n");
    }
    return;
}

