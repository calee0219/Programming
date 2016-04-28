/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月17日 (週三) 15時21分07秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long sum[100010] = {0};
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n, m;
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; ++i)
        {
            long long int tmp;
            scanf("%lld",&tmp);
            if(i == 1)
                sum[i] = tmp;
            else
                sum[i] = sum[i-1] + tmp;
        }
        while(m--)
        {
            int a, b;
            scanf("%d %d",&a,&b);
            //if(a == 1)
                //cout << sum[b] << endl;
            //else
                printf("%lld\n",sum[b]-sum[a-1]);
        }
    }
}
