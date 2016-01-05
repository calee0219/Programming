#include <stdio.h>
#include <time.h>

int main()
{
	srand( time( NULL ) );
	int computer, human, times;
	int win = 0, lose = 0, drow = 0;
	printf( "Please input the round you want to play: " );
	scanf( "%d", &times );
	int i;
	for ( i = 0; i < times; i++ )
	{
		computer = rand() % 3;
		printf( "#Please threw the Fist you want, 1=scissors 2=stone 3=paper: " );
		scanf( "%d", &human );
		human--;
		printf( "You threw " );
		switch ( human )
		{
		case 0:
			printf( "scissors, Computer threw " );
			switch ( computer )
			{
			case 0:
				printf( "scissors, DROW!!\n" );
				drow++;
				break;
			case 1:
				printf( "stone, YOU LOSE!!\n" );
				lose++;
				break;
			case 2:
				printf( "paper, YOU WIN!!\n" );
				win++;
				break;
			}
			break;
		case 1:
			printf( "stone, Computer threw " );
			switch ( computer )
			{
			case 0:
				printf( "scissors, YOU WIN!!\n" );
				win++;
				break;
			case 1:
				printf( "stone, DROW!!\n" );
				drow++;
				break;
			case 2:
				printf( "paper, YOU LOSE!!\n" );
				lose++;
				break;
			}
			break;
		case 2:
			printf( "paper, Computer threw " );
			switch ( computer )
			{
			case 0:
				printf( "scissors, YOU LOSE!!\n" );
				lose++;
				break;
			case 1:
				printf( "stone, YOU WIN!!\n" );
				win++;
				break;
			case 2:
				printf( "paper, DROW!!\n" );
				drow++;
				break;
			}
			break;
		}
	}
	printf( "WIN: %d\nLOSE: %d\nDROW: %d", win, lose, drow );
	return 0;
}
