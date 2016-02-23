/*************************************************************************
	> File Name: Educational_Codeforces_Round_3#A.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月06日 (週三) 03時12分00秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a[1000];
    size_t i;
    for(i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);
    for(i = 0; i < n; ++i)
    {
        if(m > 0)
            m -= a[i];
        else
            break;
    }
    printf("%d", i);
    return 0;
}

