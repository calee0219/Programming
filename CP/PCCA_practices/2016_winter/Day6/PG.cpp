/*************************************************************************
	> File Name: PG.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 18時17分58秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        queue<int> q[m+1];
        while(n--)
        {
            string mv;
            cin >> mv;
            if(mv == "push")
            {
                int a, b;
                scanf("%d%d", &a, &b);
                q[b].push(a);
            }
            else
            {
                int ord = 1;
                while(q[ord].empty())
                    ord++;
                cout << q[ord].front() << endl;
                q[ord].pop();
            }
        }
    }
    return 0;
}

