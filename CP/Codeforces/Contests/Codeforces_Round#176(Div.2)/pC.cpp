#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main()
{
    int n;
    cin >> n;
    if(n%4 == 2 || n%4 == 3) {
        cout << -1;
        return 0;
    }
    if(n & 1) {
        for(int i = 0; i < n/2; ++i) {
            a[2*i] = 2*i + 2;
            a[2*i+1] = n+2-a[2*i];
        }
        int h = n/2+1;
        a[h-1] = h;
        for(int i = 0; i < n/2; ++i) {
            a[2*i+h] = h-2-2*i;
            a[2*i+h+1] = n-a[2*i+h];
        }
    } else {
        for(int i = 0; i < n/2; ++i) {
            a[2*i] = 2*i + 2;
            a[2*i+1] = n+2-a[2*i];
        }
        int h = n/2+1;
        for(int i = 0; i < n/2; ++i) {
            a[2*i+h-1] = h-2-2*i;
            a[2*i+h] = n-a[2*i+h-1];
        }
    }
    for(int i = 0; i < n; ++i) cout << a[i] << ' ';
    return 0;
}
