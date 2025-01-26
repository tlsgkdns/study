#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
int N, M, A, B, C, P[10001];
ll ans = 0, T;
vector<pair<int, pair<int, int>>> ed;
int find(int a)
{
	if (P[a] == a) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a < b) swap(a, b);
	P[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) P[i] = i;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		ed.push_back({ C, {A, B} });
	}
	sort(ed.begin(), ed.end());
	for (int i = 0; i < ed.size(); i++)
	{
		int c = ed[i].first;
		int a = ed[i].second.first;
		int b = ed[i].second.second;
		if (find(a) != find(b))
		{
			ans += c;
			merge(a, b);
		}
	}
	cout << ans + T * ((N - 2) * (N - 1) / 2) << '\n';
}

// https://www.acmicpc.net/problem/14950