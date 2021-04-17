#include <iostream>
#include <vector>
using namespace std;
int n, m, d;
void add(int& s, int& ans)
{
	int num = (s - d) + 1;
	ans += (num > 0) ? num : 0;
	s = 0;
}
int main()
{
	cin >> n >> m >> d;
	vector<vector<bool>> place(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			place[i][j] = (c == '.');
		}

	int ans = 0, succ = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (place[i][j]) succ++;
			else
				add(succ, ans);
		add(succ, ans);
	}
	succ = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (place[j][i]) succ++;
			else
				add(succ, ans);
		add(succ, ans);
	}

	cout << ans << endl;
}

// https://www.acmicpc.net/problem/14472