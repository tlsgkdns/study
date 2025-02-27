#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, string> member;
unordered_map<string, vector<string>> team;
string t, m, n;
int N, M, C, tp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		cin >> C;
		while (C--)
		{
			cin >> m;
			team[t].push_back(m);
			member[m] = t;
		}
		sort(team[t].begin(), team[t].end());
	}
	while (M--)
	{
		cin >> n;
		cin >> tp;
		if (tp == 0)
		{
			vector<string>& arr = team[n];
			for (const string& ans : arr)
				cout << ans << '\n';
		}
		else
			cout << member[n] << '\n';
	}
}

// https://www.acmicpc.net/problem/16165