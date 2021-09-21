#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 1;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void eat(vector<vector<char>>& cad)
{
	char base = 'b';
	int l = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (base != cad[i][j])
			{
				ans = max(l, ans);
				l = 1;
				base = cad[i][j];
			}
			else
				l++;
		}
		ans = max(l, ans);
		base = 'b'; l = 1;
	}
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (base != cad[i][j])
			{
				ans = max(l, ans);
				l = 1;
				base = cad[i][j];
			}
			else
				l++;
		}
		ans = max(l, ans);
		base = 'b'; l = 1;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<vector<char>> candy(N, vector<char>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> candy[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i + 1 < N)
			{
				swap(candy[i][j], candy[i + 1][j]);
				eat(candy);
				swap(candy[i][j], candy[i + 1][j]);
			}
			if (j + 1 < N)
			{
				swap(candy[i][j], candy[i][j + 1]);
				eat(candy);
				swap(candy[i][j], candy[i][j + 1]);
			}
		}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/3085