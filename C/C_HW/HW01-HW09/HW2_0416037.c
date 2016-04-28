#include <stdio.h>

int main()
{
	int n;
	int deficient = 0, perfect = 0, abundant = 0;
	printf( "Please input N:" );
	scanf( "%d", &n );
	int i;
	for ( i = 2; i <= n; i++ )
	{
		int ii;
		int tmp = 1;
		for ( ii = 2; ii < i; ii++ )
		{
			if ( i % ii == 0 )
			{
				tmp += ii;
			}
		}
		if ( tmp > i )
			abundant++;
		else if ( tmp == i )
			perfect++;
		else
			deficient++;
	}
	printf( "DEFICIENT:%d\nPERFECT:%d\nABUNDANT:%d", deficient, perfect, abundant );
	return 0;
}
