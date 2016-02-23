/*************************************************************************
	> File Name: PC_1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月25日 (週一) 11時45分31秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k, d;
int ans = 0;
int to = 0;
bool che = 0;

void dfs(int l)
{
    if(to == n-d && che == 0)
    {
        ans++;
        return;
    }
    else if(to >= n)
    {
        if(to > n || che == 0)
            return;
        ans++;
        return;
    }
    else
        for(int i = 1; i <= k; ++i)
        {
            bool chch = 0;
            if(i >= d && che == 0) 
            {
                chch = 1;
                che = 1;
            }
            to += i;
            dfs(l+1);
            to -= i;
            if(chch)
                che = 0;
        }
}

int main()
{
    cin >> n >> k >> d;
    dfs(0);
    cout << ans;
    return 0;
}

