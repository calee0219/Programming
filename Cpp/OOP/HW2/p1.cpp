/*************************************************************************
	> File Name: p1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年03月19日 (週六) 13時23分23秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int> > m1, m2;
    char str[2];
    while(cin.peek() != '\n')
    {
        vector<int> v;
        while(cin.peek() < '9' && cin.peek() > '0')
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        m1.push_back(v);
        cin.getline(str,2);
    }
    cin.getline(str,2);
    while(cin.peek() != '\n')
    {
        vector<int> v;
        while(cin.peek() != '\n')
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        m2.push_back(v);
        char str[2];
        cin.getline(str,2);
    }
    for(unsigned int i = 0; i < m1.size(); ++i)
    {
        for(unsigned int j = 0; j < m1.at(i).size(); ++j)
            cout << m1.at(i).at(j) << ' ';
        cout << endl;
    }
    return 0;
}
