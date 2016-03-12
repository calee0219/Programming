/*************************************************************************
    > File Name: PC.cpp
    > Author: Gavin Lee
    > Mail: sz110010@gmail.com
    > Created Time: 西元2016年02月24日 (週三) 22時35分47秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<int,int> m;
    while(~scanf("%d", &n) && n)
    {
        if(n > 0)
        {
            if(m.count(n))
                m.at(n)++;
            else
                m.insert(pair<int,int>(n,1));
        }
        else if(m.empty())
            continue;
        else if(n == -1)
        {
            cout << m.begin()->first << ' ';
            m.begin()->second--;
            if(m.begin()->second == 0)
                m.erase(m.begin()->first);
        }
        else
        {
            cout << m.rbegin()->first << ' ';
            m.rbegin()->second--;
            if(m.rbegin()->second == 0)
                m.erase(m.rbegin()->first);
        }
    }
    return 0;
}
