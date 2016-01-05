#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int alen = a.length(), blen = b.length();
	int ans = 0;
	int one = 0, zero = 0;
	int i, j;
	for(i = 0; i < alen-1; ++i)
	{
		for(j = i; j >= i-(blen-alen) && j >= 0; --j)
		{
			if(a[j] != b[i])
				ans++;
		}
	}
	if(blen >= 2*alen-1)
	{
		for(i = 0; i < alen; ++i)
		{
			if(a[i] == '0')
				zero++;
			else
				one++;
		}
		for(i = alen-1; i <= blen-alen; ++i)
		{
			if(b[i] == '0')
				ans += one;
			else
				ans += zero;
		}
	}
	//for(i = blen-alen+1; i < blen; ++i)
	for(; i < blen; ++i)
	{
		int j;
		for(j = alen-1; j >= alen-(blen-i); --j)
		{
			if(a[j] != b[i])
				ans++;
		}
	}
	cout << ans;
    return 0;
}

