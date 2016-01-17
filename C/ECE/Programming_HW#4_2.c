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

int main(int argc, int* argv[])
{
    srand(time(NULL));
    int Ta = argv[argc-2];
    int Ts = argv[argc-1];
    int arrive = rand() % Ta;
    int service = rand() % Ts;
    return 0;
}

