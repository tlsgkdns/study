#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int R, C, ans = 0;
string S[1001], W[1001];
unordered_map<string, bool> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> S[i];
	for (int c = 0; c < C; c++)
		for (int r = 0; r < R; r++)
			W[c].push_back(S[r][c]);
	while (true)
	{
		bool b = false;
		for (int i = 0; i < C; i++)
		{
			string ns = string(W[i].begin() + 1 + ans, W[i].end());
			if (s.find(ns) != s.end())
			{
				b = true;
				break;
			}
			s[ns] = true;
		}
		if (b) break;
		s.clear();
		++ans;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2866