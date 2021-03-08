#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> city;
const int INF = 1000000000;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	city.resize(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		city[a - 1][b - 1] = min(c, city[a - 1][b - 1]);
	}
	for (int i = 0; i < n; i++) city[i][i] = 0;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (city[i][j] == INF) cout << 0 << " ";
			else cout << city[i][j] << " ";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/11404

/*
basic floyd problem
*/