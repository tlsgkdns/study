#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> ans[11];
int K, cnt = 0, B[1025];

void solve(int l, int r, int d)
{
	++cnt;
	if (l == r)
	{
		ans[d].push_back(B[l]);
		return;
	}
	int m = (l + r) / 2;
	solve(l, m - 1, d + 1);
	ans[d].push_back(B[m]);
	solve(m + 1, r, d + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K; int N = pow(2, K) - 1;
	for (int i = 0; i < N; i++) cin >> B[i];
	solve(0, N - 1, 0);
	for (int i = 0; !ans[i].empty(); i++)
	{
		for (int idx = 0; idx < ans[i].size(); idx++)
			cout << ans[i][idx] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/9934