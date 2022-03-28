#include <iostream>
#include <unordered_map>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;
queue<pair<vector<int>, int>> q;
vector<vector<int>> adj = { {1, 3}, {0, 2, 4}, {1, 5},
							{0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8},
							{3, 7}, {4, 6, 8}, {5, 7} };
unordered_map <ll, int> m;
int ans = -1;
ll k;
ll getKey(vector<int>& arr)
{
	ll ret = 0;
	for (int i = 0; i < 9; i++)
		ret += pow(10, 8 - i) * arr[i];
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> board(9), b(9);
	int s;
	for (int i = 0; i < 9; i++)
	{
		cin >> board[i];
		if (board[i] == 0)
		{
			board[i] = 9;
			s = i;
		}
	}
	m[getKey(board)] = 0;
	q.push({ board, s });
	while (!q.empty())
	{
		b = q.front().first;
		int idx = q.front().second;
		q.pop();
		bool br = true;
		int cnt = m[getKey(b)];
		for (int i = 0; i < 9; i++)
			if (b[i] != i + 1)
				br = false;
		if (br)
		{
			ans = cnt;
			break;
		}
		for (int i = 0; i < adj[idx].size(); i++)
		{
			swap(b[idx], b[adj[idx][i]]);
			k = getKey(b);
			if (m.count(k) == 0)
			{
				m[k] = cnt + 1;
				q.push({ b, adj[idx][i] });
			}
			swap(b[idx], b[adj[idx][i]]);
		}
	}
	cout << ans << '\n';
}

//https://www.acmicpc.net/problem/1525