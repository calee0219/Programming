/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月23日 (週六) 13時40分34秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100000];
    for(int i = 1; i <= n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        if(i == 1)
            a[i] = tmp;
        else
            a[i] = a[i-1] + tmp;
    }
    int m;
    cin >> m;
    int q;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &q);
    }
    return 0;
}
