#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2001;
vector<int> adj[MAX];
int cnt[MAX];
int N, M, K, L;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> K;
		while (K--)
		{
			cin >> L;
			cnt[L]++;
			adj[i].push_back(L);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (ans > 0) break;
		bool f = true;
		for (int j = 0; j < adj[i].size(); j++)
			if (cnt[adj[i][j]] <= 1)
			{
				f = false;
				break;
			}
		if (f) ans = 1;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16960