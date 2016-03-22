/*************************************************************************
	> File Name: p1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年03月19日 (週六) 13時23分23秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class matrix {
public:
    matrix();
    // member function for getting every elements of matrix
    void scan()
    {
        char str[100];
        while(cin.peek() != '\n')
        {
            vector<int> v;
            while(cin.peek() < '9' && cin.peek() > '0')
            {
                int tmp;
                cin >> tmp;
                v.push_back(tmp);
            }
            matrix::_e.push_back(v);
            cin.getline(str,100);
        }
        cin.getline(str,100);
    }
    // member function for display the matrix
    void print()
    {
        if(matrix::_e.size() == 0)
        {
            cout << "null matrix" << endl;
            return;
        }
        for(unsigned int i = 0; i < matrix::_e.size(); ++i)
        {
            for(unsigned int j = 0; j < matrix::_e.at(i).size(); ++j)
                cout << matrix::_e.at(i).at(j) << ' ';
            cout << endl;
        }
        return;
    }
    // member function for getting matrix[x][y]
    int at(const int &x, const int &y)
    {
        return matrix::_e.at(x).at(y);
    }
    // overloading * for matrix
    matrix operator*(const matrix&)
    {}
private:
    vector<vector<int> > _e;
};

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
