/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月25日 (週一) 10時09分26秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int g[5][5];
bool che[5];
int s[5];
int ans = 0;

void lis(int l)
{
    if(l == 5)
    {
        
        if(ans < g[s[0]][s[1]]+g[s[1]][s[0]] + g[s[1]][s[2]]+g[s[2]][s[1]] + 2*(g[s[2]][s[3]]+g[s[3]][s[2]]) + 2*(g[s[3]][s[4]]+g[s[4]][s[3]]))
            ans = g[s[0]][s[1]]+g[s[1]][s[0]] + g[s[1]][s[2]]+g[s[2]][s[1]] + 2*(g[s[2]][s[3]]+g[s[3]][s[2]]) + 2*(g[s[3]][s[4]]+g[s[4]][s[3]]);
    }
    for(int i = 0; i < 5; ++i)
    {
        if(che[i] == 0)
        {
            che[i] = 1;
            s[l] = i;
            lis(l+1);
            che[i] = 0;
        }
    }
}

int main()
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
            scanf("%d", &g[i][j]);
    }
    lis(0);
    cout << ans;
    return 0;
}

