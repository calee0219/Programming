#include <stdio.h>

int a[1000000], b[1000000], t[1000000], c[1000000];

int main()
{
    int n, m, k, s;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    size_t i, j;
    for(i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for(i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    for(i = 0; i < m; ++i)
    {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
    }
    return 0;
}
