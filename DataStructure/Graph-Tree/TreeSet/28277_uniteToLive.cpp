#include <iostream>
#include <set>

using namespace std;

int N, Q, n, s, c, a, b, idx[500001];
set<int> S[500001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> n;
		idx[i] = i;
		while (n--)
		{
			cin >> s;
			S[i].insert(s);
		}
	}
	while (Q--)
	{
		cin >> c;
		if (c == 1)
		{
			cin >> a >> b;
			if (S[idx[a]].size() < S[idx[b]].size())
				swap(idx[a], idx[b]);
			for (auto it = S[idx[b]].begin(); it != S[idx[b]].end(); it++)
				S[idx[a]].insert(*it);
			S[idx[b]].clear();
		}
		else
		{
			cin >> a;
			cout << S[idx[a]].size() << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/28277