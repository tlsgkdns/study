#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> group;
vector<bool> cnt;
vector<vector<int>> logo(1001, vector<int>(1001, -1));
int N, a1, b1, a2, b2;
int find(int a)
{
	if (group[a] == a) return a;

	return group[a] = find(group[a]);
}
void merge(int a, int b)
{
	if (a < b) swap(a, b);
	int p = find(a);
	int q = find(b);
	group[p] = q;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	group.resize(N + 1); cnt.resize(N + 1, false);
	logo[500][500] = 0;
	for (int i = 0; i <= N; i++) group[i] = i;
	for (int n = 1; n <= N; n++)
	{
		cin >> a1 >> b1 >> a2 >> b2;
		for (int y = b1; y <= b2; y++)
		{
			if (logo[y + 500][a1 + 500] == -1)
				logo[y + 500][a1 + 500] = n;
			else if (find(logo[y + 500][a1 + 500]) != find(n))
				merge(n, logo[y + 500][a1 + 500]);
		}
		for (int y = b1; y <= b2; y++)
		{
			if (logo[y + 500][a2 + 500] == -1)
				logo[y + 500][a2 + 500] = n;
			else if (find(logo[y + 500][a2 + 500]) != find(n))
				merge(n, logo[y + 500][a2 + 500]);
		}
		for (int x = a1; x <= a2; x++)
		{
			if (logo[b1 + 500][x + 500] == -1)
				logo[b1 + 500][x + 500] = n;
			else if (find(logo[b1 + 500][x + 500]) != find(n))
				merge(n, logo[b1 + 500][x + 500]);
		}
		for (int x = a1; x <= a2; x++)
		{
			if (logo[b2 + 500][x + 500] == -1)
				logo[b2 + 500][x + 500] = n;
			else if (find(logo[b2 + 500][x + 500]) != find(n))
				merge(n, logo[b2 + 500][x + 500]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= N; i++)
	{
		if (cnt[find(group[i])]) continue;
		cnt[find(group[i])] = true;
		ans++;
	}
	ans--;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/3108