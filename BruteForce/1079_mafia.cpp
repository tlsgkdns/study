#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int night(vector<bool>, vector<int>, int);
int day(vector<bool>, vector<int>, int);
int N, mafia;
vector<vector<int>> R;
vector<int> guilty;

int night(vector<bool> dead, vector<int> g, int alive)
{
	if (alive <= 2) return 1;
	vector<int> tmp = g;
	int ret = 0;
	for (int person = 0; person < N; person++)
	{
		if (person == mafia || dead[person]) continue;
		dead[person] = true;
		for (int i = 0; i < N; i++)
			g[i] += R[person][i];
		ret = max(day(dead, g, alive - 1) + 1, ret);
		dead[person] = false;
		g = tmp;
	}
	return ret;
}
int day(vector<bool> dead, vector<int> g, int alive)
{
	if (alive <= 1) return 0;
	int sacrifice = mafia;
	for (int person = N - 1; person >= 0; person--)
	{
		if (dead[person]) continue;
		if (g[person] >= g[sacrifice]) sacrifice = person;
	}
	if (sacrifice == mafia) return 0;
	dead[sacrifice] = true;
	return night(dead, g, alive - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	R.resize(N, vector<int>(N));
	guilty.resize(N);
	vector<bool> dead(N, false);
	for (int i = 0; i < N; i++)
		cin >> guilty[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> R[i][j];
	cin >> mafia;
	if (N % 2 == 1) cout << day(dead, guilty, N) << '\n';
	else cout << night(dead, guilty, N) << '\n';
}
// https://www.acmicpc.net/problem/1079