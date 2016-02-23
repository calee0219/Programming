/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月30日 (週六) 00時45分08秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int sv[10000];

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    while(n)
    {
        if(n & 1)
            sv[cnt] = 1;
        n >>= 1;
        cnt++;
    }
    for(int i = cnt-1; i >= 0; --i)
        if(sv[i])
            cout << i+1 << ' ';
    return 0;
}

