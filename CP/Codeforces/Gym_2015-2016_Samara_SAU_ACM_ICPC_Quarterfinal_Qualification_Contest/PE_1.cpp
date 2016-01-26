/*************************************************************************
	> File Name: PE_1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月26日 (週二) 13時51分26秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct P
{
    int id;
	int c;
	int r;
};

P h[100010];
int H[100010];
bool cmp(P a, P b);

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        h[i] = (P){i, a, b};
    }
    int last_c = h[n].c;
    sort(&h[1], &h[1+n], cmp);
    int h_r = 1;
    int ord = 0;
    int i = 1;
    int max = 1;
    while(h_r < last_c)
    {
        for(; h[i].c <= h_r; ++i)
        {
            if(h[max].r < h[i].r)
                max = i;
        }
        if(h[max].r <= h_r)
        {
            cout << "No such luck";
            return 0;
        }
        H[ord] = max;
        ord++;
        h_r = h[max].r;
    }
    cout << ord+1 << endl;
    for(int i = 0; i < ord; ++i)
        cout << h[H[i]].id << ' ';
    cout << n;
    return 0;
}

bool cmp(P a,P b)
{
	if(a.c==b.c)
		return a.r<b.r;
	return a.c<b.c;
}
