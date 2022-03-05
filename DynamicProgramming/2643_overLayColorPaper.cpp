#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

int N, A, B;
int dp[101][101];
int getMin(pii p)
{
	return min(p.first, p.second);
}
bool overLay(pii p1, pii p2)
{
	return ((p2.first <= p1.first && p2.second <= p1.second) || ((p2.second <= p1.first) && (p2.first <= p1.second)));
}
bool cmp(pii p1, pii p2)
{
	return getMin(p1) > getMin(p2);
}
vector<pii> paper;
int solve(int idx, int prev)
{
	if (idx == N + 1) return 0;
	int& ret = dp[idx][prev];
	if (ret != -1) return ret;
	if (overLay(paper[prev], paper[idx]))
		return ret = max(solve(idx + 1, idx) + 1, solve(idx + 1, prev));
	return ret = solve(idx + 1, prev);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	paper.push_back({ 1001, 1001 });
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		paper.push_back({ A, B });
	}
	sort(paper.begin(), paper.end(), cmp);
	cout << solve(1, 0) << '\n';
}

// https://www.acmicpc.net/problem/2643