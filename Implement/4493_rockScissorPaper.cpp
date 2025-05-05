#include <iostream>

using namespace std;

int T, N;
char c1, c2;
int chk()
{
	if (c1 == c2) return 0;
	if (c1 == 'S' && c2 == 'P') return 1;
	if (c1 == 'P' && c2 == 'R') return 1;
	if (c1 == 'R' && c2 == 'S') return 1;
	return 2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int s1 = 0, s2 = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> c1 >> c2;
			int c = chk();
			if (c == 1) s1++;
			else if (c == 2) s2++;
		}
		if (s1 == s2) cout << "TIE\n";
		else if (s1 > s2) cout << "Player 1\n";
		else cout << "Player 2\n";
	}
}

// https://www.acmicpc.net/problem/4493