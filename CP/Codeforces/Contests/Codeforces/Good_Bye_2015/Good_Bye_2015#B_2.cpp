/*************************************************************************
	> File Name: Good_Bye_2015#B_2.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月06日 (週三) 03時17分55秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int s, b;
    cin >> s >> b;
    // s0 and b0 stand for the first zero base on binary in s and b
    int s0 = 0, b0 = 0;
    int ans = 0;
    // ns and nm is the number of s and m's in binary, my English is really poor :)
    int ns = 0, nb = 0;
    int sums = 0, sumb = 0;
    while(s)
    {
        // here to find how long s is, and save it in ns
        ns++;
        // using binary operator to check if the first zero of s
        if(s & 1);
        else
        {
            s0 = ns;
            sums++;
        }
        s >>= 1;
    }
    while(b)
    {
        nb++;
        if(b & 1);
        else
        {
            b0 = nb;
            sumb++;
        }
        b >>= 1;
    }
    // ans add from ns-1 to nb-1
    // but if ns == 0, then add from 1 to nmo-1
    if(ns != 0)
        ans += (ns + nb - 2)*(nb - ns + 1)/2;
    else
        ans += nb*(nb - 1)/2;
    // and then we must minus the one zero persion that is small than s and is bigger than m
    // first I'll check if I write correct above!!
    cout << ans << endl;
    // I thank if s and b have the same lenth, the ans is just the lenth between two zero
    if(sums == 1 && sumb == 1)
    {
        ans -= (ns - s0 - 1);
        ans -= (b0 - 1);
    }
    else if(sums != 1 && sumb != 1)
    {
        ans -= (ns - s0);
        ans -= b0;
    }
    cout << ans;
    return 0;
}

