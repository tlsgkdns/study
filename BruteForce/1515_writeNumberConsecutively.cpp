#include <iostream>
#include <string>
using namespace std;

int idx = 0, tmpNum = 1, num = 1, deci = 1, tmpDeci = 1;
string str;
char now = '1';
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	while (true)
	{
		now = (tmpNum / tmpDeci) + '0';
		if (now == str[idx]) idx++;
		tmpNum %= tmpDeci;
		tmpDeci /= 10;
		if (idx == (int)str.size())
			break;
		if (tmpDeci == 0)
		{
			num++;
			if (num == deci * 10) deci *= 10;
			tmpDeci = deci;
			tmpNum = num;
		}
	}
	cout << num << '\n';
}

// https://www.acmicpc.net/problem/1515