#include <bits/stdc++.h>
using namespace std;

long long int n, k;

long long int sum(long long int a)
{
    return (a+k)*(k-a+1)/2;
}

long long int BS(long long int a, long long int b)
{
    //cout << a << ',' << b << ',' << (a+b)/2 << ',' << sum((a+b)/2)<< endl;
    long long int s = sum((a+b)/2);
    if(a == b) return a;
    if(s > n) {
        return BS((a+b)/2+1,b);
    } else {
        return BS(a,(a+b)/2);
    }
}

int main()
{
    cin >> n >> k;
    k--;
    n--;
    if(k*(k+1)/2 < n) {
        cout << -1;
        return 0;
    }
    if(n == 1) {
        cout << 0;
        return 0;
    }
    long long int tmp = BS(1,k+1);
    //cout << tmp << endl;
    if(sum(tmp) == n) cout << k-tmp+1;
    else cout << k-tmp+2;
    return 0;
}
