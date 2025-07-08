#include <iostream>
#include <algorithm>

using namespace std;

int N, T[100001], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	for (int i = N - 1; i >= 0; i--)
		ans = max(ans, (N - i + 1) + T[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/9237