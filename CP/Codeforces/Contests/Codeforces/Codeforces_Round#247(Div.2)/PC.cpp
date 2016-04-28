/*************************************************************************
	> File Name: PC.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月25日 (週一) 10時41分02秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int H(int n, int m);

int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    n -= d-1;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        int to = n - i;
        ans += 1 + H(i, to)*i;
    }
    cout << ans;
    return 0;
}

int H(int n, int m)
{
    int ans = 1;
    for(int i = 1; i <= n+m-1; ++i)
        ans *= i;
    for(int i = 1; i <= m; ++i)
        ans /= i;
    for(int i = 1; i <= n-1; ++i)
        ans /= i;
    return ans;
}

