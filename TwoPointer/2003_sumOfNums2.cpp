#include <iostream>

using namespace std;
using ll = long long;

int arr[10001];
int N, M, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int l = 0, s = 0;
	for (int r = 0; r <= N; r++)
	{
		while (l < r && s > M)
		{
			s -= arr[l];
			l++;
		}
		if (s == M) ans++;
		if (r < N) s += arr[r];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2003