#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, M, indegree[MAX], cnt = 0;
map<string, int> m;
string str, X, Y, names[MAX];
vector<int> adj[MAX], adj2[MAX];
vector<string> sorted;
bool cmp(int a, int b)
{
	return names[a] < names[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> names[i];
		m[names[i]] = i;
		sorted.push_back(names[i]);
	}
	sort(sorted.begin(), sorted.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		adj[m[Y]].push_back(m[X]);
		indegree[m[X]]++;
	}
	queue<int> q;
	vector<int> arr;
	for (int i = 0; i < N; i++)
		if (indegree[i] == 0)
			arr.push_back(i);
	sort(arr.begin(), arr.end(), cmp);
	cout << arr.size() << '\n';
	for (int i = 0; i < arr.size(); i++)
	{
		q.push(arr[i]);
		cout << names[arr[i]] << " ";
	}
	cout << '\n';
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			indegree[there]--;
			if (indegree[there] == 0)
			{
				adj2[here].push_back(there);
				q.push(there);
			}
		}
	}
	for (int i = 0; i < N; i++) sort(adj2[i].begin(), adj2[i].end(), cmp);
	for (int i = 0; i < N; i++)
	{
		int now = m[sorted[i]];
		cout << sorted[i] << " " << adj2[now].size() << " ";
		for (int idx = 0; idx < adj2[now].size(); idx++) cout << names[adj2[now][idx]] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/21276