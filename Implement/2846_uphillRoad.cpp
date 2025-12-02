#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int P[1001], N, c = 0, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> P[i];
	for (int i = 1; i < N; i++)
	{
		if (P[i - 1] < P[i])
		{
			ans = max(ans, P[i] - P[c]);
		}
		else
			c = i;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2846