#include <stdio.h>

int main()
{
    char str = getchar();
    while ( str != '\n' )
    {
        if ( str >= 'A' && str <= 'Z' )
            printf( "%02d", str-'A'+1 );
        else if ( str >= 'a' && str <= 'z' )
            printf( "%02d", 'a'-str+52 );
        else if ( str >= '0' && str <= '9' )
            printf( "%02d", str-'0'+90 );
        else if ( str == ' ' )
            printf( "#" );
        else
            printf( "*" );
        str = getchar();
    }
    return 0;
}
