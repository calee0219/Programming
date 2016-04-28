/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: sz110010@gmail.com
	> Created Time: Mon 04 Apr 2016 10:33:00 PM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool prefix(string,string);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        string str[10000];
        for(int i = 0; i < n; ++i)
            cin >> str[i];
        sort(str, str+n);
        bool che = true;
        for(int i = 0; i < n-1; ++i)
        {
            if(prefix(str[i],str[i+1]))
            {
                che = false;
                break;
            }
        }
        if(che) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

bool prefix(string a, string b)
{
    if(a.length() > b.length())
        return false;
    for(int i = 0; i < a.length(); ++i)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}
