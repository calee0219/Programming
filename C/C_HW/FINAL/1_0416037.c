#include <stdio.h>

long long int ans = 1;

void recursive(int i)
{
    if(i <= 1)
        return;
    ans *= i;
    recursive(i-1);
    return;
}

int main()
{
    printf("Please input a number: ");
    int i;
    scanf("%d", &i);
    recursive(i);
    printf("The answer: ");
    printf("%lld", ans);
    return 0;
}
