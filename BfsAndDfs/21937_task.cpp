#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[100001];

int N, M, X, A, B;
bool v[100001];
int dfs(int here)
{
	int ret = 0;
	for (int& there : adj[here])
		if (!v[there])
		{
			v[there] = true;
			ret += dfs(there) + 1;
		}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[B].push_back(A);
	}
	cin >> X;
	v[X] = true;
	cout << dfs(X) << '\n';
}

// https://www.acmicpc.net/problem/21937