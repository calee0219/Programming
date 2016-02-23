#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x, y, z, p;
	int xa, ya;
	scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
	y &= 1;
	if(y)
		z = (z+x) % 4;
	else
		z = (z-x) % 4;
	if(z < 0)
		z += 4;
	for(int i = 0; i < p; ++i)
	{
		int nt = n;
		int mt = m;
		int zt = z;
		scanf("%d%d", &xa, &ya);
		if(y)
			ya = mt+1 - ya;
		while(zt--)
		{
			int tmp = ya;
			ya = xa;
			xa = mt+1 - tmp;
			tmp = nt;
			nt = mt;
			mt = tmp;
		}
		printf("%d %d\n", xa, ya);
	}
	return 0;
}

