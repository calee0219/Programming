#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string str;
	cin >> n >> str >> str;
	if(str == "week")
	{
		if(n == 5 || n == 6)
			cout << 53;
		else
			cout << 52;
	}
	else
	{
		if(n >= 0 && n <= 29)
			cout << 12;
		else if(n == 30)
			cout << 11;
		else
			cout << 7;
	}
	return 0;
}
