#include <bits/stdc++.h>
using namespace std;
struct house {
    int l, r, id;
}h[5010];

int n, r, c[4];
map<tuple<int,int,int>,int> dp;

int rec(int now, int s1, int s2)
{
    if(now == n)
        return 0;
    if(h[now].id == 1)
        s1 = h[now].r + r;
    else
        s2 = h[now].r + r;
    int tmp = dp.count(make_tuple(now+1,s1,s2)) != 0?dp.at(make_tuple(now+1,s1,s2)):rec(now+1,s1,s2);
    dp.insert(make_pair(make_tuple(now,s1,s2),min(c[h[now].id]+tmp,c[3]+tmp)));
    return dp.at(make_tuple(now,s1,s2));
}

bool cmp(house a, house b)
{
    return a.r < b.r;
}

int main()
{
    while(~scanf("%d%d%d%d%d", &n, &r, &c[1], &c[2], &c[3]) && n && r && c[1] && c[2] && c[3])
    {
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d", &h[i].l, &h[i].r, &h[i].id);
        sort(h,h+n,cmp);
        printf("%d", rec(0,0,0));
    }
    return 0;
}
