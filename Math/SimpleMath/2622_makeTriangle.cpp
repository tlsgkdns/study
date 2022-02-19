#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N - i; j++)
		{
			int k = N - (i + j);
			if (k < j || (i + j) <= k) continue;
			ans++;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2622