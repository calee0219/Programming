/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月25日 (週一) 13時06分24秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    int fir = 0;
    while(scanf("%d", &n) && n)
    {
        if(fir)
            cout << endl;
        fir = 1;
        int a;
        while(scanf("%d", &a) && a)
        {
            queue<int> v;
            vector<int> t;
            for(int i = 1; i < n; ++i)
            {
                v.push(a);
                cin >> a;
            }
            v.push(a);
            for(int i = 1; i <= n; ++i)
            {
                if(!v.empty() && i == v.front())
                {
                    v.pop();
                    while(!t.empty() && !v.empty() && t.back() == v.front())
                    {
                        t.pop_back();
                        v.pop();
                    }
                }
                else t.push_back(i);
            }
            if(v.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

