#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>
#define INF 10000
using namespace std;

vector<vector<int>> stats;
vector<int> t;
vector<bool> cache(1 << 20 + 1, false);
bitset<20> bb;

int half, n, m = 10000;

void team(int sc)
{
	if (cache[bb.to_ulong()]) return;
	cache[bb.to_ulong()] = true;
	if (t.size() == half)
	{
		int remain = 0;
		vector<int> link;
		for (int i = 0; i < n; i++)
			if (!bb[i])
			{
				link.push_back(i);
				for (int l : link)
					remain += stats[i][l] + stats[l][i];
			}
		m = min(m, abs(remain - sc));
	}

	for (int i = 0; i < n; i++)
	{
		if (bb[i]) continue;
		bb.set(i);
		int add = 0;
		for (int s : t) add += stats[s][i] + stats[i][s];
		t.push_back(i);
		team(sc + add);
		bb.reset(i);
		t.pop_back();
	}
}
int main()
{
	bb.reset();
	cin >> n; half = n / 2;
	stats.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> stats[i][j];
	team(0);
	cout << m << endl;
}

// https://www.acmicpc.net/problem/14889