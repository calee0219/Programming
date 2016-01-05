#include <stdio.h>
#include <stdlib.h>

/** prototype of three recognisers **/
void recogniser1();
void recogniser2();

void sign(void); void integer(void); void fraction(void); void error(void); void real(void);

int main() {
    int input;
    while((input = getchar()) != EOF) {
        ungetc(input, stdin);
        int recogniser = rand() % 2;
        switch(recogniser) {
            case 0: recogniser1();
                break;
            case 1: recogniser2();
                break;
        }
    }
    return 0;
}


/** Start of Recogniser 1 **/
void recogniser1() {
	sign();
}
/** End of Recogniser 1 **/
void sign(void)
{
    switch(getchar()) {
    case '+': case '-':
		sign(); return;
	case '.':
		fraction(); return;
    case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		integer(); return;
    case '\n': printf("Rejected by method 1\n"); return;
    }
}

void integer(void)
{
    switch(getchar()) {
    case '+': case '-':
		error(); return;
	case '.':
		real(); return;
    case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		integer(); return;
    case '\n': printf("Rejected by method 1\n"); return;
    }
}

void fraction(void)
{
    switch(getchar()) {
    case '+': case '-':
	case '.':
		error(); return;
    case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		real(); return;
    case '\n': printf("Rejected by method 1\n"); return;
    }
}

void error(void)
{
    switch(getchar()) {
    case '+': case '-':
	case '.':
    case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		error(); return;
    case '\n': printf("Rejected by method 1\n"); return;
    }
}

void real(void)
{
	switch(getchar()) {
    case '+': case '-':
	case '.':
    	error(); return;
    case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		real(); return;
    case '\n': printf("Accepted by method 1\n"); return;
    }
}


/** Start of Recogniser 2**/
void recogniser2() {
	const int sign = 0,
              integer = 1,
              fraction = 2,
              real = 3,
              error = 4;
    int ch;
    int condition = sign;
    while((ch=getchar()) != '\n')
        if ( condition == sign ) {
			if ( ch == '+' || ch == '-' )
				condition = sign;
			else if ( ch >= '0' && ch <= '9' )
				condition = integer;
			else if ( ch = '.' )
				condition = fraction;
        }
        else if ( condition == integer ) {
			if ( ch == '+' || ch == '-' )
				condition = error;
			else if ( ch >= '0' && ch <= '9' )
				condition = integer;
			else if ( ch = '.' )
				condition = real;
        }
        else if ( condition == fraction ) {
        	if ( ch == '+' || ch == '-' )
				condition = error;
			else if ( ch >= '0' && ch <= '9' )
				condition = real;
			else if ( ch = '.' )
				condition = error;
        }
        else if ( condition == real ) {
        	if ( ch == '+' || ch == '-' )
				condition = error;
			else if ( ch >= '0' && ch <= '9' )
				condition = real;
			else if ( ch = '.' )
				condition = error;
        }
        else if ( condition == error ) {
			if ( ch == '+' || ch == '-' )
				condition = error;
			else if ( ch >= '0' && ch <= '9' )
				condition = error;
			else if ( ch = '.' )
				condition = error;
        }
    if( condition == real ) printf( "Accepted by method 2\n" );
    else printf( "Rejected by method 2\n" );
}
/** End of Recogniser 2 **/
