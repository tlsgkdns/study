#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topSort(vector<vector<bool>>& adj, vector<int>& indegree, int N)
{
	vector<int> ret(N + 1);
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			q.push(i);
	for (int i = 1; i <= N; i++)
	{
		if (q.empty())
			return vector<int>();
		int here = q.front();
		q.pop();
		ret[i] = here;
		for (int j = 1; j <= N; j++)
		{
			if (!adj[here][j]) continue;
			if (--indegree[j] == 0) q.push(j);
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	vector<vector<int>> ans;
	for (int t = 0; t < T; t++)
	{
		int N, M, a, b;
		cin >> N;
		vector<int> rk(N);
		vector<vector<bool>> adj(N + 1, vector<bool>(N + 1, false));
		for (int i = 0; i < N; i++)
		{
			cin >> rk[i];
			for (int j = 0; j < i; j++)
				adj[rk[j]][rk[i]] = true;
		}
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			if (adj[a][b])
			{
				adj[a][b] = false;
				adj[b][a] = true;
			}
			else if (adj[b][a])
			{
				adj[b][a] = false;
				adj[a][b] = true;
			}
		}
		vector<int> ind(N + 1, 0);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (adj[i][j]) ind[j]++;
		vector<bool> arr(N + 1, false);
		bool unknown = false;
		for (int i = 1; i < ind.size(); i++)
		{
			if (arr[ind[i]])
			{
				unknown = true;
				break;
			}
			arr[ind[i]] = true;
		}
		vector<int> ret;
		ret = topSort(adj, ind, N);
		if (!ret.empty() && unknown)
		{
			ret = vector<int>();
			ret.push_back(-1);
		}
		ans.push_back(ret);
	}
	for (vector<int> as : ans)
	{
		if (as.empty()) cout << "IMPOSSIBLE\n";
		else if (as[0] == -1) cout << "?\n";
		else
		{
			for (int i = 1; i < as.size(); i++)
				cout << as[i] << " ";
			cout << '\n';
		}
	}
}
// https://www.acmicpc.net/problem/3665