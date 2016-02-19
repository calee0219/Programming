#include <bits/stdc++.h>
using namespace std;

int s[1000000];

int f(int i);

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int i;
		cin >> i;
		cout << f(i) << endl;
	}
	return 0;
}

int f(int i)
{
	if(s[i] != 0)
		return s[i];
	if(i < 1000)
	{
		s[i] = f(f(i*3)+1);
		return s[i];
	}
	else
	{
		s[i] = i - 10;
		return s[i];
	}
}

