#include <bits/stdc++.h>
using namespace std;

char m[4][4];

int main()
{
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j)
            cin >> m[i][j];
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(m[i][j] == '#' && m[i+1][j] == '#' && m[i][j+1] == '#' && m[i+1][j+1] == '#') {
                cout << "YES";
                return 0;
            }
            if(m[i+1][j] == '#' && m[i][j+1] == '#' && m[i+1][j+1] == '#') {
                cout << "YES";
                return 0;
            }
            if(m[i][j] == '#' && m[i][j+1] == '#' && m[i+1][j+1] == '#') {
                cout << "YES";
                return 0;
            }
            if(m[i][j] == '#' && m[i+1][j] == '#' && m[i+1][j+1] == '#') {
                cout << "YES";
                return 0;
            }
            if(m[i][j] == '#' && m[i+1][j] == '#' && m[i][j+1] == '#') {
                cout << "YES";
                return 0;
            }
            if(m[i][j] == '.' && m[i+1][j] == '.' && m[i][j+1] == '.' && m[i+1][j+1] == '.') {
                cout << "YES";
                return 0;
            }
            if(m[i+1][j] == '.' && m[i][j+1] == '.' && m[i+1][j+1] == '.') {
                cout << "YES";
                return 0;
            }
            if(m[i][j] == '.' && m[i][j+1] == '.' && m[i+1][j+1] == '.') {
                cout << "YES";
                return 0;
            }
            if(m[i][j] == '.' && m[i+1][j] == '.' && m[i+1][j+1] == '.') {
                cout << "YES";
                return 0;
            }
            if(m[i][j] == '.' && m[i+1][j] == '.' && m[i][j+1] == '.') {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
