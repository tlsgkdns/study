#include <iostream>
#include <algorithm>

using namespace std;

int N, ans1 = 0, ans2 = 0;
bool G[101][101];
char ch;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			G[i][j] = (ch == 'X');
		}
	for (int i = 0; i < N; i++)
	{
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < N; j++)
		{
			if (G[i][j]) cnt1 = 0;
			else ++cnt1;
			if (G[j][i]) cnt2 = 0;
			else ++cnt2;
			ans1 += (cnt1 == 2);
			ans2 += (cnt2 == 2);
		}
	}
	cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/1652