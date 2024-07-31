#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> e1, e2;
int N, M, A, B, C, P[1001], ans1 = 0, ans2 = 0;

int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b) swap(a, b);
	P[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) P[i] = i;
	for (int i = 0; i < M + 1; i++)
	{
		cin >> A >> B >> C;
		e1.push_back({ !C, {A, B} });
		e2.push_back({ C, {A, B} });
	}
	sort(e1.begin(), e1.end());
	sort(e2.begin(), e2.end());
	for (int i = 0; i < e1.size(); i++)
	{
		int c = e1[i].first;
		int a = e1[i].second.first;
		int b = e1[i].second.second;
		if (find(a) == find(b)) continue;
		merge(a, b);
		ans1 += c;
	}
	for (int i = 0; i <= N; i++) P[i] = i;
	for (int i = 0; i < e2.size(); i++)
	{
		int c = e2[i].first;
		int a = e2[i].second.first;
		int b = e2[i].second.second;
		if (find(a) == find(b)) continue;
		merge(a, b);
		ans2 += c;
	}
	cout << ((N - ans2) * (N - ans2)) - (ans1 * ans1) << '\n';
}

// https://www.acmicpc.net/problem/13418