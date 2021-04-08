#include <iostream>

using namespace std;

int main()
{
	int n, ans = 0;
	string s;
	cin >> n;
	cin >> s;
	for (char c : s) ans += (c - '0');
	cout << ans << '\n';
}
//https://www.acmicpc.net/problem/11720
/*
easy string problem
*/