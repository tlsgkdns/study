#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
using pii = pair<pair<int, int>, int>;

const ll INF = 1000000000007;
vector<int> init;
int L, S[52], N, ans[102];

struct cmp {
	bool operator()(const pii& p1, const pii& p2)
	{
		if (p1.first.first < 0) return true;
		if (p2.first.first < 0) return false;
		ll lcnt1 = p1.first.second, rcnt1 = p1.first.first - p1.first.second;
		ll lcnt2 = p2.first.second, rcnt2 = p2.first.first - p2.first.second;
		ll f1 = (lcnt1) * (rcnt1);
		ll f2 = (lcnt2) * (rcnt2);
		if (f1 != f2) return f1 > f2;
		return p1.second > p2.second;
	}
};
priority_queue<pii, vector<pii>, cmp> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> S[i];
	cin >> N;
	sort(S, S + L);
	if (S[0] == 2) init.push_back(1);
	for (int i = 0; i < L; i++) init.push_back(S[i]);
	for (int i = 1; i < L; i++)
		if (S[i - 1] + 2 == S[i])
			init.push_back(S[i - 1] + 1);
	sort(init.begin(), init.end());
	for (int i = 0; i < init.size(); i++) ans[i] = init[i];
	if (N > init.size())
	{
		if (S[0] > 2)
		{
			pq.push({ {S[0], 1}, (S[0] == 1) ? 2 : 1 });
			pq.push({ {S[0], S[0] - 1}, S[0] - 1 });
		}
		for (int i = 0; i < L - 1; i++)
		{
			if (S[i] + 2 < S[i + 1])
			{
				pq.push({ {S[i + 1] - S[i], 1}, S[i] + 1 });
				pq.push({ { S[i + 1] - S[i], S[i + 1] - S[i] - 1}, S[i + 1] - 1 });
			}
		}
		pq.push({ {-1, 0}, S[L - 1] + 1 });
		for (int i = init.size(); i < N; i++)
		{
			int l = pq.top().first.first;
			int idx = pq.top().first.second;
			int m = (l / 2);
			ans[i] = pq.top().second;
			pq.pop();
			if (l < 0)
				pq.push({ {-1, 0}, ans[i] + 1 });
			else if (m < idx && m < idx - 1)
				pq.push({ {l, idx - 1}, ans[i] - 1 });
			else if (idx < m && idx + 1 <= m)
				pq.push({ {l, idx + 1}, ans[i] + 1 });
		}
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1060