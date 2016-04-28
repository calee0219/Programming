/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年04月09日 (週六) 21時09分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

map<string,int> dp;
int find(string);
string extra(string);

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i)
    {
        string str;
        cin >> str;
        cout << "Case #" << i << ": " << find(str) << endl;
    }
    return 0;
}

int find(string str)
{
    cout << str << dp.size() << endl;
    if(dp.count(str)) return dp[str];
    else if(str == "+") { cout << "0hi" << endl; return 0; }
    else if(str == "-") { cout << "1hi" << endl; return 1; }
    else if(str.back() == '+') // +/-,+
    {
        cout << "hi" << endl;
        string tmp = str;
        tmp.erase(tmp.end()-1);
        cout << tmp << "+/-,+" << endl;
        if(dp.count(tmp))
            dp[tmp] = find(tmp);
        return dp[str] = dp[tmp];
    }
    else
    {
        if(str.front() == '-') // -,-
        {
            string tmp = str;
            reverse(tmp.begin(),tmp.end());
            int l = tmp.length();
            for(int i = 0; i < l; ++i)
            {
                if(tmp[i] == '+')
                    tmp[i] = '-';
                else
                    tmp[i] = '+';
            }
            tmp.erase(tmp.end()-1);
            cout << tmp << "-,-" << endl;
            if(!dp.count(tmp))
                dp[tmp] = find(tmp);
            return dp[str] = dp[tmp] + 1;
        }
        else // +,-
        {
            string tmp = str;
            tmp = extra(tmp);
            if(!dp.count(tmp))
                dp[tmp] = find(tmp);
            cout << tmp << endl;
            return dp[str] = dp[tmp] + 1;
        }
    }
}

string extra(string str)
{
    int l = str.length()-2;
    while(str[l] == '-') l--;
    reverse(str.begin(),str.begin()+l+1);
    for(int i = 0; i <= l; ++i)
    {
        if(str[i] == '+')
            str[i] = '-';
        else
            str[i] = '+';
    }
    cout << str << "extra" << endl;
    return str;
}
