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
long long int sum;

void dfs(int n, int l)
{
    if(used[l] == 0)
    {
        sum += a[l];
        //cout << l << ' ' << sum << endl;
        used[l] = 1;
        for(int i = 0; i < node[l].size(); ++i)
        {
            if(used[node[l].at(i)]) continue;
            else dfs(n, node[l].at(i));
        }
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
        {
            node[i].clear();
            used[i] = 0;
            cin >> a[i];
        }
        while(m--)
        {
            int b, c;
            cin >> b >> c;
            node[b].push_back(c);
            node[c].push_back(b);
        }
        long long int max = 0;
        for(int i = 1; i <= n; ++i)
        {
            sum = 0;
            dfs(n, i);
            if(max < sum)
                max = sum;
        }
        cout << max << endl;
    }
    return 0;
}

