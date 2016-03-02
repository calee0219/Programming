#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int l;
        scanf("%d", &l);
        int a[1000000], b[1000000];
        for(int i = 0; i < l; ++i)
        {
            int ta, tb;
            scanf("%d%d", &ta, &tb);
            a[i] = ta;
            b[i] = tb;
        }
        int mina = 0-a[0];
        int minb = 0-b[0];
        for(int i = 1; i < l; ++i)
        {
            mina=min(mina, i-a[i]);
            minb=min(minb, i-b[i]);
        }
        int m = mina+minb;
        for(int i = l-1; i >= 0; --i)
        {
            mina=min(mina, i-a[i]);
            minb=min(minb, i-b[i]);
        }
        m = min(m, mina+minb);
        printf("K prechodu reky je treba %d pontonu\n", &m);
    }
    return 0;
}
