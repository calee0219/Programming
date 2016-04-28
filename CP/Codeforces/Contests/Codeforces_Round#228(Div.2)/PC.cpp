#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int x[101];
	for(int i = 0; i < n; ++i)
		cin >> x[i];
	sort(&x[0], &x[n]);
	int p = 0;
	int check = 1;
	for(int i = 0; i < n && check; ++i)
	{
		int cnt = 0;
		check = 0;
		for(int j = 0; j < n; ++j)
		{
			if(x[j] == -1) continue;
			if(x[j] >= cnt)
			{
				cnt++;
				x[j] = -1;
			}
			check = 1;
		}
		if(cnt) p++;
	}
	cout << p;
	return 0;
}
