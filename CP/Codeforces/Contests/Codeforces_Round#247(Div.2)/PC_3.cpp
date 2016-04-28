/*************************************************************************
	> File Name: PC_2.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月25日 (週一) 12時52分50秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k, d;
int dp[100][2];

int main()
{
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 0; i <= n; ++i)
    {
        dp[i][0] = dp[i][1] = 0;
        for(int j = 0; j <= k; ++j)
        {
            if(i < j) break;
            if(j < d)
            {
                dp[i][0] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
            }
            else
            {
                dp[i][1] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
            }
        }
    }
    cout << dp[n][1] << endl;
    return 0;
}

