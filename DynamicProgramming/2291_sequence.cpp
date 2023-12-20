#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> ans;
int dp[11][221][221], N, M, K;

int solve(int idx, int goal, int num)
{
	int& ret = dp[idx][goal][num];
	if (ret >= 0) return ret;
	if (idx == N) return ret = (goal == 0);
	if (goal == 0) return ret = 0;
	ret = 0;
	for (int n = num; n <= goal; n++)
		ret += solve(idx + 1, goal - n, n);
	return ret;
}
void reconstruct(int idx, int goal, int num, int kth)
{
	if (idx == N) return;
	int s = 0;
	for (int n = num; n <= goal; n++)
	{
		if (s + dp[idx + 1][goal - n][n] >= kth)
		{
			ans.push_back(n);
			reconstruct(idx + 1, goal - n, n, kth - s);
			break;
		}
		else
			s += dp[idx + 1][goal - n][n];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	solve(0, M, 1);
	reconstruct(0, M, 1, K);
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2291