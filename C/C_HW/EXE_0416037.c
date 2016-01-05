#include <stdio.h>

int main()
{
	int date, age, year;
	printf( "What's the year this year: " );
	scanf( "%d", &year );
	printf( "What is your birth year: " );
	scanf( "%d", &date );
	age = year - date;
	while ( age > 150 || age < 1 )
	{
		printf( "Your age is %d\n", age );
		printf( "Sorry, I think you type a wrong answer!\nPlease input again:\n" );
		printf( "What's the year this year: " );
		scanf( "%d", &year );
		printf( "What is your birth year: " );
		scanf( "%d", &date );
		age = year - date;
	}
    printf( "Hello. You are %d years old.", age );
    return 0;
}
