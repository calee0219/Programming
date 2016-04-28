/*************************************************************************
	> File Name: PD.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月25日 (週四) 21時34分30秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    int wr = 0;
    vector<int> v;
    for(int i = 0; i < n-1; ++i)
    {
        int d;
        scanf("%1d", &d);
        v.push_back(d);
        wr += d;
        if(wr / 10)
            wr = wr % 10 + 1;
    }
    wr = r-wr;
    if(wr < 0)
        wr += 10;
    if(wr < 9 && wr > 0)
    {
        set<string> s;
        for(int i = 0; i < n; ++i)
        {
            string str;
            for(int j = 0; j < n; ++j)
            {
                if(j == i)
                    str.insert(str.end(), (char)(wr+'0'));
                if(j < n-1)
                    str.insert(str.end(), (char)(v.at(j)+'0'));
            }
            s.insert(str);
        }
        for (set<string>::iterator it=++s.begin(); it!=--s.end(); ++it)
            cout << *it << endl;
    }
    else
    { 
        set<string> s;
        for(int i = 0; i < n; ++i)
        {
            string str;
            for(int j = 0; j < n; ++j)
            {
                if(j == i)
                    str.insert(str.end(), (char)'0');
                if(j < n-1)
                    str.insert(str.end(), (char)(v.at(j)+'0'));
            }
            s.insert(str);
            str.clear();
            for(int j = 0; j < n; ++j)
            {
                if(j == i)
                    str.insert(str.end(), (char)'9');
                if(j < n-1)
                    str.insert(str.end(), (char)(v.at(j)+'0'));
            }
            s.insert(str);
        }
        for (set<string>::iterator it=++s.begin(); it!=--s.end(); ++it)
            cout << *it << endl;
    }
    return 0;
}
