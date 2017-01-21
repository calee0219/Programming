#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c1, c2, r1, r2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    if(!(c1+c2 == r1+r2 && r1+r2 == d1+d2)) {
        cout << -1;
        return 0;
    }
    int a = (r1+c1-d2)/2;
    int b = (r1+c2-d1)/2;
    int c = (r2+c1-d1)/2;
    int d = (r2+c2-d2)/2;
    if(a == b || a == c || a == d || b == c || b == d || c == d) {
        cout << -1;
        return 0;
    }
    if(a > 9 || b > 9 || c > 9 || d > 9) {
        cout << -1;
        return 0;
    }
    if(a < 1 || b < 1 || c < 1 || d < 1) {
        cout << -1;
        return 0;
    }
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    return 0;
}
