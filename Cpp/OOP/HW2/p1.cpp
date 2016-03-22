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
    void scan();                            // member function for getting every elements of matrix
    void print();                           // member function for display the matrix
    int at(const int &x, const int &y);     // member function for getting matrix[x][y]
    // overloading * for matrix
    matrix operator*(const matrix &m)
    {
        matrix ans;
        if(!m._e.size() || !matrix::_e.size() || m._e.at(0).size() != matrix::_e.size())
            return ans;
    }
private:
    vector<vector<int> > _e;
};

int main()
{
    matrix m1, m2;
    m1.scan();
    m2.scan();
    matrix ans;
    ans = m1 * m2;
    ans.print();
    return 0;
}

void matrix::print()
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

void matrix::scan()
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

int matrix::at(const int &x, const int &y)
{
    return matrix::_e.at(x).at(y);
}
