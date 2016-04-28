/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月25日 (週一) 09時57分13秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    string s;
    cin >> s;
    int l = s.length();
    int ans = 0;
    for(int i = 0; i < l; ++i)
    {
        switch(s[i]) {
            case '1':
                ans += a1;
                break;
            case '2':
                ans += a2;
                break;
            case '3':
                ans += a3;
                break;
            case '4':
                ans += a4;
                break;
        }
    }
    cout << ans;
    return 0;
}

