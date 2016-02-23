/*************************************************************************
	> File Name: PD.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月26日 (週二) 11時08分56秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct st {
    int i;
    long long int s;
}sum[200010];

bool cmp(st a, st b);

int main()
{
    int n;
    cin >> n;
    bool che = 1;
    int sho = 200000;
    int shoix = 0;
    for(int i = 1; i <= n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        sum[i].s = tmp + sum[i-1].s;
        sum[i].i = i;
    }
    sort(&sum[1], &sum[n+1], cmp);
    for(int i = 1; i < n; ++i)
    {
        if(sum[i].s == sum[i+1].s)
        {}
    }
    if(che)
        cout << -1;
    else
    {
        cout << shoix << ' ' << sho;
    }
    return 0;
}

bool cmp(st a, st b)
{
    if(a.s == b.s)
        return a.i < b.i;
    return a.s < b.s;
}
