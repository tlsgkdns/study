#include <iostream>

using namespace std;

int pre = -1000001, N, A, ans = true;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> N)
	{
		if (!ans) continue;
		if (pre <= N)
			pre = N;
		else
			ans = false;
	}
	if (ans) cout << "Good\n";
	else cout << "Bad\n";
}

// https://www.acmicpc.net/problem/14910