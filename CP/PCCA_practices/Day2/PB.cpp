#include <bits/stdc++.h>
using namespace std;

long long int tower(int n);

int main()
{
	int n;
	while(~scanf("%d", &n))
		cout << tower(n)-1 << endl;
	return 0;
}

long long int tower(int n)
{
    long long int a = 2;
    long long int ans = 1;
    while(n)
    {
        if(n & 1)
            ans *= a;
        n >>= 1;
        a *= a;
    }
    return ans;
}
