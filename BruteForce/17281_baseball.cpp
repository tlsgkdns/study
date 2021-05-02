#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = -1;
vector<vector<int>> info;

struct game
{
	vector<bool> bases;
	vector<int> order;
	int outCnt, inn = 0, hitter = 0;
	game(vector<int>& ord)
	{
		bases.resize(3, false);
		order = ord;
		outCnt = 0;
		inn = 0;
	}
	int singleHit()
	{
		int sc = 0;
		if (bases[2])
		{
			sc++;
			bases[2] = false;
		}
		for (int i = 1; i >= 0; i--)
			if (bases[i])
			{
				bases[i + 1] = true;
				bases[i] = false;
			}
		bases[0] = true;
		return sc;
	}
	int doubleHit()
	{
		int sc = 0;
		for (int i = 2; i > 0; i--)
		{
			if (bases[i])
			{
				sc++;
				bases[i] = false;
			}
		}
		if (bases[0])
		{
			bases[2] = true;
			bases[0] = false;
		}
		bases[1] = true;
		return sc;
	}
	int tripleHit()
	{
		int sc = 0;
		for (int i = 2; i >= 0; i--)
		{
			if (bases[i]) sc++;
			bases[i] = false;
		}
		bases[2] = true;
		return sc;
	}
	int homeRun()
	{
		int sc = 0;
		for (int i = 2; i >= 0; i--)
		{
			if (bases[i]) sc++;
			bases[i] = false;
		}
		sc++;
		return sc;
	}
	bool out()
	{
		outCnt++;
		if (outCnt == 3)
		{
			inn++;
			outCnt = 0;
			for (int i = 0; i < 3; i++)
				bases[i] = false;
		}
		if (inn == n) return true;
		return false;
	}
	int nextHitter()
	{
		int nxt = hitter + 1;
		if (nxt == 9) nxt = 0;
		return nxt;
	}
	int run()
	{
		int score = 0;
		bool gameSet = false;
		while (!gameSet)
		{
			switch (info[inn][order[hitter]])
			{
			case 0:
				gameSet = out();
				break;
			case 1:
				score += singleHit();
				break;
			case 2:
				score += doubleHit();
				break;
			case 3:
				score += tripleHit();
				break;
			case 4:
				score += homeRun();
				break;
			}
			hitter = nextHitter();
		}
		return score;
	}
};

void solve(vector<int>& ord, vector<bool>& set, int setting)
{
	if (setting == 9)
	{
		game g(ord);
		ans = max(g.run(), ans);
		return;
	}
	if (ord[setting] != -1)
	{
		solve(ord, set, setting + 1);
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		if (set[i]) continue;
		set[i] = true;
		ord[setting] = i;
		solve(ord, set, setting + 1);
		set[i] = false;
		ord[setting] = -1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; info.resize(n, vector<int>(9));
	vector<int> ord(9, -1);
	vector<bool> set(9, false);
	ord[3] = 0; set[0] = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 9; j++)
			cin >> info[i][j];
	solve(ord, set, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17281