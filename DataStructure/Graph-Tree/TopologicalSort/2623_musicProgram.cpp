#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> adj;
queue<int> q;
vector<int> entry, ans;
int main()
{
	cin >> N >> M;
	adj.resize(N + 1); entry.resize(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		vector<int> arr;
		int p, s;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			cin >> s;
			arr.push_back(s);
		}
		for (int j = 0; j < arr.size(); j++)
			for (int k = j + 1; k < arr.size(); k++)
			{
				adj[arr[j]].push_back(arr[k]);
				entry[arr[k]]++;
			}
	}
	for (int i = 1; i <= N; i++)
		if (entry[i] == 0) q.push(i);
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		ans.push_back(f);
		for (int nxt : adj[f])
		{
			entry[nxt]--;
			if (entry[nxt] == 0) q.push(nxt);
		}
	}
	if (ans.size() != N) cout << 0 << '\n';
	else
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/2623