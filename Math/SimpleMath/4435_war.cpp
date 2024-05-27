#include <iostream>

using namespace std;

int T, G, S;
int score1[6] = { 1, 2, 3, 3, 4, 10 };
int score2[7] = { 1, 2, 2, 2, 3, 5, 10 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int s1 = 0, s2 = 0;
		for (int i = 0; i < 6; i++)
		{
			cin >> G;
			s1 += (G * score1[i]);
		}
		for (int i = 0; i < 7; i++)
		{
			cin >> S;
			s2 += (S * score2[i]);
		}
		cout << "Battle " << t << ": ";
		if (s1 > s2) cout << "Good triumphs over Evil\n";
		else if (s1 < s2) cout << "Evil eradicates all trace of Good\n";
		else cout << "No victor on this battle field\n";
	}
}

// https://www.acmicpc.net/problem/4435