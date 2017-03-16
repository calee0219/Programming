/*************************************************************************
	> File Name: PF.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年0 1;;;44秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int lg = max(n,m);
	int len[100010];
	int one = 0;
	char g[1000010];
	int maxlen = 0;
	for(int i = 0; i<n; ++i){
		int tmp = 0;
		for(int j = 0; j<m; ++j){
            char input;
			cin >> input;
			g[i*m+j] = input;

			if(input=='.')
				++tmp;
            else{
                ++len[tmp];
                if(tmp>maxlen)
                    maxlen = tmp;
                one += tmp;
                tmp = 0;
			}
		}
        if(tmp!=0){
            ++len[tmp];
            if(tmp>maxlen)
                maxlen = tmp;
            one += tmp;
            tmp = 0;
        }
	}

	for(int i = 0; i<m; ++i){
		int tmp = 0;
		for(int j = 0; j<n; ++j){
			if(g[i*n+j]=='.')
				++tmp;
			else{
				++len[tmp];
                if(tmp>maxlen)
                    maxlen = tmp;
				tmp = 0;
			}
		}
        if(tmp!=0){
            ++len[tmp];
            if(tmp>maxlen)
                maxlen = tmp;
            tmp = 0;
        }
	}

	for(int i = 1; i<=lg; ++i)
		cout << len[i] << " ";
	cout << endl;

	for(int i = 1; i<=lg; ++i){
		if(i==1 && i==maxlen)
			cout << one;
		else if(i==1)
		cout << one << ' ';
		else{
			int sum = 0;
			for(int j = i; j<=maxlen; ++j){
				sum += (j-i+1)*len[j];
			}
			if(i==lg)
				cout << sum;
			else
				cout << sum << ' ';
			sum = 0;
		}
	}
	return 0;
}

