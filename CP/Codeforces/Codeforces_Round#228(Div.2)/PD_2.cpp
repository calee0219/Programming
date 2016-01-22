#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	cin >> k;
	int loop = (int)log(k) / log(2) + 1;
	int node = 2 + 3*loop+1 + k-pow(2, loop)*(loop*2-1);
	char matrix[1000][1000];
	for(int i = 1; i <= node; ++i)
	{
		for(int j = 1; j <= node; ++j)
		{
			if(i == j) matrix[i][j] = 'N';
			else if((i == 1 && j == 2) || (i == 2 && j == 1)) matrix[i][j] = 'N';
			else if((i == 1 && j == 3) || (i == 3 && j == 1) || (i == 2 && j == 4) || (i == 4 && j == 2)) matrix[i][j] = 'Y';
			else if(i > 4 && i < 3*loop+4 && j > 4 && j < 3*loop+4)
			{
				if(j == 2*loop+i || i == 2*loop+j) matrix = 'Y';
				else if()
			}
			else matrix[i][j] = 'N';
		}
	}
	return 0;
}
