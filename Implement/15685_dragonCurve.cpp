#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> dg(101, vector<bool>(101, false));
pair<int, int> clock[4]
{
	{1, 0}, {0, -1}, {-1, 0}, {0, 1}
};
int nextID(int id)
{
	int ret = id;
	if (id == 3) ret = 0;
	else ret++;
	return ret;
}
int main()
{
	int n, x, y, d, g, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> g;
		pair<int, int> s = { x, y };
		vector<int> v;
		v.push_back(d);
		dg[s.first][s.second] = true;
		s.first += clock[d].first;
		s.second += clock[d].second;
		dg[s.first][s.second] = true;
		for (int j = 0; j < g; j++)
		{
			int vs = v.size();
			for (int id = vs - 1; id >= 0; id--)
			{
				int nxt = nextID(v[id]);
				pair<int, int> p = clock[nxt];
				v.push_back(nxt);
				s = { p.first + s.first,  p.second + s.second };
				dg[s.first][s.second] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (dg[i][j] && dg[i + 1][j] && dg[i][j + 1] && dg[i + 1][j + 1])
				ans++;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15685