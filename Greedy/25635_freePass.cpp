#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
int N;
ll ans = 0, A[100001], s = 0;
priority_queue<ll> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		s += A[i];
	}
	sort(A, A + N);
	s -= A[N - 1];
	if (N == 1) cout << 1 << '\n';
	else if (A[N - 1] <= s + 1) cout << s + A[N - 1] << '\n';
	else cout << s * 2 + 1 << '\n';
}

// https://www.acmicpc.net/problem/25635