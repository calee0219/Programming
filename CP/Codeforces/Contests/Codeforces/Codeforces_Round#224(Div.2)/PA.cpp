/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月23日 (週六) 01時26分20秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char w1[100] = {'\0'}, w2[100] = {'\0'};
    scanf("%[^|]", w1);
    getchar();
    scanf("%[^\n]", w2);
    string str;
    cin >> str;
    int l = str.length() - abs((int)strlen(w1)-(int)strlen(w2));
    if(l < 0 || l & 1)
        printf("Impossible");
    else
    {
        if(strlen(w1) < strlen(w2))
        {
            cout << w1;
            for(int i = 0; i < str.length()-l/2; ++i)
                cout << str[i];
            cout << '|' << w2;
            for(int i = str.length()-l/2; i < str.length(); ++i)
                cout << str[i];
        }
        else
        {
            cout << w1;
            for(int i = 0; i < l/2; ++i)
                cout << str[i];
            cout << '|' << w2;
            for(int i = l/2; i < str.length(); ++i)
                cout << str[i];
        }
    }
    return 0;
}

