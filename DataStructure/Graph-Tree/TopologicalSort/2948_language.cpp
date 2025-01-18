#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
string ans = "";
bool adj[26][26], alp[26];
int N, indegree[26], D[26];
string W[101];
bool f = false;
vector<int> ch;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(D, -1, sizeof(D));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> W[i];
		for (int idx = 0; idx < W[i].size(); idx++)
		{
			int a = W[i][idx] - 'a';
			if (!alp[a])
			{
				ch.push_back(a);
				alp[a] = true;
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			int idx = 0;
			for (idx = 0; idx < min(W[i].size(), W[j].size()); idx++)
				if (W[i][idx] != W[j][idx])
				{
					int a = W[i][idx] - 'a';
					int b = W[j][idx] - 'a';
					if (!adj[a][b])
					{
						indegree[b]++;
						adj[a][b] = true;
					}
					break;
				}
			if (idx == min(W[i].size(), W[j].size()) && W[i].size() > W[j].size())
			{
				f = true;
			}
		}
	queue<int> q;
	int ord = 0;
	for (int i = 0; i < ch.size(); i++)
	{
		if (indegree[ch[i]] == 0)
		{
			q.push(ch[i]);
			D[ch[i]] = ord++;
		}
	}
	while (q.size() == 1)
	{
		int here = q.front();
		q.pop();
		for (int there = 0; there < 26; there++)
			if (adj[here][there])
			{
				indegree[there]--;
				if (indegree[there] == 0)
				{
					D[there] = ord++;
					q.push(there);
				}
			}
	}
	if (!f && q.size() > 1) cout << "?\n";
	else
	{
		string ans(ch.size(), '#');
		for (int i = 0; i < ch.size(); i++)
		{
			if (D[ch[i]] < 0)
			{
				f = true;
				break;
			}
			ans[D[ch[i]]] = (ch[i] + 'a');
		}
		if (f) cout << "!\n";
		else cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/2848