#include <iostream>
#include <vector>

using namespace std;

int J, R;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> J >> R;
	vector<int> score(J + 1);
	int ans = 1, win = -1, sc;
	for (int i = 0; i < R; i++)
	{
		for (int j = 1; j <= J; j++)
		{
			cin >> sc;
			score[j] += sc;
		}
	}
	for (int j = 1; j <= J; j++)
		if (win <= score[j])
		{
			win = score[j];
			ans = j;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13604