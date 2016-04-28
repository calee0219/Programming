/*************************************************************************
	> File Name: 3n+1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年03月15日 (週二) 00時03分03秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j;
    cin >> i >> j;
    int min_num, max_num;
    min_num = min(i,j);
    max_num = max(i,j);
    int cnt = 0;
    int n;
    cin >> n;
    while(n != 1)
    {
        if(n & 1)
            n = 3 * n + 1;
        else
            n /= 2;
        if(n > min_num && n < max_num)
            cnt++;
    }
    return 0;
}
