/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月24日 (週三) 02時57分39秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n)
    {
        queue<int> q;
        int m;
        cin >> m;
        if( m == 0)
        {
            cin >> n;
            if(n)
                cout << endl;
            continue;
        }
        q.push(m);
        for(int i = 1; i < n; ++i)
        {
            cin >> m;
            q.push(m);
        }
        vector<int> v;
        for(int i = 1; i <= n; ++i)
        {
            v.push_back(i);
            while(!v.empty() && !q.empty() && v.back() == q.front())
            {
                v.pop_back();
                q.pop();
            }            
        }
        if(v.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
