#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int w, m;
vector<int> weight, marble;
vector<bool> ans;
bool dp[31][40001];

int main()
{
	cin >> w; weight.resize(w);
	for (int i = 0; i < w; i++) cin >> weight[i];
	cin >> m; marble.resize(m);
	for (int i = 0; i < m; i++) cin >> marble[i];
	for (int i = 0; i < w; i++)
		dp[i][weight[i]] = true;
	for (int i = 1; i < w; i++)
		for (int j = 1; j <= 40000; j++)
		{
			if (dp[i - 1][j])
			{
				dp[i][abs(weight[i] - j)] = true;
				dp[i][j] = true;
				dp[i][weight[i] + j] = true;
			}
		}
	for (int mar : marble)
	{
		char a = dp[w - 1][mar] ? 'Y' : 'N';
		cout << a << " ";
	}
	cout << '\n';
}

// https://www.acmicpc.net/problem/2629