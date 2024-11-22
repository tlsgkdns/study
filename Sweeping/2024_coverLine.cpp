#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> line;
int L, R, M, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	while (true)
	{
		cin >> L >> R;
		if (L == 0 && R == 0) break;
		if (R < 0 || L > M) continue;
		line.push_back({ L, R });
	}
	line.push_back({ M, 50001 });
	sort(line.begin(), line.end());
	int l = 0, r = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i].first > l)
		{
			if (line[i].first > r)
			{
				ans = 0;
				break;
			}
			else
			{
				l = r;
				r = line[i].second;
				++ans;
			}
		}
		else
			r = max(r, line[i].second);
	}
	if (r < M) ans = 0;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2024