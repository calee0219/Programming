#include <iostream>
#include <cmath>
using namespace std;

long long int check(long long int num)
{
    long long int i = 1;
    long long int sum = 0;
    while(i <= num)
    {
        sum += i;
        i *= 2;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        long long sum = n * (n+1) / 2;
        sum -= 2 * check(n);
        cout << sum << endl;
    }
    return 0;
}

