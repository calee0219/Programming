/*************************************************************************
	> File Name: PC.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月17日 (週三) 15時22分16秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int ans = 0;
    char c[100000];
    while(gets(c))
    {
        char* pch;
        pch = strtok (c, " ");
        while (pch != NULL)
        {
            int tmp = 0;
            for(int i = 0; i < strlen(pch); ++i)
            {
                tmp *= 10;
                tmp += pch[i] - '0';
            }
            ans += tmp;
            pch = strtok (NULL, " ");
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
