/*************************************************************************
	> File Name: PD_1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 23時56分28秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int a[1000000];
vector<int> node[1000000];
bool used[1000000];

void dfs(int n, int l)
{
    if(l == n+1)
        return;
    int sum = 0;
    if(!node[l].empty())
    {
        if(used[node[l].back()]) continue;
        else
        {
            used[node[l].back()] = 1;
            dfs(n, node[l].back());
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    while(m--)
    {
        int b, c;
        cin >> b >> c;
        node[b].push_back(c);
        node[c].push_back(b);
    }
    dfs(n, 1);
    return 0;
}

