#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<bool> ans;
vector<int> page, pos;
int T, N;

bool canFold()
{
	stack<int> s[2];
	int idx, nxt;
	for (int i = 1; i <= N; i++)
	{
		idx = (pos[i] % 2 == 1);
		if (pos[i] != N - 1)
		{
			nxt = page[pos[i] + 1];
			if (nxt < i)
			{
				if (s[idx].empty() || s[idx].top() != i)
					return false;
				else
					s[idx].pop();
			}
			else
				s[idx].push(nxt);
		}
		if (pos[i] != 0)
		{
			idx = !idx;
			nxt = page[pos[i] - 1];
			if (nxt < i)
			{
				if (s[idx].empty() || s[idx].top() != i)
					return false;
				else
					s[idx].pop();
			}
			else
				s[idx].push(nxt);
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		page = vector<int>(N);
		pos = vector<int>(N + 1);
		for (int i = 0; i < N; i++)
		{
			cin >> page[i];
			pos[page[i]] = i;
		}
		ans.push_back(canFold());
	}
	for (bool a : ans)
		if (a) cout << "YES\n";
		else cout << "NO\n";
}

// https://www.acmicpc.net/problem/1391