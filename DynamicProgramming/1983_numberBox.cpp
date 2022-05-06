#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[401][401][401];
vector<int> box1, box2;
const int NINF = -2000000000;
int N, num, L1, L2;
int solve(int cur, int idx1, int idx2)
{
	if (idx1 == L1 && idx2 == L2) return 0;
	if (cur == N) return NINF;
	int& ret = dp[cur][idx1][idx2];
	if (ret != NINF) return ret;
	if (idx1 < L1) ret = max(ret, solve(cur + 1, idx1 + 1, idx2));
	if (idx2 < L2) ret = max(ret, solve(cur + 1, idx1, idx2 + 1));
	if (idx1 < L1 && idx2 < L2) ret = max(ret, solve(cur + 1, idx1 + 1, idx2 + 1) + box1[idx1] * box2[idx2]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			for (int k = 0; k <= N; k++)
				dp[i][j][k] = NINF;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 0) continue;
		box1.push_back(num);
	}
	L1 = (int)box1.size();
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 0) continue;
		box2.push_back(num);
	}
	L2 = (int)box2.size();
	cout << solve(0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1983