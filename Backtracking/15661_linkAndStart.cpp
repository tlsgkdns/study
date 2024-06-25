#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> t1, t2;
int N, S[21][21], ans = 1000000007;
void solve(int now, int s1, int s2)
{
	if (now == N)
	{
		ans = min(ans, abs(s1 - s2));
		return;
	}
	int s = 0;
	for (int idx = 0; idx < t1.size(); idx++) s += (S[now][t1[idx]] + S[t1[idx]][now]);
	t1.push_back(now);
	solve(now + 1, s1 + s, s2);
	t1.pop_back();
	s = 0;
	for (int idx = 0; idx < t2.size(); idx++) s += (S[now][t2[idx]] + S[t2[idx]][now]);
	t2.push_back(now);
	solve(now + 1, s1, s2 + s);
	t2.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	solve(0, 0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15661