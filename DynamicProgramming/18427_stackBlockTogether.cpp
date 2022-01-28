#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int N, M, H;
int dp[51][1001];
string input;
vector<vector<int>> blks;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> H;
	blks.resize(N + 1);
	getline(cin, input);
	for (int i = 1; i <= N; i++)
	{
		getline(cin, input);
		stringstream ss(input);
		string tmp;
		while (getline(ss, tmp, ' '))
			blks[i].push_back(stoi(tmp));
	}
	for (int n = 1; n <= N; n++)
		for (int i = 0; i < blks[n].size(); i++)
			dp[n][blks[n][i]] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int h = 1; h <= H; h++) dp[i][h] += dp[i - 1][h] % 10007;
		for (int j = 0; j < blks[i].size(); j++)
			for (int k = blks[i][j]; k <= H; k++)
				dp[i][k] += (dp[i - 1][k - blks[i][j]]) % 10007;
	}
	cout << dp[N][H] % 10007 << '\n';
}

// https://www.acmicpc.net/problem/18427