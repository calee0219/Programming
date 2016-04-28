/*************************************************************************
	> File Name: Programming_HW#4_2.c
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 2016年01月16日 下午 02:32:20
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

/* this file */
#define TOTAL_TIME 720

typedef struct q {
    int time;
    struct q* next;
} queue;

void push_back(queue* line, int arrive);
queue* pop_front(queue* line);

int main(int argc, int* argv[])
{
//    srand(time(NULL));
    int Ta = 4;//*argv[argc-2];
    int Ts = 4;//*argv[argc-1];
    int arrive, service;
    int now = 0;
    int last = 0;
    queue* waiting_line;
    arrive = rand() % Ta + 1;
    service = rand() % Ts + 1;
    push_back(waiting_line, arrive);
    for(now = 0; now < TOTAL_TIME; ++now)
    {
        if(now == arrive + last)
        {
            printf("Next customer arrives!");
            arrive = rand() % Ta + 1;
            service = rand() % Ts + 1;
            push_back(waiting_line, arrive);
            last = now;
        }
    }
    return 0;
}

void push_back(queue* line, int arrive)
{
    while(line != NULL)
        line = line->next;
    line = malloc(sizeof(queue));
    line->time = arrive;
    line->next = NULL;
    return;
}

queue* pop_front(queue* line)
{
    queue* tmp = line;
    line = line->next;
    free(tmp);
    return line;
}

