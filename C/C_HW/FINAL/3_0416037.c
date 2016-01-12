#include <stdio.h>

char a[100+1];
int ord;
int len;

int check()
{
    while(ord < len)
    {
        if(a[ord] == '(')
        {
            ord++;
            if(check() == 0) return 0;
            ord++;
            if(a[ord-1] == ')') return 1;
            else if(a[ord] == '(' || a[ord] == '[' || a[ord] == '{' || a[ord] == '<') {ord++; if(check() == 0) return 0;}
            else return 0;
        }
        else if(a[ord] == '[')
        {
            ord++;
            if(check() == 0) return 0;
            ord++;
            if(a[ord-1] == ']') return 1;
            else if(a[ord] == '(' || a[ord] == '[' || a[ord] == '{' || a[ord] == '<') {ord++; if(check() == 0) return 0;}
            else return 0;
        }
        else if(a[ord] == '{')
        {
            ord++;
            if(check() == 0) return 0;
            ord++;
            if(a[ord-1] == '}') return 1;
            else if(a[ord] == '(' || a[ord] == '[' || a[ord] == '{' || a[ord] == '<') {ord++; if(check() == 0) return 0;}
            else return 0;
        }
        else if(a[ord] == '<')
        {
            ord++;
            if(check() == 0) return 0;
            ord++;
            if(a[ord-1] == '>') return 1;
            else if(a[ord] == '(' || a[ord] == '[' || a[ord] == '{' || a[ord] == '<') {ord++; if(check() == 0) return 0;}
            else return 0;
        }
        return 1;
    }
    return 1;
}

int main()
{
    scanf("%s", a);
    while(a[0] != '0')
    {
        ord = 0;
        len = strlen(a);
        if(check())
            printf("Correct");
        else
            printf("Error");
        printf("\n");
        scanf("%s", a);
    }
    return 0;
}
