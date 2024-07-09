#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<pair<int, int>, int>> Q;
int N, A[100003], M, I, J, ans[100003];
int C[100003], l = 0, r = 0, cnt = 0, sq = 0, T[100003];

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	int a = p1.first.first / sq, b = p2.first.first / sq;
	if (a == b) return p1.first.second < p2.first.second;
	return a < b;
}
void p(int x) {
	if (C[x] != 0) T[C[x]]--;
	C[x]++; T[C[x]]++;
	cnt = max(cnt, C[x]);
}

void m(int x) {
	T[C[x]]--;
	if (C[x] == cnt && T[C[x]] == 0) cnt--;
	C[x]--;
	T[C[x]]++;
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
	for (int i = 0; i < Q.size(); i++)
	{
		int L = Q[i].first.first;
		int R = Q[i].first.second;
		int idx = Q[i].second;
		while (l < L) m(A[l++]);
		while (l > L) p(A[--l]);
		while (r < R) p(A[++r]);
		while (r > R) m(A[r--]);
		ans[idx] = cnt;
	}
	for (int i = 0; i < Q.size(); i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/13548