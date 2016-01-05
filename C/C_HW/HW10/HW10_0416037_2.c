#include <stdio.h>
#include <string.h>

int save[100001];

int main()
{
	char c;
	int kkk = 0;
	while((c = getchar()) != '0')
	{
		if(kkk)
			printf("\n");
		kkk = 1;
		memset(save, 0, 100001*sizeof(int));
		size_t ord = 0;
		int num[100001] = {0};
		while(c != '\n')
		{
			while(c == ' ')
				c = getchar();
			num[ord] *= 10;
			num[ord] += c - '0';
			if((c = getchar()) == ' ')
			{
				save[num[ord]]++;
				while((c = getchar()) == ' ');
				if(c != '\n')
				ord++;
			}
		}
		save[num[ord]]++;
		ord++;
		int che = 0;
		size_t i;
		for(i = 0; i < ord; ++i)
		{
			if(num[i] >= ord)
			{
				che = 1;
				printf("Message hacked by the Martians!!!");
				break;
			}
		}
		if(che)
			continue;
		for(i = 0; i < ord; ++i)
		{
			num[i] = -1;
			if(save[i])
			{
				num[i] = i;
				save[i]--;
			}
		}
		size_t j = 0;
		int kk = 0;
		for(i = 0; i < ord; ++i)
		{
			for(; j < ord; ++j)
			{
				if(num[i] == -1)
				{
					if(save[j])
					{
						save[j]--;
						num[i] = j;
						break;
					}
				}
				else
					break;
			}
			if(kk)
				printf(" ");
			kk = 1;
			printf("%d", num[i]);
		}
	}
	return 0;
}

