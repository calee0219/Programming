#include <bits/stdc++.h>
using namespace std;

int a[2000020];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    int begin = 1, end = n+1;
    for(int i = 2; i <= n; ++i) {
//for(int i = 0; i < 2*end; ++i) cout << a[i] << ' ';
//cout << endl;
        for(int j = n/i; j >= 0; --j) {
            //cout << a[end] << ' ' << j*n+1 << endl;
            if(j == n/i) a[end] = a[j*i+begin];
            else a[(j+1)*i+begin] = a[j*i+begin];
        }
        begin++;
        end++;
    }
    for(int i = begin; i < end; ++i) cout << a[i] << ' ';
    cout << endl;
    return 0;
}
