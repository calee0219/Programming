#include <stdio.h>

double number[10000];

void value( int length );
void integer( int length );
void decimal( int length );

int main()
{
    int i = -1;
    do {
        i++;
        scanf( "%lf", &number[i] );
    } while ( number[i] != 0 );
    printf( "Longest sequence with equal values: " );
    value( i );
    printf( "\nLongest sequence with same integer part: " );
    integer( i );
    printf( "\nLongest sequence with same decimal part: " );
    decimal( i );
    return 0;
}

void value( int length )
{
	int check_number = 0;
	int max = 0;
	int i, j;
	for ( i = 0; i < length; i++ )
	{
		int check = 1;
		for ( j = i+1; j < length; j++ )
		{
			if ( number[i] == number[j] )
			{
				check++;
			}
			else
				break;
		}
		if ( check > max )
		{
			max = check;
			check_number = i;
		}
	}
	printf( "(" );
	int che = 0;
	for ( i = check_number; i < max; i++ )
	{
		if ( che )
			printf( ", " );
		che = 1;
		printf( "%.3f", number[check_number] );
	}
	printf( ")" );
	printf( " length: %d", max );
}

void integer( int length )
{
	int check_number = 0;
	int max = 0;
	int i, j;
	for ( i = 0; i < length; i++ )
	{
		int check = 1;
		for ( j = i+1; j < length; j++ )
		{
			if ( (int)number[i] == (int)number[j] )
			{
				check++;
			}
			else
				break;
		}
		if ( check > max )
		{
			max = check;
			check_number = i;
		}
	}
	printf( "(" );
	int che = 0;
	i = 0;
	for ( i = check_number; i < length; i++ )
	{
		if ( (int)number[i] == (int)number[check_number])
		{
			if ( che )
				printf( ", " );
			che = 1;
			printf( "%.3f", number[i] );
		}
		else
			break;
	}
	printf( ")" );
	printf( " length: %d", max );
}

void decimal( int length )
{
	int check_number = 0;
	int max = 0;
	int i, j;
	for ( i = 0; i < length; i++ )
	{
		int check = 1;
		for ( j = i+1; j < length; j++ )
		{
			if ( number[i]-(int)number[i]+0.0000000001 >= number[j]-(int)number[j] && number[i]-(int)number[i]-0.0000000001 <= number[j]-(int)number[j] )
			{
				check++;
			}
			else
				break;
		}

		if ( check > max )
		{
			max = check;
			check_number = i;
		}
	}
	printf( "(" );
	int che = 0;
	for ( i = check_number; i < length; i++ )
	{
		if ( number[i]-(int)number[i]+0.0000000001 >= number[check_number]-(int)number[check_number] && number[i]-(int)number[i]-0.0000000001 <= number[check_number]-(int)number[check_number] )
		{
			if ( che )
				printf( ", " );
			che = 1;
			printf( "%.3f", number[i] );
		}
		else
			break;
	}
	printf( ")" );
	printf( " length: %d", max );
}
