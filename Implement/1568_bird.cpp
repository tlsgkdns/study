#include <iostream>

using namespace std;

int N, ans = 0, now = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N > 0)
	{
		if (N < now) now = 1;
		N -= now++;
		++ans;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1568