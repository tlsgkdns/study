#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<pair<int, int>, int>> Q;
int N, A[100001], M, I, J, ans[100001];
int C[1000001], l = 0, r = 0, cnt = 0, sq = 0;

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	int a = p1.first.first / sq, b = p2.first.first / sq;
	if (a == b) return p1.first.second < p2.first.second;
	return a < b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; sq = sqrt(N);
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> I >> J;
		Q.push_back({ { I, J }, i });
	}
	sort(Q.begin(), Q.end(), cmp);
	l = Q[0].first.first; r = Q[0].first.second;
	for (int i = l; i <= r; i++)
	{
		if (C[A[i]]++ == 0)
			++cnt;
	}
	ans[Q[0].second] = cnt;
	for (int i = 1; i < M; i++)
	{
		int L = Q[i].first.first;
		int R = Q[i].first.second;
		int idx = Q[i].second;
		while (l < L) if (--C[A[l++]] == 0) --cnt;
		while (l > L) if (C[A[--l]]++ == 0) ++cnt;
		while (r < R) if (C[A[++r]]++ == 0) ++cnt;
		while (r > R) if (--C[A[r--]] == 0) --cnt;
		ans[idx] = cnt;
	}
	for (int i = 0; i < M; i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/13547