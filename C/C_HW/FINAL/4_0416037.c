#include <stdio.h>

int main()
{
    FILE* fin = fopen("input_file1.txt", "r");
    FILE* fout = fopen("output_file1.txt", "w");
    char la[100][100];
    char* str[100];
    int m[100];
    int len, num;
    fscanf(fin, "%d%d", &len, &num);
    int i;
    for(i = 0; i < num; ++i)
    {
        str[i] = la[i];
        m[i] = 0;
        fscanf(fin, "%s", str[i]);
        int j;
        for(j = 0; j < len; ++j)
        {
            int k;
            for(k = j; k < len; ++k)
            {
                if(str[i][j] > str[i][k])
                    m[i]++;
            }
        }
    }
    for(i = 0; i < num; ++i)
    {
        int j;
        for(j = 0; j < num-1; ++j)
        {
            if(m[j] > m[j+1])
            {
                int tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
                char* t = str[j];
                str[j] = str[j+1];
                str[j+1] = t;
            }
        }
    }
    for(i = 0; i < num; ++i)
        fprintf(fout, "%s\n", str[i]);
    return 0;
}

