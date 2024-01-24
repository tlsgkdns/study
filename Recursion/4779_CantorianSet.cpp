#include <iostream>
#include <cmath>
using namespace std;

int N;

void solve(int l, bool b)
{
	if (b)
	{
		for (int i = 0; i < l; i++) cout << " ";
		return;
	}
	if (l == 1) cout << "-";
	else
	{
		solve(l / 3, false);
		solve(l / 3, true);
		solve(l / 3, false);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (cin.eof()) break;
		solve(pow(3, N), false);
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/4779