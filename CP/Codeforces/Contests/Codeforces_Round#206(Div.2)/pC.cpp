#include <bits/stdc++.h>
using namespace std;

int n, l, r, ql, qr;
int w[100010];

int main()
{
    cin >> n >> l >> r >> ql >> qr;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    int f[100010];
    f[0] = 0;
    for(int i = 1; i <= n; ++i) f[i] = f[i-1]+w[i];
    int ans = INT_MAX;
    for(int i = 0; i <= n; ++i) {
        int v = f[i]*l + (f[n]-f[i])*r;
        if(i < n/2) v += qr * max(0, (n-2*i-1));
        else v += ql * max(0, (2*i-n-1));
        ans = min(ans, v);
    }
    cout << ans;
    return 0;
}
