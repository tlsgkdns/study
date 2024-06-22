#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000007;
vector<int> A[11];
int N, M, O, P, ans = INF;

void solve(int idx, int b, int cnt)
{
	if (b == (1 << N) - 1)
	{
		ans = min(ans, cnt);
		return;
	}
	if (idx == M) return;
	solve(idx + 1, b, cnt);
	int tmp = b;
	for (int i = 0; i < A[idx].size(); i++)
		tmp |= (1 << A[idx][i]);
	solve(idx + 1, tmp, cnt + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> O;
		while (O--)
		{
			cin >> P;
			A[i].push_back(P - 1);
		}
	}
	solve(0, 0, 0);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11578