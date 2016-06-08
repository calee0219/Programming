/*
 * =====================================================================================
 *
 *       Filename:  hw7.cpp
 *
 *    Description:  design linux-shell-like systems
 *
 *        Version:  1.0
 *        Created:  06/05/2016 11:48:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gavin Lee (calee0219), sz110010@gmail.com
 *   Organization:  NCTU
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>
using namespace std;

namespace fos {
	string cat(string);
	string removetag(string);
}

string buf[666];

int main(int argc, char *argv[])
{
	for(int i = 1; i <= argc; ++i) {
		ifstream ff(argv[i]);
		string str;
		int cha = 0;
		while(getline(ff,str)) {
			cout << "% " << str << endl;
			int ord = 0, pre = 0;
			// Get command
			while(ord < str.length() && (str[ord] == ' ')) ord = ++pre;
			while(ord < str.length() && str[ord] != ' ' && str[ord] != '|' && str[ord] != '>') ++ord;
			string command(str.substr(pre,ord));
			pre = ord;

			if(command == "cat") {
				string tmp_buf;
				string from;
				if(buf[cha] == "") {
					// get the file name
					while(ord < str.length() && (str[ord] == ' ')) ord = ++pre;
					while(ord < str.length() && str[ord] != ' ' && str[ord] != '|' && str[ord] != '>') ++ord;
					from = str.substr(pre,ord);
					pre = ord;
					tmp_buf = fos::cat(from);
				}
				else
					tmp_buf = buf[cha];

				// if there is | or >
				while(ord < str.length() && str[ord] == ' ') ord = ++pre;
				char opera = str[ord];
				ord = ++pre;
				if(opera == '|') {
					string num(str.substr(pre,str.length()));
					buf[cha+stoi(num)] += tmp_buf;
				}
				else if(opera == '>') {
					while(ord < str.length() && str[ord] == ' ') ord = ++pre;
					while(ord < str.length() && str[ord] != ' ') ++ord;
					string fileName(str.substr(pre,ord));
					ofstream of(fileName);
					of << tmp_buf;
					of.close();
				}
				else {
					cout << tmp_buf;
				}
			}
			else if(command == "removetag") {

			}
			else if(command == "exit") {
				break;
			}
			else {
				string tmp_buf = "unknow command\n";
				continue;
			}
			++cha;
		}
		ff.close();
	}
	return 0;
}

string fos::cat(string file)
{
	ifstream rf(file);
	string tmp;
	string buf;
	while(getline(rf,tmp))
	{
		buf += tmp;
		buf += "\n";
	}
	return buf;
}

string fos::removetag(string)
{

}
