/*************************************************************************
	> File Name: PJ_1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 12時57分41秒
 ************************************************************************/

#include <bits/stdc++.h>
#define mod 100000007
using namespace std;

int mypow(int b)
{
    long long int ans = 1;
    long long int a = 3;
    while(b)
    {
        if(b & 1)
            ans *= a;
        ans %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        cout << (mypow(N)-1 + mod) % mod << endl;
    }
    return 0;
}

