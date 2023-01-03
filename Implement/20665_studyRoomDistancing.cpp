#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
int N, T, P, ans = 0;
string S, E;
vector<pii> times;
int room[101][1261], d[101][1261];
int timeToInt(string t)
{
	string H(t.begin(), t.begin() + 2);
	string M(t.begin() + 2, t.end());
	return stoi(H) * 60 + stoi(M);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(room, -1, sizeof(room));
	cin >> N >> T >> P;
	for (int i = 0; i < T; i++)
	{
		cin >> S >> E;
		times.push_back({ timeToInt(S), timeToInt(E) });
	}
	sort(times.begin(), times.end());
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= 1260; j++)
			d[i][j] = N;
	for (int i = 0; i < T; i++)
	{
		int c = 0, insIdx = 0;
		for (int idx = 0; idx < N; idx++)
			if (d[idx][times[i].first] > d[insIdx][times[i].first])
				insIdx = idx;
		for (int t = times[i].first; t < times[i].second; t++)
		{
			room[insIdx][t] = i;
			for (int idx = insIdx; idx < N; idx++) d[idx][t] = min(d[idx][t], idx - insIdx);
			for (int idx = insIdx - 1; idx >= 0; idx--) d[idx][t] = min(d[idx][t], insIdx - idx);
		}
	}
	for (int t = 540; t < 1260; t++)
		ans += (room[P - 1][t] < 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20665