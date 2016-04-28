/*************************************************************************
	> File Name: Codeforces_Round#3367(Div.2)#A.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月06日 (週三) 03時01分23秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin >> n;
    if(n & 1)
        cout << 0;
    else
    {
        n /= 2;
        cout << (n-1) / 2;
    }
    return 0;
}

