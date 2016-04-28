/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月23日 (週六) 10時11分41秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int main()
{
    int n, t, c;
    cin >> n >> t >> c;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        if(tmp <= t)
            p.push_back(tmp);
        else
        {
            if(p.size() >= c)
                ans += p.size() - c + 1;
            p.erase(p.begin(), p.end());
        }
    }
    if(p.size() >= c)
        ans += p.size() - c + 1;
    cout << ans;
    return 0;
}

