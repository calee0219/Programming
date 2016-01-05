#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = a; i <= b; ++i)
	{
		if(i % 4 == 0) continue;
		int sum = 0;
		int tmp = i;
		while(tmp)
		{
			if(sum > 1) break;
			if(tmp & 1);
			else
				sum++;
			tmp >>= 1;
		}
		if(sum == 1)
			ans++;
	}
	cout << ans;
	return 0;
}
