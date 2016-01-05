#include <stdio.h>

int main ()
{
	char c;
	while (1) {
		c = getchar();
		if (c == '#') ungetc ('@', stdin);
		else ungetc (c, stdin);
		printf("%c", c);
		if(c = 'a')
			break;
	}
	return 0;
}

