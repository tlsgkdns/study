#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
const int MAX = 50001;
vector<pii> C[MAX * 4];
int N, T, X, Y, ans = -1;
bool v[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T;
	for (int i = 1; i <= N; i++)
	{
		cin >> X >> Y;
		C[Y].push_back({ X, i });
	}
	for (int i = 0; i < MAX; i++) sort(C[i].begin(), C[i].end());
	queue<pair<int, pii>> q;
	q.push({ 0, {0, 0} });
	while (!q.empty())
	{
		int d = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		if (y == T)
		{
			ans = d;
			break;
		}
		for (int h = -2; h <= 2; h++)
		{
			int ny = y + h;
			if (ny > T || ny < 0) continue;
			for (int w = -2; w <= 2; w++)
			{
				pii nx = { x + w, 0 };
				auto tmp = lower_bound(C[ny].begin(), C[ny].end(), nx);
				if (tmp == C[ny].end()) continue;
				pii p = *tmp;
				if (nx.first == p.first && !v[p.second])
				{
					v[p.second] = true;
					q.push({ d + 1, {ny, x + w} });
				}
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2412