/*************************************************************************
	> File Name: PD.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 11時26分35秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int g[1000000];

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
            cin >> a[i];
            g[i] = i;
        }
        while(m--)
        {
            int b, c;
            cin >> b >> c;
            int gc = g[c];
            for(int i = 1; i <= n; ++i)
                if(g[i] == gc)
                    g[i] = g[b];
        }
        for(int i = 1; i <= n; ++i)
            if(g[i] != i)
                a[g[i]] += a[i];
        int max = 0;
        for(int i = 1; i <= n; ++i)
            if(max < a[i])
                max = a[i];
        cout << max;
    }
    return 0;
}

