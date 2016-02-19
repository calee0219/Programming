/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 09時48分27秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        long long int a[50010];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(&a[0], &a[n+1]);
        long long int ans = 0;
        long long int p[50010] = {0};
        for(int i = 1; i <= n; ++i)
            p[i] = a[i] + p[i-1];
        for(int i = 2; i <= n; ++i)
            ans += i*a[i] - p[i];
        cout << ans << endl;
    }
    return 0;
}

