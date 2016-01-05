/************************************************************
* This program will do addition, subtraction, and multiply	*
* And you can input 2 number a and b less than 10^100		*
* The execution time must less then 1 second.				*
* Editor : Gavin Lee										*
* For HW by Prof. VincentS. Tseng							*
************************************************************/
#include <stdio.h>
#include <string.h>

/* prototypes */
void char_to_int();
void addition( char* a, int a_len, char* b, int b_len );
void subtraction( char* a, int a_len, char* b, int b_len );
void multiplication( char* a, int a_len, char* b, int b_len );

/************************************************************
* main : Scan a and b and call the function					*
* 			addition, subtraction, and multiplication		*
* 			then print a+b, a-b, and a*b					*
************************************************************/
int main()
{
	char a[100], b[100];
	int a_len, b_len;
	/* Check if a > b or not */
	int error = 0;
	do
	{
		if ( error )
			printf( "ERROR INPUT, a must bigger than b!!\n" );
		error = 1;
		printf( "Input a:" );
		scanf( "%s", a );
		printf( "Input b:" );
		scanf( "%s", b );
		a_len = strlen( a );
		b_len = strlen( b );
	}
	while ( a_len < b_len || ( a_len == b_len && strcmp( a, b ) < 0 ) );
	/* Change character into integer */
    char_to_int( a, a_len );
    char_to_int( b, b_len );
    /* addition of a and b */
    printf( "a+b=" );
    addition( a, a_len, b, b_len );
    /* subtraction of a and b */
    printf( "a-b=" );
    subtraction( a, a_len, b, b_len );
    /* multiplication of a and b */
    printf( "a*b=" );
    multiplication( a, a_len, b, b_len );
    return 0;
}
/************************************************************
* char_to_int : Transform characters into integers			*
* 			variables *array, len							*
* 			no return value									*
************************************************************/
void char_to_int( char* array, int len )
{
	while ( len-- )
		array[len] -= '0';
}
/************************************************************
* addition : To add two input number a and b				*
* 			variables *a, a_len, *b, b_len					*
*			print the addition of a and b out				*
* 			no return value									*
************************************************************/
void addition( char* a, int a_len, char* b, int b_len )
{
	int output[100] = {0};
	int len = a_len + 1;
	/* put a into output or we might change the value of *a */
	/* the reason we need output+1 is that addition may create at most one digit in the front */
	int i;
	for ( i = 0; i < a_len; i++ )
		output[i+1] = a[i];
	/* do the digit-addition */
	while( len-- )
	{
		if ( b_len )
		{
			b_len--;
			/* check if each digit of a add each digit of b will create a carry */
			if ( output[len] + b[b_len] > 9 )
				output[len-1] += 1;
			output[len] = ( output[len] + b[b_len] ) % 10;
		}
	}
	/* use che to check if there is a carry in front of the number or it's 0 */
	int che = 1;
	for ( i = 0; i <= a_len; i++ )
	{
		if ( che && output[i] == 0 );
		else
		{
			printf( "%d", output[i] );
			che = 0;
		}
	}
	if ( che )
		printf( "0" );
	printf( "\n" );
}
/************************************************************
* subtraction : To subtract two input number a from b		*
* 			variables *a, a_len, *b, b_len					*
*			print the subtraction of a and b out			*
* 			no return value									*
************************************************************/
void subtraction( char* a, int a_len, char* b, int b_len )
{
	int output[100];
	int len = a_len;
	/* put a into output or we might change the value of *a */
	int i;
	for ( i = 0; i < a_len; i++ )
		output[i] = a[i];
	/* do the digit-subtraction */
	while( a_len-- )
	{
		if ( b_len )
		{
			b_len--;
			/* see if each a need another 10 to do the subtraction */
			if ( output[a_len] - b[b_len] < 0 )
			{
				output[a_len-1]--;
				output[a_len] += 10 - b[b_len];
			}
			else
				output[a_len] -= b[b_len];
		}
	}
	/* use che to check if there is any 0 in front of the whole number */
	int che = 1;
	for ( i = 0; i < len; i++ )
	{
		if ( che && output[i] == 0 );
		else
		{
			printf( "%d", output[i] );
			che = 0;
		}
	}
	if ( che )
		printf( "0" );
	printf( "\n" );
}
/************************************************************
* multiplication : To multiply two input number a and b		*
* 			variables *a, a_len, *b, b_len					*
*			print the multiplication of a and b out			*
* 			no return value									*
************************************************************/
void multiplication( char* a, int a_len, char* b, int b_len )
{
	/* two dimensional array to save the product of each digit multiplication */
	int output[100][100] = {0};
	int total_len = 0;
	int ans[1000] = {0};
	a_len--;
	b_len--;
	/* do the digit-multiplication */
	int i, j;
	for ( i = a_len; i >= 0; i-- )
	{
		for ( j = b_len; j >= 0; j-- )
		{
			/* check if each product will create additional carry */
			if (  a[i] * b[j] > 9 )
				output[a_len-i][b_len-j+1] += ( a[i] * b[j] ) / 10;
			output[a_len-i][b_len-j] += ( a[i] * b[j] ) % 10;
		}
	}
	/* to sum up the product of each digit-multiplication */
	for ( i = 0; i <= a_len+1; i++ )
	{
		for ( j = 0; j <= b_len+1; j++ )
		{
			ans[i+j] += output[i][j];
			if ( ans[i+j] > 9 )
			{
				ans[i+j+1] += ans[i+j] / 10;
				ans[i+j] %= 10;
			}
			/* to recode the highest bit of the total product */
			if ( i + j > total_len && ans[i+j] )
				total_len = i + j;
		}
	}
	for ( i = total_len; i >= 0; i-- )
		printf( "%d", ans[i] );
	printf( "\n" );
}
