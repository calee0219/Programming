/*************************************************************************
	> File Name: PF_1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月26日 (週二) 14時32分38秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	char g[n][m];
	int len[m+1];
	int maxlen = m+1;
	int one = 0;
	int tmp = 0;
	int lg = max(n,m);

	int counter = 0;
	for(int i = 0; i<n; ++i){
		for(int j = 0; j<m; ++j){
			char input;
			cin >> input;
			g[i][j] = input;

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
}
