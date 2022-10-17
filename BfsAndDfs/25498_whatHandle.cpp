#include <iostream>
#include <queue>
using namespace std;
const int MAX = 500001;
int N, U, V;
string str, ans = "";
vector<int> adj[MAX];
bool v[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> str;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> U >> V;
		adj[U - 1].push_back(V - 1);
		adj[V - 1].push_back(U - 1);
	}
	v[0] = true;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		ans.push_back(str[q.front()]);
		int s = q.size();
		char ch = 'a';
		vector<int> tmp;
		while (s--)
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i];
				if (v[there]) continue;
				if (ch < str[there]) ch = str[there];
				tmp.push_back(there);
			}
		}
		for (int i = 0; i < tmp.size(); i++)
			if (ch == str[tmp[i]])
			{
				q.push(tmp[i]);
				v[tmp[i]] = true;
			}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25498