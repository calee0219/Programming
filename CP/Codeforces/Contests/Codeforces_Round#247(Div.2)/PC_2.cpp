/*************************************************************************
	> File Name: PC_2.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月25日 (週一) 18時19分28秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k, d;
long long int dp[110][2] = {0};

int main()
{
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k && i >= j; ++j)
        {
            if(j < d)
            {
                dp[i][0] += dp[i-j][0];
                dp[i][0] %= 1000000007;
                dp[i][1] += dp[i-j][1];
                dp[i][1] %= 1000000007;
            }
            else
            {
                dp[i][1] += dp[i-j][1] + dp[i-j][0];
                dp[i][1] %= 1000000007;
            }
        }
    }
    cout << dp[n][1] << endl;
    return 0;
}

