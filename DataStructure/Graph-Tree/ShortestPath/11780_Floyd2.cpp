#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000007;
int N, M, A, B, C, adj[101][101], P[101][101];
void getPath(vector<int>& R, int here, int there)
{
	int mid = P[here][there];
	if (here == mid)
	{
		R.push_back(here);
		return;
	}
	getPath(R, here, mid);
	getPath(R, mid, there);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i != j) adj[i][j] = INF;
			else adj[i][j] = 0;
			P[i][j] = i;
		}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A][B] = min(adj[A][B], C);
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];
					P[i][j] = k;
				}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (adj[i][j] == INF) cout << "0 ";
			else cout << adj[i][j] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j || adj[i][j] == INF) cout << 0 << '\n';
			else
			{
				vector<int> r;
				getPath(r, i, j);
				r.push_back(j);
				cout << r.size() << " ";
				for (int idx = 0; idx < r.size(); idx++)
					cout << r[idx] << " ";
				cout << '\n';
			}
		}
}

// https://www.acmicpc.net/problem/11780