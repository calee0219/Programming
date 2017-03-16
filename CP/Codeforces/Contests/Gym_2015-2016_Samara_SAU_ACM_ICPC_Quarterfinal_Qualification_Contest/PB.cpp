/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月26日 (週二) 09時51分32秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int y[5010] = {0};

int main()
{
	int n, m;
	cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            char a;
            cin >> a;
            if(a == '1')
                y[j]++;
        }
    }
    int check = 0;
    for(int i = 1; i <= m; ++i)
    {
        if(y[i] > n/2)
            check++;
    }
    int ccc = 0;
    for(int i = 1; i <= m; ++i)
    {
        if(ccc == 15)
            printf("0");
        else if(y[i] > n/2)
        {
            printf("1");
            ccc++;
        }
        else if(y[i] < (n+1)/2)
            printf("0");
        else if(check < 8)
        {
            printf("1");
            check++;
            ccc++;
        }
        else printf("0");
    }
	return 0;
}
