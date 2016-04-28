#include <stdio.h>

int main()
{
	int n;
	printf( "Enter a 5-digit integer: " );
	scanf( "%d", &n );
	int str[6];
	int i;
	for ( i = 0; i < 5; i++ )
	{
		str[i] = n % 10;
		n /= 10;
	}
	str[5] = n;
	if ( str[5] != 0 || str[4] == 0 )
		printf( "Your input is not a 5-digit integer. Exit" );
	else if ( str[0] == str[4] && str[1] == str[3] )
		printf( "It is a palindrome." );
	else
		printf( "It is not a palindrome" );
	return 0;
}
