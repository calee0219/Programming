/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月23日 (週六) 03時13分50秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int alex(int c);
int arth(int a, int b, int w, int x);
int main()
{
    int a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;
    return 0;
}

int alex(int c)
{
    return c-1;
}

int arth(int a, int b, int w, int x)
{
    if(b >= x)
        return b-x;
    else
        return w-x+b;
}

