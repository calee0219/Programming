#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int m[100000];
    long long int sum = 0;
	size_t i;
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &m[i]);
        sum += m[i];
    }
	int bavg = 0, savg = 0;
	if(sum % n != 0)
		bavg = 1;
    savg = sum / n;
	bavg += savg;
    long long int ans1 = 0;
	long long int ans2 = 0;
    for(i = 0; i < n; ++i)
    {
        if(m[i] < savg)
            ans1 += savg - m[i];
		else if(m[i] > savg)
			ans2 += m[i] - bavg;
    }
	if(ans2 > ans1)
		printf("%d", ans2);
	else
		printf("%d", ans1);
    return 0;
}

