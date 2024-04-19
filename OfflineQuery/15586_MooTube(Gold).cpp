#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using piii = pair<int, pair<int, int>>;

vector<piii> arr, query;
int N, Q, p, q, r, cnt[100001], P[100001], ans[100001], k, v, idx = 0;

int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	P[b] = a;
	cnt[a] += cnt[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		P[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0; i < N - 1; i++)
	{
		cin >> p >> q >> r;
		arr.push_back({ -r, {p, q} });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < Q; i++)
	{
		cin >> k >> v;
		query.push_back({ -k, {v, i} });
	}
	sort(query.begin(), query.end());
	for (int i = 0; i < Q; i++)
	{
		int lim = -query[i].first;
		int st = query[i].second.first;
		int id = query[i].second.second;
		while (idx < N - 1 && lim <= -arr[idx].first)
		{
			merge(arr[idx].second.first, arr[idx].second.second);
			++idx;
		}
		ans[id] = cnt[find(st)];
	}
	for (int i = 0; i < Q; i++) cout << ans[i] - 1 << '\n';
}

// https://www.acmicpc.net/problem/15586