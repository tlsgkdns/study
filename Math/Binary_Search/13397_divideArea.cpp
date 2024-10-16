#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1000000007;
int N, M, A[5001];

bool solve(int L)
{
	int mx = A[0], mn = A[0], cnt = 1;
	for (int i = 1; i < N; i++)
	{
		mx = max(A[i], mx);
		mn = min(A[i], mn);
		if (mx - mn > L)
		{
			++cnt;
			mx = A[i];
			mn = A[i];
		}
	}
	return cnt <= M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	int l = -1, r = 10001;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) r = m;
		else l = m;
	}
	cout << r << '\n';
}

// https://www.acmicpc.net/problem/13397