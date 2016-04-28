/*************************************************************************
	> File Name: PC.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月23日 (週六) 11時00分38秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> g[300000];
vector<int> check;

int dfs(int now);

int main()
{
    int n;
    cin >> n;
    int p[100000];
    for(int i = 0; i < n; ++i)
        scanf("%d", &p[i]);
    int m;
    cin >> m;
    while(m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }
    dfs(0);
    for(int i = 0; i < n; ++i)
    {
    }
    return 0;
}

int dfs(int now)
{
    
}

