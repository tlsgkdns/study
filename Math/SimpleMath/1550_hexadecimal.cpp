#include <iostream>
#include <cctype>
using namespace std;

char ch;
long long ans = 0, d = 1;
string str;
int main()
{
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		int n = (isalpha(str[i])) ? str[i] - 'A' + 10 : str[i] - '0';
		ans += n * d;
		d *= 16;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1550