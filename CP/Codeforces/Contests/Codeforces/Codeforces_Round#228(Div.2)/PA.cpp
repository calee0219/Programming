#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int x[100];
	for(int i = 0; i < n; ++i)
		cin >> x[i];
	int che = 1;
	while(che)
	{
		for(int i = 0; i < n && che; ++i)
		{
			for(int j = 0; j < n && che; ++j)
			{
				if(x[i] > x[j])
					x[i] -= x[j];
				else if(x[i] < x[j])
					x[j] -= x[i];
				else
				{
					int check = 0;
					for(int k = 0; k < n-1; ++k)
						if(x[k] == x[k+1])
							check++;
					if(check == n-1)
						che = 0;
				}
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < n; ++i)
		sum += x[i];
	cout << sum;
	return 0;
}
