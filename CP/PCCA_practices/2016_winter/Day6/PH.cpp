/*************************************************************************
	> File Name: PH.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 12時43分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int x = 0, y = 0;
        char c;
        cin >> c;
        while(c != '\n')
        {
            while(c != '\n' && c < '0' || c > '9') c = getchar();
            int num = 0;
            while(c != '\n' && c >= '0' && c <= '9')
            {
                num *= 10;
                num += c-'0';
                c = getchar();
            }
            switch(c) {
            case 'u': case 'U':
                y += num;
                break;
            case 'd': case 'D':
                y -= num;
                break;
            case 'r': case 'R':
                x += num;
                break;
            case 'l': case 'L':
                x -= num;
                break;
            }
            if(c != '\n')
                c = getchar();
        }
        cout << x << ' ' << y << endl;
    }
    return 0;
}

