#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

vector<int> adj[27];
int N, M, L, ans = 0;
int indegree[27];
char A, B, C;
bool arr[27];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(indegree, 0, sizeof(indegree));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		++indegree[B - 'A'];
		adj[A - 'A'].push_back(B - 'A');
	}
	cin >> L;
	while (L--)
	{
		cin >> C;
		arr[C - 'A'] = true;
	}
	queue<int> q;
	for (int i = 0; i < N; i++)
		if (indegree[i] == 0 && !arr[i])
			q.push(i);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (arr[there]) continue;
			++ans;
			q.push(there);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17220