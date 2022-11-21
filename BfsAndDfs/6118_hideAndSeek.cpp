#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, A, B, cnt = 0, num, D = 0;
const int MAX = 50001;
vector<int> adj[MAX];
bool v[50001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	queue<int> q;
	v[1] = true;
	q.push(1);
	while (!q.empty())
	{
		int s = q.size();
		cnt = s; num = N + 1; ++D;
		while (s--)
		{
			int here = q.front();
			num = min(num, here);
			q.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i];
				if (v[there]) continue;
				v[there] = true;
				q.push(there);
			}
		}
	}
	cout << num << " " << D - 1 << " " << cnt << '\n';
}

// https://www.acmicpc.net/problem/6118