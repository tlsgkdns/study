#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int MAX = 51;
int N, D1, P1, D2, P2, ans = 0;
vector<pii> lines;
vector<int> cnts;
int t(int a, int b)
{
	if (a == 1) return b;
	if (a == 2) return 3 * MAX - b;
	if (a == 3) return 4 * MAX - b;
	return MAX + b;
}
int main()
{
	cin >> N; N /= 2;
	cnts.resize(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> D1 >> P1 >> D2 >> P2;
		int p1 = t(D1, P1), p2 = t(D2, P2);
		if (p1 > p2) swap(p1, p2);
		lines.push_back({ p1, p2 });
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			if (lines[i].first > lines[j].first&& lines[i].first < lines[j].second && lines[i].second > lines[j].second)
			{
				cnts[i]++;
				cnts[j]++;
				ans++;
			}
		}
	}
	cout << ans << '\n';
	cout << *max_element(cnts.begin(), cnts.end()) << '\n';
}

// https://www.acmicpc.net/problem/2650