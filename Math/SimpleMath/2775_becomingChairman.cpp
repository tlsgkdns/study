#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> apt(15, vector<int>(15, 0));
vector<int> a;
int main()
{
	for (int i = 1; i < apt.size(); i++)apt[0][i] = i;
	for (int p = 1; p < apt.size(); p++)
		for (int q = 1; q < apt.size(); q++)
			for (int r = 1; r <= q; r++)
				apt[p][q] += apt[p - 1][r];
	int t, n, k;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		a.push_back(apt[n][k]);
	}
	for (int e : a) cout << e << '\n';
}

// https://www.acmicpc.net/problem/2775

/*
k, n was very small, so just calculate was helpful.
*/