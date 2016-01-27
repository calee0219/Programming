/*************************************************************************
	> File Name: PJ.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 11時41分58秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int dp[1000000];
int range = 1;

int ddpp(int N)
{
    if(N == 1000000)
        return dp[1000000];
    int j = (ddpp(N-1)*3 + 2) % 100000007;
    if(j  == 2)
        range = j-1;
    return j;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        scanf("%d", &N);
        dp[1] = 0;
        for(int i = 2; i <= N && i <= 1000000; ++i)
        {
            if(dp[i] == 0)
            {
                dp[i] = dp[i-1]*3 + 6;
                dp[i] %= 100000007;
            }
            if(dp[i] == 2 && range == 1)
            {
                range = i - 1;
                break;
            }
        }
        if(N > 1000000)
            ddpp(N);
        if(range != 1)
            N %= range;
        printf("%d\n", dp[N]+2);
    }
    return 0;
}

