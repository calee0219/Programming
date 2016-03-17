/*************************************************************************
	> File Name: skyscrapers.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年03月16日 (週三) 19時14分38秒
 ************************************************************************/

#include <bits/stdc++.h>
#define BIG_NUM 1000000007LL
using namespace std;
typedef long long LL;

int r, l, n;
LL C[5000][5000];
LL M[5000][5000];

int main()
{
    C[0][0] = 1;
    //cout << M[1][0];
    for(int i = 1; i < 5000+1; ++i)
    {
        C[i][0] = 1LL;
        for(int j = 1; j <= i; ++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j] % BIG_NUM;
    }
    //memset(M,0,sizeof(M));
    //cout << M[1][0] << endl;
    for(int i = 0; i < 5003; ++i)
    {
        M[i][i] = 1LL;
        for(int j = 1; j <= i; ++j)
            M[i][j] = (M[i-1][j-1] + (i-1)*M[i-1][j]) % BIG_NUM;
    }
    while(~scanf("%d%d%d", &n, &r, &l) && n && r && l)
    {
        LL ans = 0LL;
        for(int i = 0; i < n; ++i)
            ans = (ans + M[i][r-1] * M[n-i-1][l-1] * C[n-1][i]) % BIG_NUM;
        printf("%lld\n", ans);
    }
    return 0;
}
