#include <stdio.h>
#include <string.h>

int check[1000000], save[1000000];

int list_check(int now, int lenth, int* num);

int main()
{
	char c;
	while((c = getchar()) != '0')
	{
		size_t ord = 0;
		int num[1000000] = {0};
		while(c != '\n')
		{
			num[ord] *= 10;
			num[ord] += c - '0';
			if((c = getchar()) == ' ')
			{
				ord++;
				while((c = getchar()) == ' ');
			}
		}
		memset(check, 0, (ord+1)*sizeof(int));
		memset(save, 0, (ord+1)*sizeof(int));
		int che = 0;
		size_t i;
		for(i = 0; i <= ord; ++i)
		{
			if(num[i] > ord)
			{
				che = 1;
				printf("Message hacked by the Martians!!!\n");
				break;
			}
		}
		if(che)
			continue;
		if(list_check(0, ord+1, num) == 0)
			printf("Message hacked by the Martians!!!\n");
	}
	return 0;
}

int list_check(int now, int lenth, int* num)
{
	if(now == lenth)
	{
		size_t i;
		for(i = 0; i < lenth; ++i)
		{
			if(num[save[num[save[i]]]] != num[save[i]])
				return 0;
		}
		for(i = 0; i < lenth; ++i)
			printf("%d ", num[save[i]]);
		printf("\n");
		return 1;
	}
	size_t i;
	for(i = 0; i < lenth; ++i)
	{
		if(check[i] == 0)
		{
			check[i] = 1;
			save[now] = i;
			if(list_check(now+1, lenth, num))
				return 1;
			check[i] = 0;
		}
	}
	return 0;
}

