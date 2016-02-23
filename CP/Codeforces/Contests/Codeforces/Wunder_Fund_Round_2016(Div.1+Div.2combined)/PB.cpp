/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月30日 (週六) 01時38分53秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int sv[55];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        bool che[55] = {0};
        for(int j = 1; j <= n; ++j)
        {
            int tmp;
            cin >> tmp;
            if(che[tmp])
                sv[i] = tmp;
            che[tmp] = 1;
        }
    }
    bool ch = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(sv[i] == 0)
        {
            if(ch)
            {
                sv[i] = n;
                ch = 0;
            }
            else sv[i] = n-1;
        }
        cout << sv[i] << ' ';
    }
    return 0;
}

