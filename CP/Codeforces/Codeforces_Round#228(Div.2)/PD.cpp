#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << n+2 << endl;
	for(int i = 0; i < n+2; ++i)
	{
		for(int j = 0; j < n+2; ++j)
		{
			if(i == j) cout << 'N';
			else if(i == 0 && j != 1) cout << 'Y';
			else if(i == 1 && j != 0) cout << 'Y';
			else if(j == 0 && i != 1) cout << 'Y';
			else if(j == 1 && i != 0) cout << 'Y';
			else cout << 'N';
		}
		cout << endl;
	}
	return 0;
}
