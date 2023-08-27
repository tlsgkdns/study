#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
vector<pii> pos;
int cnt[100001], T, N, X, Y, M, A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(cnt, 0, sizeof(cnt));
		pos = vector<pii>();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> X >> Y;
			pos.push_back({ X, Y });
			++cnt[X];
		}
		sort(pos.begin(), pos.end());
		pii cur = { 0, 0 };
		bool up = true;
		for (int idx = 0; idx < N; cur = pos[idx + cnt[pos[idx].first] - 1], idx += cnt[pos[idx].first])
			if (cur.second > pos[idx].second)
			{
				sort(pos.begin() + idx, pos.begin() + idx + cnt[pos[idx].first], greater<pii>());
				cur = pos[idx + cnt[pos[idx].first] - 1];
				up = false;
			}

		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> A;
			cout << pos[A - 1].first << " " << pos[A - 1].second << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/11067