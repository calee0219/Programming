/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年04月11日 (週一) 21時15分31秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        string str;
        cin >> str;
        int ans = 0;
        int l = str.length();
        for(int j = 1; j < l; ++j)
        {
            if(str[j] != str[j-1])
                ans++;
        }
        if(str[l-1] == '-')
            ans++;
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
