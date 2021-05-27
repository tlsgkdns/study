#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> house;
int M, N;

void grow(vector<int> g)
{
	int idx = 0;
	for (int i = M - 1; i >= 0; i--, idx++)
		house[i][0] += g[idx];
	for (int i = 1; i < M; i++, idx++)
		house[0][i] += g[idx];
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	vector<int> ed(3), g(2 * M - 1, 0);
	house.resize(M, vector<int>(M, 1));
	for (int day = 0; day < N; day++)
	{
		for (int i = 0; i < 3; i++)
			cin >> ed[i];
		int idx = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < ed[i]; j++, idx++)
				g[idx] += i;
	}
	grow(g);
	for (int j = 1; j < M; j++)
		for (int i = 1; i < M; i++)
			house[i][j] = house[0][j];
	for (vector<int> hou : house)
	{
		for (int h : hou)
			cout << h << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/10836