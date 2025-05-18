#include <iostream>

using namespace std;

int N, a1 = 0, a2 = 1, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N > 0)
	{
		int tmp = a2;
		N -= a2;
		a2 += a1;
		a1 = tmp;
		++ans;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20811