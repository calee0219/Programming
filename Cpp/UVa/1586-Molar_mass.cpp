/*************************************************************************
	> File Name: 1586-Molar_mass.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年03月04日 (週五) 01時34分43秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    map<char,double> m;
    m['C'] = 12.01;
    m['H'] = 1.008;
    m['O'] = 16;
    m['N'] = 14.01;
    while(T--)
    {
     	string s;
        cin >> s;
        double ans = 0;
        unsigned int ord = 0;
        while(ord < s.size())
        {
            char tmp;
            int num = 0;
            if(s[ord] < 'Z' && s[ord] > 'A')
            tmp = s[ord];
            ord++;
            while(s[ord] >= '0' && s[ord] <= '9')
            {
                num *= 10;
                num += s[ord]-'0';
                ord++;
            }
            if(num)
            ans += m[tmp]*num;
            else
            ans += m[tmp];
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
