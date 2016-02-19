/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月17日 (週三) 15時19分25秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    int che = 0;
    while(scanf("%d%d", &a, &b) && a && b)
    {
        char c[10000];
        scanf("%s", c);
        int len = strlen(c);
        long long int num = 0;
        for(int i = 0; i < len; ++i)
        {
            num *= a;
            if(c[i] <= '9' && c[i] >= '0')
                num += c[i]-'0';
            else
                num += c[i] - 'A' + 10;
        }
        char cc[10000];
        int i;
        for(i = 0; num; ++i)
        {
            int tmp = num % b;
            if(tmp >= 0 && tmp < 10) cc[i] = tmp + '0';
            else cc[i] = tmp - 10 + 'A';
            num /= b;
        }

        for(int j = i-1; j >= 0; --j)
            printf("%c", cc[j]);
        printf("\n");
    }
    return 0;
}
