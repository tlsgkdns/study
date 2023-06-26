#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<pair<int, int>> P;
pair<int, int> D = { 0, 0 };
int N, A, dp[301][50001], H = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		H += A;
		P.push_back({ -A, i });
	}
	H /= 2;
	sort(P.begin(), P.end());
	dp[0][0] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= 50000; j++)
		{
			if (dp[i][j] < 0) continue;
			if (j - P[i].first > H)
			{
				if (j - P[i].first > D.first)
				{
					D.first = j - P[i].first;
					D.second = i;
				}
				continue;
			}
			dp[i + 1][j] = dp[i][j];
			if (P[i].first == 0) continue;
			dp[i + 1][j - P[i].first] = i;
		}
	}
	vector<int> R;
	while (D.first > 0)
	{
		R.push_back(P[D.second].second + 1);
		D.first += P[D.second].first;
		D.second = dp[D.second][D.first];
	}
	cout << R.size() << '\n';
	sort(R.begin(), R.end());
	for (int i = 0; i < R.size(); i++) cout << R[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1226