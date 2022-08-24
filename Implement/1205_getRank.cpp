#include <iostream>

using namespace std;

int N, S, P, s, e, ans = -1;
bool change = false;
int score[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S >> P;
	for (int i = 0; i < N; i++) cin >> score[i];
	s = N + 1, e = N + 1;
	for (int i = 0; i < N; i++)
	{
		if (!change && score[i] == S)
		{
			s = i + 1;
			change = true;
		}
		else if (score[i] < S)
		{
			if (!change) s = i + 1;
			e = i + 1;
			break;
		}
	}
	if (e <= P) ans = s;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1205