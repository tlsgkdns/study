#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = -1;
int T[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	for (int i = N - 1; i >= 2; i--)
		if (T[i] < T[i - 1] + T[i - 2])
		{
			ans = T[i] + T[i - 1] + T[i - 2];
			break;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1448