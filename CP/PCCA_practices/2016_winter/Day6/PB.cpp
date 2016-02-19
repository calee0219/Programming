/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 10時11分41秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int N;
int sum[100010];

int main()
{
    cin >> N;
    for(int i = 1; i <= N+1; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        sum[i] = sum[i-1] + tmp;
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        int low = lower_bound(sum+1, sum+N+2, tmp) - sum;
        printf("%d\n", N-low+1);
    }
    return 0;
}

