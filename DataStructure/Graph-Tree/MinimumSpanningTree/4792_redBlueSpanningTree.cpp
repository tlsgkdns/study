#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;
int N, M, K, F, T, P[1001];
char C;
int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a < b) swap(a, b);
	P[a] = b;
}
int mst(vector<pair<int, pair<int, int>>>& edges)
{
	for (int i = 0; i < N; i++) P[i] = i;
	int ret = 0;
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
		if (find(edges[i].second.first) != find(edges[i].second.second))
		{
			merge(edges[i].second.first, edges[i].second.second);
			ret += edges[i].first;
		}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N >> M >> K;
		if (N == 0 && M == 0 && K == 0) break;
		vector<pair<int, pair<int, int>>> edges1, edges2;
		int cnt = 0, bcnt = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> C >> F >> T;
			cnt += (C == 'B');
			edges1.push_back({ (C == 'B'), {F, T} });
			edges2.push_back({ -(C == 'B'), {F, T} });
		}
		int l = mst(edges1), r = -mst(edges2);
		ans.push_back(l <= K && K <= r);
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/4792