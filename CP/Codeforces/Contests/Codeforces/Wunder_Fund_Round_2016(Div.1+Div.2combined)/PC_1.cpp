/*************************************************************************
	> File Name: PC_1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月03日 (週三) 22時35分36秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

struct point {
    LL x, y;
    int index;
};

LL area(point a, point b, point c);
bool isline(point a, point b, point c);
int inside(point a, point b, point c, point p);
bool same_slop(point a, point b, point c);

int main()
{
    int n;
    cin >> n;
    point vertex[4];
    for(int i = 1; i <= n; ++i)
    {
        point p;
        cin >> p.x >> p.y;
        p.index = i;
        if(i <= 3)
            vertex[i] = p;
        else
        {
            if(isline(vertex[1], vertex[2], vertex[3]))
            {
                point tmp = p;
                p = vertex[1];
                vertex[1] = p;
            }
            int change = inside(vertex[1], vertex[2], vertex[3], p);
           if(change)
            {
                vertex[change] = p;
            }
        }
    }
    for(int i = 1; i <= 3; ++i)
        cout << vertex[i].index << ' ';
    return 0;
}

LL area(point a, point b, point c)
{
    return abs((a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x));
}

bool isline(point a, point b, point c)
{
    if(area(a,b,c) == 0) return true;
    else return false;
}

int inside(point a, point b, point c, point p)
{
    if(area(a,b,c) == area(p,b,c)+area(a,p,c)+area(a,b,p))
    {
        if(same_slop(a,b,p))
            return 1;
        if(same_slop(b,c,p))
            return 2;
        if(same_slop(a,c,p))
            return 3;
        return 1;
    }
    else
        return 0;
}

bool same_slop(point a, point b, point c)
{
    if((a.y-b.y)*(a.x-c.x) == (a.y-c.y)*(a.x-b.x))
        return true;
    else
        return false;
}

