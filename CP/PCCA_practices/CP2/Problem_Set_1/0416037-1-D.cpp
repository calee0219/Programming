/*************************************************************************
	> File Name: PE.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月17日 (週三) 15時34分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int x, y;
        cin >> x >> y;
        while(true)
        {
            bool check = false;
            int d;
            string mv;
            cin >> mv;
            switch(mv[0]) {
            case 'L':
                cin >> d;
                x -= d;
                break;
            case 'U':
                cin >> d;
                y += d;
                break;
            case 'R':
                cin >> d;
                x += d;
                break;
            case 'D':
                cin >> d;
                y -= d;
                break;
            default:
                check = true;
            }
            if(check)
                break;
        }
        cout << x << ' ' << y << endl;
    }
    return 0;
}
