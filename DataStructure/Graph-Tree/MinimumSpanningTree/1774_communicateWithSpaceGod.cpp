#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

vector<int> parent;
int N, M, X, Y;

double getDist(int x1, int y1, int x2, int y2)
{
	return sqrt((double)pow(x2 - x1, 2) + (double)pow(y2 - y1, 2));
}

int getParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}
void merge(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a > b) swap(a, b);
	parent[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	vector<pair<int, int>> stars;
	vector<pair<double, pair<int, int>>> dists;
	vector<vector<double>> adj(N, vector<double>(N));
	for (int i = 0; i < N; i++) parent.push_back(i);
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		for (int j = 0; j < stars.size(); j++)
		{
			double d = getDist(X, Y, stars[j].first, stars[j].second);
			dists.push_back(make_pair(d, make_pair(i, j)));
			adj[i][j] = d;
			adj[j][i] = d;
		}
		stars.push_back({ X, Y });
	}
	sort(dists.begin(), dists.end());
	double ans = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		merge(X - 1, Y - 1);
	}
	for (int i = 0; i < dists.size(); i++)
	{
		int from = dists[i].second.first;
		int to = dists[i].second.second;
		if (getParent(from) == getParent(to)) continue;
		ans += adj[from][to];
		merge(from, to);
	}
	cout << fixed;
	cout.precision(2);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1774