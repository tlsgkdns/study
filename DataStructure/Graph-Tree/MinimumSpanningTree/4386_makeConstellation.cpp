#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<double>> cost;
vector<pair<int, int>> pos;
vector<int> set;
double getDist(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int getParent(int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set[x]);
}

bool find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	return 0;
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) set[b] = a;
	else set[a] = b;
}

int main()
{
	int n; double sum = 0;
	cin >> n;
	cost = vector<vector<double>>(n + 1, vector<double>(n + 1, 0));
	vector<pair<double, pair<int, int>>> edge;
	set = vector<int>(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		pos.push_back(make_pair(x, y));
		set[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			edge.push_back(make_pair(getDist(pos[i].first, pos[i].second,
				pos[j].first, pos[j].second), make_pair(i, j)));
		}
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++)
	{
		if (!find(edge[i].second.first, edge[i].second.second))
		{
			sum += edge[i].first;
			unionParent(edge[i].second.first, edge[i].second.second);
		}
	}
	cout << sum << '\n';
}

// https://www.acmicpc.net/problem/4386