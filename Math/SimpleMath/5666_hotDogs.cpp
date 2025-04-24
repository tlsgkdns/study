#include <iostream>

using namespace std;
double H, P;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout.precision(2); cout << fixed;
	while (true)
	{
		cin >> H >> P;
		if (cin.eof()) break;
		cout << H / P << '\n';
	}
}

// https://www.acmicpc.net/problem/5666