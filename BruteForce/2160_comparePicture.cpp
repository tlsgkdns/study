#include <iostream>

using namespace std;
char P[51][5][7];
int N, a1 = 0, a2 = 0, cm = 100000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 7; x++)
				cin >> P[i][y][x];
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			int c = 0;
			for (int y = 0; y < 5; y++)
				for (int x = 0; x < 7; x++)
					c += (P[i][y][x] != P[j][y][x]);
			if (c < cm)
			{
				a1 = i; a2 = j;
				cm = c;
			}
		}
	cout << a1 + 1 << " " << a2 + 1 << '\n';
}

// https://www.acmicpc.net/problem/2160