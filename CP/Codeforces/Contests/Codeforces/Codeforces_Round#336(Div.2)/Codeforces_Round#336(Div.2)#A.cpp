/*************************************************************************
	> File Name: Codeforces_Round#336(Div.2)#A.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月06日 (週三) 02時57分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int time = s;
    while(n--)
    {
        int f, t;
        cin >> f >> t;
        if(t + f > time)
            time = t + f;
    }
    cout << time;
    return 0;
}

