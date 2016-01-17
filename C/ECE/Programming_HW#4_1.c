/*************************************************************************
	> File Name: Programming_HW#4_1.c
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 2016年01月16日 下午 01:41:36
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

struct MatrixNode {
    int row, col, value;
    struct MatrixNode* down;
    struct MatrixNode* right;
};

// global variable
struct MatrixNode** colHeader;
struct MatrixNode** rowHeader;

void read(FILE* fin, struct MatrixNode** name_col, struct MatrixNode** name_row, int col, int row);
void insert(struct MatrixNode** name_col, struct MatrixNode** name_row, int col, int row, int num);
//int summation();
//int subtraction();
//int multiplication();

int main(int argc, char* argv[])
{
    FILE* fin = fopen(argv[argc-2], "r");
    FILE* fout = fopen(argv[argc-1], "w");
    struct MatrixNode** a_colHeader,** a_rowHeader;
    int a_col, a_row;
    struct MatrixNode** b_colHeader,** b_rowHeader;
    int b_col, b_row;
    system("pause");
    read(fin, a_colHeader, a_rowHeader, a_col, a_row);
    read(fin, b_colHeader, b_rowHeader, b_col, b_row);
#ifdef DEBUG
    printf("A\n");
    int i;
    for(i = 0; i < a_col; ++i)
        while(a_colHeader[i] != NULL)
        {
            printf("%d ", a_colHeader[i]->value);
            a_colHeader[i] = a_colHeader[i]->down;
        }
    printf("B\n");
    for(i = 0; i < a_row; ++i)
        {
            printf("%d ", a_rowHeader[i]->value);
            a_rowHeader[i] = a_rowHeader[i]->down;
        }
    printf("B\n");
    for(i = 0; i < b_col; ++i)
        while(b_colHeader[i] != NULL)
        {
            printf("%d ", b_colHeader[i]->value);
            b_colHeader[i] = b_colHeader[i]->down;
        }
    printf("\n");
    for(i = 0; i < b_row; ++i)
        {
            printf("%d ", b_rowHeader[i]->value);
            b_rowHeader[i] = b_rowHeader[i]->down;
        }
    printf("\n");
#endif
/*    int n;
    fprintf(fout, "A + B = ");
    if(n = summation())
    {
        fprintf(fout, "(It occupies %d entries.)\n", n);
        int i, j;
        for(i = 0; i < a_row; ++i)
            for(j = 0; j < a_col; ++j)
                fprintf(fout, "%d ", colHeader[j]->value);
    }
    else
        fprintf(fout, "\nNo operation\n");
    fprintf(fout, "A - B = ");
    if(n = subtraction())
    {
        fprintf(fout, "(It occupies %d entries.)\n", n);
        int i, j;
        for(i = 0; i < a_row; ++i)
            for(j = 0; j < a_col; ++j)
                fprintf(fout, "%d ", colHeader[j]->value);
    }
    else
        fprintf(fout, "\nNo operation\n");
    fprintf(fout, "A * B = ");
    if(n = multiplication())
    {
        fprintf(fout, "(It occupies %d entries.)\n", n);
        int i, j;
        for(i = 0; i < a_row; ++i)
            for(j = 0; j < b_col; ++j)
                fprintf(fout, "%d ", colHeader[j]->value);
    }
    else
        fprintf(fout, "\nNo operation\n");
*/    fclose(fin);
    fclose(fout);
    return 0;
}

void read(FILE* fin, struct MatrixNode** name_col, struct MatrixNode** name_row, int col, int row)
{
    fgetc(fin);
    fscanf(fin, "%d%d", &row, &col);
    int i, j;
    for(i = 0; i < col; ++i)
    {
        for(j = 0; j < row; ++j)
        {
            int num;
            fscanf(fin, "%d", &num);
            insert(name_col, name_row, i, j, num);
        }
    }
}

void insert(struct MatrixNode** name_col, struct MatrixNode** name_row, int col, int row, int num)
{
    while(name_col[col] != NULL)
        name_col[col] = name_col[col]->down;
    system("pause");
    name_col[col] = malloc(sizeof(struct MatrixNode));
    system("pause");
    name_col[col]->value = num;
    name_col[col]->col = col;
    name_col[col]->row = row;
    while(name_row[row] != NULL)
        name_row[row] = name_row[row]->right;
    name_row[row] = name_col[col];
    return;
}
/*
int summation()
{}

int subtraction()
{}

int multiplication()
{}
*/
