#include <stdio.h>
#include <math.h>

int GCD( int x, int y );
int Recursive_GCD( int x, int y );

int main()
{
	int x, y;
	scanf( "%d%d", &x, &y );
	printf( "Results of calling GCD function: %d\n", GCD( x, y ) );
	printf( "Results of calling Recursive_GCD function: %d", Recursive_GCD( x, y ) );
	return 0;
}

int GCD( int x, int y )
{
	while ( x != y )
	{
		if ( x > y )
			x -= y;
		else
			y -= x;
	}
	return x;
}

int Recursive_GCD( int x, int y )
{
	if ( x == y )
		return x;
	else if ( x > y )
		return Recursive_GCD( x-y, y );
	else if ( x < y )
		return Recursive_GCD( x, y-x );
}
