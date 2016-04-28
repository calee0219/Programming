/*************************************************************************
	> File Name: HW12_0416037.c
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月03日 (週日) 16時35分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATA{
    char name[15];
    int year, mounth, date;
    int con;
    char back[10];
} DA;

int cmp_nam(const void* a, const void* b);
int cmp_con(const void* a, const void* b);

int main()
{
    FILE* fin = fopen("PM2.5.csv", "r");
    FILE* fSin = fopen("outcomeSingle.csv", "w");
    FILE* fBin = fopen("outcomeBinary.bin", "wb");
    char c;
    while((c = fgetc(fin)) != '\n')
    {
        fputc(c, fSin);
        fputc(c, fBin);
    }
    fputc(c, fSin);
    fputc(c, fBin);
    DA data[1000];
    int i;
    for(i = 0; i < 1000; ++i)
    {
        DA tmp;
        fscanf(fin, "%[^,], %d/%d / %d,%d, %[^\n]", tmp.name, &tmp.year, &tmp.mounth, &tmp.date, &tmp.con, tmp.back);
        while((c = fgetc(fin)) != '\n');
        data[i] = tmp;
    }
    qsort(data, 1000, sizeof(DA), cmp_nam);
    for(i = 0; i < 1000; ++i)
    {
        fprintf(fSin, "%s, %d/%d / %d,%d, %s\n", data[i].name, data[i].year, data[i].mounth, data[i].date, data[i].con, data[i].back);
        fprintf(fBin, "%s, %d/%d / %d,%d, %s\n", data[i].name, data[i].year, data[i].mounth, data[i].date, data[i].con, data[i].back);
    }
    fclose(fBin);
    fclose(fSin);
    fclose(fin);
    fBin = fopen("outcomeBinary.bin", "rb");
    FILE* fPai = fopen("outcomePair.csv", "w");
    while((c = fgetc(fBin)) != '\n')
        fputc(c, fPai);
    fputc(c, fPai);
    for(i = 0; i < 1000; ++i)
    {
        DA tmp;
        fscanf(fBin, "%[^,], %d/%d / %d,%d, %[^\n]", tmp.name, &tmp.year, &tmp.mounth, &tmp.date, &tmp.con, tmp.back);
        while((c = fgetc(fBin)) != '\n');
        data[i] = tmp;
    }
    qsort(data, 1000, sizeof(DA), cmp_con);
    for(i = 0; i < 1000; ++i)
        fprintf(fPai, "%s, %d/%d / %d,%d, %s\n", data[i].name, data[i].year, data[i].mounth, data[i].date, data[i].con, data[i].back);
    fclose(fPai);
    fclose(fBin);
    return 0;
}

int cmp_nam(const void* a, const void* b)
{
    return strcmp(((DA*)a)->name, ((DA*)b)->name);
}

int cmp_con(const void* a, const void* b)
{
	if(strcmp(((DA*)a)->name, ((DA*)b)->name) == 0)
		return (((DA*)a)->con > ((DA*)b)->con)?1:-1;
	return strcmp(((DA*)a)->name, ((DA*)b)->name);
}

