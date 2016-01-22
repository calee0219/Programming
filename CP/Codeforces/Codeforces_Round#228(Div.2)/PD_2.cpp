#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	cin >> k;
	int sq = sqrt(k);
	int cont = 0;
	for(int i = 0; i <= 2*sq+4; ++i)
	{
		for(int j = 0; j <= 2*sq+4; ++j)
		{
			if(i == 0 && (j>= 2 && j <= sq+3)) cout << 'Y';
			else if(i == 1 && (j >= sq+4 && j <= 2*sq+4)) cout << 'Y';
			else if(j == 0 && (i>= 2 && i <= sq+3)) cout << 'Y';
			else if(j == 1 && (i >= sq+4 && i <= 2*sq+4)) cout << 'Y';
			else if(cont < k)
			{

			}
			else
		}
	}
}
