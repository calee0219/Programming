/*************************************************************************
	> File Name: Educational_Codeforces_Round_3#B.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月06日 (週三) 03時12分59秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, m;
    scanf("%d%d", &n, &m);
    long long int a[11] = {0};
    size_t i;
    for(i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        a[tmp]++;
    }
    long long int sum = n * (n-1) / 2;
    for(i = 1; i <= m; ++i)
    {
        sum -= a[i] * (a[i]-1) / 2;
    }
    printf("%d", sum);
    return 0;
}

