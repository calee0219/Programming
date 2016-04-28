/*************************************************************************
	> File Name: PC.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月30日 (週六) 01時58分14秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long int nx[4], ny[4];
long long int p[4];

int inside(int x, int y);
bool isline();

int main()
{
    int n;
    cin >> n;
    for(int che = 1; che <= n; ++che)
    {
        long long int x, y;
        scanf("%I64d%I64d", &x, &y);
        if(che > 3)
        {
            int cc = che;
            if(isline())
            {
                int tmp_cc = p[1];
                long long int tmp_x = nx[1], tmp_y = ny[1];
                nx[1] = x;
                ny[1] = y;
                p[1] = cc;
                x = tmp_x; y = tmp_y; cc = tmp_cc;
            }
            int tmp = inside(x, y);
            if(tmp)
            {
                nx[tmp] = x;
                ny[tmp] = y;
                p[tmp] = cc;
            }
        }
        else
        {
            nx[che] = x;
            ny[che] = y;
            p[che] = che;
        }
    }
    for(int i = 1; i <= 3; ++i)
        cout << p[i] << ' ';
    return 0;
}

int inside(int x, int y)
{
    if(abs(nx[1]*ny[2]+nx[2]*ny[3]+nx[3]*ny[1]-ny[1]*nx[2]-ny[2]*nx[3]-ny[3]*nx[1]) ==
            abs(nx[1]*ny[2]+nx[2]*y+x*ny[1]-ny[1]*nx[2]-ny[2]*x-y*nx[1]) +
            abs(nx[1]*y+x*ny[3]+nx[3]*ny[1]-ny[1]*x-y*nx[3]-ny[3]*nx[1]) +
            abs(x*ny[2]+nx[2]*ny[3]+nx[3]*y-y*nx[2]-ny[2]*nx[3]-ny[3]*x))
    {
        if((nx[1]-nx[2])*(ny[1]-y) == (nx[1]-x)*(ny[1]-ny[2]))
            return 1;
        if((nx[2]-nx[3])*(ny[2]-y) == (nx[2]-x)*(ny[2]-ny[3]))
            return 2;
        if((nx[3]-nx[1])*(ny[3]-y) == (nx[3]-x)*(ny[3]-ny[1]))
            return 3;
        else return 1;
    }
    return 0;
}

bool isline()
{
    if(nx[1]*ny[2]+nx[2]*ny[3]+nx[3]*ny[1]-ny[1]*nx[2]-ny[2]*nx[3]-ny[3]*nx[1] == 0)
        return 1;
    return 0;
}

