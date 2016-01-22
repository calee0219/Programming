#include <bits/stdc++.h>
using namespace std;

int s[100000];
int range = 0;

int tower(int n);

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		cout << tower(n) << endl;
	}
	return 0;
}

int tower(int n)
{
	if(n == 1)
	{
		s[1] = 1;
		return s[1];
	}
	else
	{
		if(range != 0)
		{
			n %= (range-1);
			return s[n];
		}
		if(n < 100000)
		{
			if(s[n] != 0)
				return s[n];
			s[n] = (2 * tower(n-1) + 1) % 100000007;
			if(s[n] == 1)
				range = n;
			return s[n];
		}
		else
			return (2 * tower(n-1) + 1) % 100000007;
	}
}

