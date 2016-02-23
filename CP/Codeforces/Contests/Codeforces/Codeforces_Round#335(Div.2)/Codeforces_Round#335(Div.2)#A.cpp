/*************************************************************************
	> File Name: Codeforces_Round#335(Div.2)#A.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月06日 (週三) 02時54分23秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x, y, z;
    cin >> x >> y >> z;
    int sum = 0;
    if(a-x < 0)
        sum += a-x;
    else
        sum += (a-x)/2;
    if(b-y < 0)
        sum += b-y;
    else
        sum += (b-y)/2;
    if(c-z < 0)
        sum += c-z;
    else
        sum += (c-z)/2;
    if(sum >= 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

