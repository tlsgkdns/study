#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<pair<int, int>> arr;
const int MAX = 301, INF = 1000000007;
int N, adj[MAX][MAX], A, B, Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (A > B) swap(A, B);
		arr.push_back({ A, B });
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			adj[i][j] = INF;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (arr[i].second >= arr[j].first && arr[j].second >= arr[i].first)
			{
				adj[i][j] = 1;
				adj[j][i] = 1;
			}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	cin >> Q;
	while (Q--)
	{
		cin >> A >> B;
		cout << (adj[A - 1][B - 1] >= INF ? -1 : adj[A - 1][B - 1]) << '\n';
	}
}

// https://www.acmicpc.net/problem/14588