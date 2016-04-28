/*************************************************************************
	> File Name: PF.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: Wed 23 Mar 2016 06:39:44 PM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    while(cin.peek() != '#')
    {
        int h = 0, m = 0;
        while(true)
        {
            if(cin.peek() == '$')
                break;
            char c;
            cin >> c;
            if(c == '-')
            {
                int n;
                if(cin.peek() <= '9' && cin.peek() >= '0')
                {
                    cin >> n;
                    h -= n;
                }
                getchar();
                if(cin.peek() <= '9' && cin.peek() >= '0')
                {
                    cin >> n;
                    m -= n;
                }
            }
            else
            {
                int n;
                if(cin.peek() <= '9' && cin.peek() >= '0')
                {
                    cin >> n;
                    h += n;
                }
                getchar();
                if(cin.peek() <= '9' && cin.peek() >= '0')
                {
                    cin >> n;
                    m += n;
                }
            }
            while(m >= 60)
            {
                m -= 60;
                h++;
            }
            while(m < 0)
            {
                m += 60;
                h--;
            }
            printf("%d:%02d\n", h, m);
        }
        cin >> str;
    }
    return 0;
}
