#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> order;
int N, ans = 1000000007;
char ch;
bool C[12], v[12];
bool checkWin()
{
	int s1 = 0, s2 = 0;
	for (int i = 0; i < 2 * N; i += 2)
	{
		if (C[order[i]] == C[order[i + 1]]) continue;
		s1 += C[order[i]]; s2 += C[order[i + 1]];
	}
	return s1 > s2;
}
void solve(int cnt)
{
	if (cnt >= ans) return;
	int p = 0;
	for (int i = 0; i < 2 * N; i++)
	{
		if (v[i]) continue;
		order.push_back(i); ++p;
	}
	if (checkWin()) ans = min(ans, cnt);
	while (p--) order.pop_back();
	for (int i = 1; i < 2 * N; i++)
		if (!v[i])
		{
			v[i] = true;
			order.push_back(i);
			solve(cnt + 1);
			v[i] = false;
			order.pop_back();
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 2 * N; i++)
	{
		cin >> ch;
		C[i] = (ch == 'O');
	}
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/23749