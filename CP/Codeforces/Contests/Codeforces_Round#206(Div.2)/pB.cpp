#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1010], b[1010];
    int c1, c2, c3, c4;
    int n, m;
    int la = 0, lb = 0;
    cin >> c1 >> c2 >> c3 >> c4;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i]*c1 < c2) la += a[i] * c1;
        else la += c2;
    }
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
        if(b[i]*c1 < c2) lb += b[i] * c1;
        else lb += c2;
    }
    if(la > c3) la = c3;
    if(lb > c3) lb = c3;
    if(la+lb < c4) cout << la+lb;
    else cout << c4;
    return 0;
}
