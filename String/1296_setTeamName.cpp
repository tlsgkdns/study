#include <iostream>
#include <algorithm>

using namespace std;

string Y, T[51];
int N, cnt[4], ans = 0, c = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> Y;
	for (int i = 0; i < Y.size(); i++)
	{
		cnt[0] += (Y[i] == 'L');
		cnt[1] += (Y[i] == 'O');
		cnt[2] += (Y[i] == 'V');
		cnt[3] += (Y[i] == 'E');
	}
	cin >> N;
	for (int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	for (int i = 0; i < N; i++)
	{
		int tmp[4] = {};
		for (int j = 0; j < 4; j++) tmp[j] = cnt[j];
		for (int j = 0; j < T[i].size(); j++)
		{
			tmp[0] += (T[i][j] == 'L');
			tmp[1] += (T[i][j] == 'O');
			tmp[2] += (T[i][j] == 'V');
			tmp[3] += (T[i][j] == 'E');
		}
		int s = tmp[0] + tmp[1];
		for (int idx = 0; idx < 4; idx++)
			for (int idx2 = ((idx == 0) ? 2 : idx + 1); idx2 < 4; idx2++)
			{
				s *= (tmp[idx] + tmp[idx2]);
			}
		s %= 100;
		if (c < s)
		{
			c = s;
			ans = i;
		}
	}
	cout << T[ans] << '\n';
}

// https://www.acmicpc.net/problem/1296