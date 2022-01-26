#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

struct VectorHasher {
	int operator()(const set<pair<int, int>>& V) const {
		int hash = V.size();
		for (auto& i : V) {
			hash ^= i.first + i.second + 0x9e3779b9 + (hash << 6) + (hash >> 2);
		}
		return hash;
	}
};

unordered_map<set<pair<int, int>>, bool, VectorHasher> vum;
vector<pair<int, pair<int, int>>> pos;
bool v[50][50];
int farm[51][51];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int N, M, ans = 0, mx = 0;

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}

void solve(set<pair<int, int>>& arr, int s)
{
	if (vum.count(arr) != 0) return;
	if (arr.size() == M)
	{
		ans = max(ans, s);
		return;
	}
	if ((M - arr.size()) * mx + s < ans) return;
	vum[arr] = true;
	for (auto i = arr.begin(); i != arr.end(); i++)
	{
		for (int d = 0; d < 4; d++)
		{
			int ny = (*i).first + dy[d];
			int nx = (*i).second + dx[d];
			if (!inRange(ny, nx) || v[ny][nx]) continue;
			v[ny][nx] = true;
			arr.insert({ ny, nx });
			solve(arr, s + farm[ny][nx]);
			arr.erase({ ny, nx });
			v[ny][nx] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, false, sizeof(v));
	cin >> N >> M;
	pair<int, int> stt;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> farm[i][j];
			pos.push_back(make_pair(-farm[i][j], make_pair(i, j)));
			mx = max(mx, farm[i][j]);
		}
	sort(pos.begin(), pos.end());
	set<pair<int, int>> st;
	for (int i = 0; i < pos.size(); i++)
	{
		int y = pos[i].second.first;
		int x = pos[i].second.second;
		st.insert({ y, x });
		v[y][x] = true;
		solve(st, farm[y][x]);
		st.erase({ y, x });
		v[y][x] = false;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13614