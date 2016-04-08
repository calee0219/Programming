/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: sz110010@gmail.com
	> Created Time: Fri 08 Apr 2016 08:12:19 PM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
struct Edge {
    Edge(int ts, int te, int tw):s(ts),e(te),w(tw) {}
    int s,e;
    int w;
    bool operator <(const Edge e) { return w < e.w; }
};

int n,k,m;
set<Edge> edge;
int p[1000000];
bool used[1000000];
int mst(void);
int find(int);

int main()
{
    while(~scanf("%d", &n))
    {
        memset(used,0,sizeof(used));
        int weigth = 0;
        for(int i = 0; i < n-1; ++i)
        {
            int s,e,w;
            scanf("%d%d%d",&s,&e,&w);
            weigth += w;
            Edge tmp(s,e,w);
            edge.insert(tmp);
        }
        scanf("%d", &k);
        for(int i = 0; i < k; ++i)
        {
            int s,e,w;
            scanf("%d%d%d",&s,&e,&w);
            Edge tmp(s,e,w);
            edge.insert(tmp);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
        {
            int s,e,w;
            scanf("%d%d%d",&s,&e,&w);
        }
        cout << weigth << endl << mst() << endl;
    }
    return 0;
}

int mst(void)
{
    int weight = 0;
    for(int i = 0; i < n; ++i)
        p[i] = i;
    for(int i = 0; i < n; ++i)
    {
        if(find(edge.begin()->s) != find(edge.begin()->e))
        {
            weight += edge.begin()->w;
            used[edge.begin()->s] = used[edge.begin()->e] = 1;
            edge.erase(edge.begin());
        }
    }
    return weight;
}

int find(int x)
{
    return (p[x] == x)? x:find(p[x]);
}
