#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
vector<pair<int, int>> P;
int N, H, O, D, cnt = 0, ans = 0, l, r = 0;
priority_queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> H >> O;
		if (H > O) swap(H, O);
		P.push_back({ O, H });
	}
	sort(P.begin(), P.end());
	cin >> D;
	for (int i = 0; i < N; i++)
	{
		if (P[i].first - P[i].second > D) continue;
		while (!q.empty() && P[i].first + q.top() > D)
		{
			--cnt;
			q.pop();
		}
		q.push(-P[i].second);
		++cnt;
		ans = max(ans, cnt);
	}
	ans = max(ans, cnt);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13334