/*************************************************************************
	> File Name: PC.cpp
	> Author: Gavin Lee
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年04月25日 (週一) 00時59分31秒
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

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    int mx[101][101] = {{0}};
    int cmd[1000][4];
    vector<tuple<int,int,int> > t;
    for(int i = 0; i < q; ++i)
    {
        scanf("%d", &cmd[i][0]);
        if(cmd[i][0] == 3) scanf("%d%d%d", &cmd[i][1], &cmd[i][2], &cmd[i][3]);
        else scanf("%d", &cmd[i][1]);
    }
    for(int i = q-1; i >= 0; --i)
    {
        if(cmd[i][0] == 1)
        {
            int l = t.size();
            for(int j = 0; j < l; ++j)
            {
                if(get<0>(t[j]) == cmd[i][1])
                {
                    if(get<1>(t[j]) == m) get<1>(t[j]) = 1;
                    else ++get<1>(t[j]);
                }
            }
        }
        if(cmd[i][0] == 2)
        {
            int l = t.size();
            for(int j = 0; j < l; ++j)
            {
                if(get<1>(t[j]) == cmd[i][1])
                {
                    if(get<0>(t[j]) == n) get<0>(t[j]) = 1;
                    else ++get<0>(t[j]);
                }
            }
        }
        if(cmd[i][0] == 3)
            t.push_back(make_tuple(cmd[i][1],cmd[i][2],cmd[i][3]));
    }
    int l = t.size();
    for(unsigned i = 0; i < l; ++i)
        mx[get<0>(t[i])][get<1>(t[i])] = get<2>(t[i]);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
            printf("%d ", mx[i][j]);
        printf("\n");
    }
    return 0;
}
