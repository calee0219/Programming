/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月23日 (週六) 03時13分50秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, w, x, c;
    int times = 0;
    cin >> a >> b >> w >> x >> c;
    while(c > a)
    {
        times++;
        c--;
        if(b >= x)
            b -= x;
        else
        {
            a--;
            b += w - x;
        }
    }
    cout << times;
    return 0;
}

