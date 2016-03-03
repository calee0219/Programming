#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    while(~scanf("%d%d", &x, &y))
    {
        printf("%d %d ", x, y);
        if(x > y)
        {
            int tmp = x;
            x = y;
            y = tmp;
        }
        int m = 0;
        for(int i = x; i <= y; ++i)
        {
            int cnt = 1;
            int tmp = i;
            while(tmp != 1)
            {
            if(tmp&1)
            {
                tmp = (tmp*3+1)/2;
                cnt += 2;
            }
            else
            {
                tmp /= 2;
                cnt++;
            }
            }
            m = max(cnt, m);
        }
        printf("%d\n", m);
    }
    return 0;
}
