/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年04月25日 (週一) 00時41分34秒
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
    int n;
    cin >> n;
    int t = n / 3;
    if(n > 3*t) cout << 2*t+1;
    else cout << 2*t;
    return 0;
}
