/*************************************************************************
	> File Name: Codeforces_Round#339(Div.2)#A.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 2016年01月15日 上午 12:16:14
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL pow_a(LL a, LL b)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    LL l, r, k;
    cin >> l >> r >> k;
    int tmp = l;
    int i;
    for(i = 0; tmp; ++i)
		tmp /= k;
    bool che = true;
    for(i = pow_a(k, i-1);; i *= k)
	{
		if(i < l) continue;
		if(i > r) break;
		cout << i << ' ';
		che = false;
	}
	if(che)
		cout << -1;
    return 0;
}

