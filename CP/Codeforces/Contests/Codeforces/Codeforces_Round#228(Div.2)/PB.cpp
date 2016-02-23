#include <iostream>
using namespace std;

char m[100][100];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			cin >> m[i][j];
	}
	for(int i = 0; i < n-2; ++i)
	{
		for(int j = 0; j < n-1; ++j)
		{
			if(m[i][j] == '#')
			{
				if(m[i+1][j-1] == '#' && m[i+1][j] == '#' && m[i+1][j+1] == '#' && m[i+2][j] == '#')
				{
					m[i][j] = '.'; m[i+1][j-1] = '.'; m[i+1][j] = '.'; m[i+1][j+1] = '.'; m[i+2][j] = '.';
				}
			}
		}
	}
	bool ans = true;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(m[i][j] == '#')
				ans = false;
	if(ans)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
