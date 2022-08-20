#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int N, M, K, L, ans = 0;
vector<pii> SS;
vector<int> X, Y;
int dx1[4] = { 0, -1, -1, 0 };
int dy1[4] = { 0, 0, -1, -1 };
int dx2[4] = { 1, 0, 0, 1 };
int dy2[4] = { 1, 1, 0, 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> L >> K;
	SS.resize(K);
	for (int i = 0; i < K; i++)
	{
		cin >> SS[i].first >> SS[i].second;
		X.push_back(SS[i].first);
		Y.push_back(SS[i].second);
	}
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			for (int d = 0; d < 4; d++)
			{
				int cnt = 0;
				int X1 = X[i] + dx1[d] * L;
				int Y1 = Y[j] + dy1[d] * L;
				int X2 = X[i] + dx2[d] * L;
				int Y2 = Y[j] + dy2[d] * L;
				for (int idx = 0; idx < K; idx++)
					if (X1 <= SS[idx].first && X2 >= SS[idx].first && Y1 <= SS[idx].second && Y2 >= SS[idx].second)
						cnt++;
				ans = max(ans, cnt);
			}
	cout << (K - ans) << '\n';
}

// https://www.acmicpc.net/problem/14658