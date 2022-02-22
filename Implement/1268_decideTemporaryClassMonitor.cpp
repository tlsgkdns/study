#include <iostream>

using namespace std;

int N, ans, ov = -1;
int stud[1001][5];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++)
		{
			cin >> stud[i][j];
		}

	for (int s = 0; s < N; s++)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 5; j++)
			{
				if (stud[s][j] == stud[i][j])
				{
					cnt++;
					break;
				}
			}
		if (ov < cnt)
		{
			ov = cnt;
			ans = s + 1;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1268