#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	bool check[1010] = {0};
	cin >> n >> m;
	int min = 0;
	bool che = true;
	while(n--)
	{
		char c;
		int g = 0, s = 0;
		for(int i = 0; i < m; ++i)
		{
			cin >> c;
			if(c == 'G')
				g = i;
			if(c == 'S')
				s = i;
		}
		if(g <= s)
		{
			if(check[s-g] == 0)
				min++;
			check[s-g] = 1;
		}
		else
		{
			che = 0;
			break;
		}
	}
	if(che == 0)
		cout << -1;
	else
		cout << min;
	return 0;
}

