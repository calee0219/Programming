/*************************************************************************
	> File Name: shell_sort.c
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: Mon 11 Jan 2016 06:37:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

/* Colors */
#define KNRM	"\x1B[0m"
#define KRED	"\x1B[31m"
#define KGRN	"\x1B[32m"
#define KYEL	"\x1B[33m"
#define KBLU	"\x1B[34m"
#define KMAG	"\x1B[35m"
#define KCYN	"\x1B[36m"
#define KWHT	"\x1B[37m"
#define RESET	"\033[0m"
/* other */
#define MAX(x,y) ((x>y)?x:y)

int n;

void print_tri(int* arr, int len, int col_1, int col_2);
void shell_sort(int* ptr, int len);
void swap(int* ptr, int len, int i, int j);

int main()
{
    srand(time(NULL));
    int a[63];
    n = rand() % 32;//64;
    int i;
    for(i = 0; i < n; ++i)
        a[i] = rand() % 100;
    system("clear");
    shell_sort(a, n);
    print_tri(a, n, 0, 0);
    return 0;
}

void shell_sort(int* ptr, int len)
{
    int gap = len / 2;
    while(gap)
    {
        int i;
        for(i = gap; i < len; ++i)
        {
            int j;
            for(j = i-gap; j >= 0; j-=gap)
            {
                if(ptr[i] > ptr[j])
                    swap(ptr, i, j, gap);
                else
                    break;
            }
        }
        gap /= 2;
    }
    return;
}

void swap(int* ptr, int i, int j, int len)
{
    int tmp = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = tmp;
    print_tri(ptr, len, i, j);
    return;
}

void print_tri(int* arr, int len, int col_1, int col_2)
{
    system("clear");
    printf("%s", RESET);
    int i;
    for(i = 0; i < n; ++i)
    {
        if(i == col_1 || i == col_2)
            printf("->%s%d", KGRN, arr[i]);
        else
            printf("->%s%d", KNRM, arr[i]);
        printf("%s", RESET);
    }
    printf("\n");
    int cl = 1;
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
    for(i = 0; i < n; ++i)
    {
        if(i % len == 0)
            printf("\n");
        if(i == col_1 || i == col_2)
            printf("%s%0*d ", KRED, cl, arr[i]);
        else
            printf("%s%0*d ", KNRM, cl, arr[i]);
        printf("%s", RESET);
    }
    system("sleep 0.5");
    return;
}

