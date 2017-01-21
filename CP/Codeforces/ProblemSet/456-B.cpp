#include <bits/stdc++.h>
using namespace std;

int toInt(char c)
{
    return c-'0';
}

int main()
{
    string str;
    cin >> str;
    int size = str.length();
    int num = toInt(str[size-1]) + 10*toInt(str[size-2]);
    if(num%4) cout << 0;
    else cout << 4;
    return 0;
}
