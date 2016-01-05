#include <stdio.h>
#include <string.h>
char str[65];

int output_number()
{
	int str_len = strlen( str );
	int sum = 0;
	int i;
	for ( i = 0; i < str_len-1; i++ )
		sum += 2 * (int)str[i];
	return sum;
}

int main()
{
	while ( 1 )
	{
		int wonderful = 0, ugly = 0;
		printf( "Input a name: " );
		scanf( "%s", str );
		int num = output_number();
		int num_che = num;
		while ( num_che != 0 )
		{
			switch ( num_che % 10 )
			{
			case 0:
			case 1:
			case 8:
				wonderful = 1;
				break;
			default:
				ugly = 1;
				break;
			}
			num_che /= 10;
			if ( wonderful && ugly )
				break;
		}
		if ( wonderful && ugly )
			printf( "Common, %d\n", num );
		else if ( ugly )
			printf( "Ugly, %d\n", num );
		else
			printf( "Wonderful, %d\n", num );
	}
	return 0;
}
