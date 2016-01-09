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

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int n;
char check[100000] = {0};
int now_red = -1;

void heap_sort(int* arr, int len);
void heapify(int* ptr, int now, int last);
void swap(int* ptr, int i, int j, int col);
void print_tri(int col, int* arr, int len, int col_1, int col_2);
void sub_heapify(int* ptr, int now, int last);
void max_heap(int* ptr, int len);

int main()
{
    srand(time(NULL));
    int a[63];
    n = 63; //rand() % 64;
    int i;
    for(i = 0; i < n; ++i)
        a[i] = rand() % 100;
    system("clear");
    print_tri(0, a, n, 0, 0);
    heap_sort(a, n);
    print_tri(0, a, n, 0, 0);
    for(i = 0; i < n; ++i)
        printf("->%d", a[i]);
    return 0;
}

void heap_sort(int* arr, int len)
{
    heapify(arr, len/2-1, len);
    max_heap(arr, len);
    return;
}

void heapify(int* ptr, int now, int last)
{
    if(now >= last/2 || now < 0)
        return;
    sub_heapify(ptr, now, last);
    heapify(ptr, now-1, last);
    return;
}

void sub_heapify(int* ptr, int now, int last)
{
    if(now*2+2 < last && !(ptr[now] >= ptr[now*2+1] && ptr[now] >= ptr[now*2+2]))
    {
        int max = (ptr[now*2+1] > ptr[now*2+2]) ? now*2+1 : now*2+2;
        swap(ptr, now, max, 1); 
        if(max < last/2)
            sub_heapify(ptr, max, last);
    }
    else if(now*2+1 < last && ptr[now] < ptr[now*2+1])
    {
        swap(ptr, now, now*2+1, 1);
        if(now*2+1 < last/2)
            sub_heapify(ptr, now*2+1, last);
    }
    return;
}

void max_heap(int* ptr, int len)
{
    if(len <= 1)
        return;
    swap(ptr, 0, len-1, 2);
    sub_heapify(ptr, 0, len-1);
    max_heap(ptr, len-1);
    return;
}

void swap(int* ptr, int i, int j, int col)
{
    int tmp = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = tmp;
    print_tri(col, ptr, n, i, j);
    return;
}

void print_tri(int col, int* arr, int len, int col_1, int col_2)
{
    system("clear");
    int layer = 0;
    int tmp = len;
    while(tmp)
    {
        tmp >>= 1;
        layer++;
    }
    int cl = 1;
    int i;
    for(i = 0; i < len; ++i)
    {
        int tmp = arr[i];
        int l = 0;
        while(tmp)
        {
            tmp /= 10;
            l++;
        }
        if(l > cl)
            cl = l;
    }
    int ord = 0;
    int tmp_lay;
    for(tmp_lay = 0; tmp_lay < layer; ++tmp_lay)
    {
        int j, k;
        for(j = 0; j < pow(2, layer-tmp_lay-2)-1; ++j)
            for(k = 0; k < cl; ++k)
                printf(" ");
        for(i = 0; i < pow(2, tmp_lay); ++i)
        {
            if(tmp_lay < layer-1)
            {
                if(ord*2+1 < len)
                {
                    for(k = 0; k < cl-1; ++k)
                        printf(" ");
                    printf("/");
                }
                else
                    for(k = 0; k < cl; ++k)
                        printf(" ");
            }
            for(j = 0; j < pow(2, layer-tmp_lay-2)-1; ++j)
                for(k = 0; k < cl; ++k)
                    printf("-");
            if(ord == col_1 || ord == col_2)
            {
                switch(col) {
                case 0:
                    printf("%s%0*d", KNRM, cl, arr[ord]);
                    break;
                case 1:
                    printf("%s%0*d", KGRN, cl, arr[ord]);
                    break;
                case 2:
                    printf("%s%0*d", KBLU, cl, arr[ord]);
                    check[col_2] = 1;
                    now_red = col_2;
                    break;
                default:
                    printf("%s%0*d", KNRM, cl, arr[ord]);
                }
            }
            else if(ord == now_red)
                printf("%s%0*d", KRED, cl, arr[ord]);
            else if(check[ord])
            {
                printf("%s%0*d", KYEL, cl, arr[ord]);
            }
            else
                printf("%s%0*d", KNRM, cl, arr[ord]);
            printf("%s", KNRM);
            for(j = 0; j < pow(2, layer-tmp_lay-2)-1; ++j)
                for(k = 0; k < cl; ++k)
                    printf("-");
            if(tmp_lay < layer-1 && ord*2+2 < len)
            {
                printf("\\");
                for(k = 0; k < cl-1; ++k)
                    printf(" ");
            }
            else
                for(k = 0; k < cl; ++k)
                    printf(" ");
            ord++;
            if(ord >= pow(2, tmp_lay+1)-1 || ord >= len)
                break;
            for(j = 0; j < pow(2, layer-tmp_lay-1)-1; ++j)
                for(k = 0; k < cl; ++k)
                    printf(" ");
        }
        printf("\n");
    }
    system("sleep 0.05");
    return;
}

