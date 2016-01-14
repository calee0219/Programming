/*************************************************************************
	> File Name: radix_sort.c
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: Wed 13 Jan 2016 07:30:14 PM CST
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

typedef struct li {
    int data;
    struct li* next;
} List;

void radix_sort(int* ptr, int len);
void insert(List* ls, int num);
void remove_all(List* ls);

int main()
{
    int a[50];
    int n = rand() % 50;
    int i;
    for(i = 0; i < n; ++i)
        a[i] = rand() % 50;
    radix_sort(a, 50);
    return 0;
}

void radix_sort(int* ptr, int len)
{
    List* ls[10] = {NULL};
    int lay = 1;
    int che = 1;
    int i;
    for(i = 0; i < len; ++i)
    {
        if(i == 0)
            lay *= 10;
        if(ptr[i] >= lay/10)
        {
            che = 1;
            insert(ls[(ptr[i] % lay)/(lay/10)], ptr[i]);
        }
        if(i == len-1 && che == 0)
            break;
        else
        {
            int j;
            for(j = 0; j < 10; ++j)
            {
                while(ls[i] != NULL)
                {
                    ls[i] = ls[i]->next;
                }
            }
            che = 0;
            i = -1;
        }
    }
    return;
}

void insert(List* ls, int num)
{
    while(ls != NULL)
        ls = ls->next;
    List* tmp = malloc(sizeof(List));
    tmp->data = num;
    tmp->next = NULL;
    return;
}

void remove_all(List* ls)
{
    if(ls->next != NULL)
        remove_all(ls->next);
    free(ls);
    return;
}

