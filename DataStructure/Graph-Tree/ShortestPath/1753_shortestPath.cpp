#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;
const int INF = numeric_limits<int>::max();
int v, e, s, src, des, l;
vector<list<pair<int, int>>> con;
vector<int> d;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main()
{
	cin >> v >> e;
	cin >> s;
	d = vector<int>(v + 1, INF);
	con = vector<list<pair<int, int>>>(v + 1);
	for (int i = 0; i < e; i++)
	{
		cin >> src >> des >> l;
		con[src].push_back(make_pair(des, l));
	}
	d[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty())
	{
		int c = pq.top().first;
		int h = pq.top().second;
		pq.pop();
		if (d[h] < c) continue;

		for (auto t : con[h])
		{
			if (d[t.first] > t.second + c)
			{
				d[t.first] = t.second + c;
				pq.push(make_pair(d[t.first], t.first));
			}
		}
	}
	for (int i = 1; i < d.size(); i++)
	{
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}
}

// https://www.acmicpc.net/problem/1753

/*
Dijkstra training
*/