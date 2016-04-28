/*************************************************************************
	> File Name: MST.cpp
	> Author: Gavin Lee
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年04月27日 (週三) 16時43分41秒
 ************************************************************************/

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define EPS 1E-7
#define INF 0x7FFFFFFF
#define PI 3.1415926535897932384626433832795

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VII;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
//int dx[]={1,0,-1,0};              int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};    int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};   int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};        int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

struct Edge {
    Edge(int a, int b, int c):p1(a),p2(b),w(c) {}
    int p1,p2,w;
    bool operator< (Edge e) { return w > e.w; }
};
struct TREE {
    int p;
    vector<TREE*> t;
};

set<Edge> s;
set<pair<int,int> > p[1000000];
bool used[1000000];

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int p1,p2,w;
        cin >> p1 >> p2 >> w;
        p[p1].insert(mp(p2,w));
        p[p2].insert(mp(p1,w));
    }
    Edge ee(1,p[1].begin()->ff,p[1].begin()->ss);
    s.insert(ee);
    return 0;
}
