#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
vector<vector<int>> dp, invested;
vector<vector<int>> company;
int n, m, money, inv;

int solve(int mon, int comp)
{
	if (comp > m) return 0;
	int& ret = dp[mon][comp];
	if (ret != -1) return ret;
	ret = 0;
	int s = solve(mon, comp + 1);
	for (int i = 0; i <= mon; i++)
	{
		int s = solve(mon - i, comp + 1) + company[i][comp];
		if (ret < s)
		{
			ret = s;
			invested[mon][comp] = i;
		}
	}
	return ret;
}

void reconstruct()
{
	int t = n;
	for (int i = 1; i <= m; i++)
	{
		cout << invested[t][i] << " ";
		t -= invested[t][i];
	}
	cout << '\n';
}
int main()
{
	cin >> n >> m;
	dp.resize(n + 1, vector<int>(m + 1, -1));
	invested.resize(n + 1, vector<int>(m + 1, 0));
	vector<int> z(m + 1, 0);
	company.push_back(z);
	for (int i = 0; i < n; i++)
	{
		vector<int> info;
		cin >> money;
		info.push_back(money);
		for (int j = 0; j < m; j++)
		{
			cin >> inv;
			info.push_back(inv);
		}
		company.push_back(info);
	}
	cout << solve(n, 1) << '\n';
	reconstruct();
}

// https://www.acmicpc.net/problem/2662