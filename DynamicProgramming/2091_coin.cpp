#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int coin[4], price[4] = { 1, 5, 10, 25 };
int dp[40001][4];
int X, S = 0;
bool v[40001];
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X;
	for (int i = 0; i < 4; i++)
	{
		cin >> coin[i];
		S += price[i] * coin[i];
	}
	for (int i = 0; i < 4; i++) dp[S][i] = coin[i];
	q.push(S);
	v[S] = true;
	while (!q.empty())
	{
		int money = q.front();
		q.pop();
		if (money == X) break;
		for (int i = 0; i < 4; i++)
		{
			if (dp[money][i] == 0) continue;
			int next = money - price[i];
			if (next < X || v[next]) continue;
			v[next] = true;
			for (int idx = 0; idx < 4; idx++) dp[next][idx] = dp[money][idx];
			dp[next][i]--;
			q.push(next);
		}
	}
	for (int i = 0; i < 4; i++) cout << dp[X][i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2091