#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string s;
	while(t--)
	{
		cin >> s;
		int ord = 0;
		int ans[12];
		for(int i = 1; i <= 12; ++i)
		{
			if(12 % i == 0)
			{
				bool check = false;
				for(int j = 0; j < i; ++j)
				{
					bool che = true;
					for(int k = 0; k < 12/i; ++k)
					{
						if(s[j+i*k] == 'O')
						{
							che = false;
							break;
						}
					}
					if(che)
					{
						check = true;
						break;
					}
				}
				if(check)
				{
					ans[ord] = i;
					ord++;
				}
			}
		}
		printf("%d ", ord);
		for(int i = --ord; i >= 0; --i)
			printf("%dx%d ", 12/ans[i], ans[i]);
		printf("\n");
	}
	return 0;
}

