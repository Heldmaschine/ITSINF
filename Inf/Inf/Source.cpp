#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int find(string);
int main()
{
	int n;
	ifstream inf("input.txt");
	ofstream outf("output.txt");
	inf >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		inf >> str;
		outf << find(str);
		outf << endl << endl;
	}
	inf.close();
	outf.close();
	return 0;
}

int find(string main)
{
	string prd, cmp;
	int first = 1, last = 0, num, chk;
start:
	if (first >= main.length() - prd.length()) return main.length(); 
	cmp = main;
	last = main.find(main[0], first);
	prd = main.substr(0, last);
	num = 0;
	chk = 0;
	while (cmp[0])
	{
		if (prd != cmp.substr(0, last)){
			--chk; break;
		}
		else  ++chk;
		cmp.erase(0, last);
		++num;
	}
	if (chk != num)
	{
		first = last + 1;
		goto start;
	}
	//cout << prd.length();
	return prd.length();
}