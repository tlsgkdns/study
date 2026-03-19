#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M, ans = 0;
char C[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> C[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (i < N - 2)
			{
				string s = "";
				s.push_back(C[i][j]);
				s.push_back(C[i + 1][j]);
				s.push_back(C[i + 2][j]);
				ans += (s == "FOX" || s == "XOF");
			}
			if (j < M - 2)
			{
				string s = "";
				s.push_back(C[i][j]);
				s.push_back(C[i][j + 1]);
				s.push_back(C[i][j + 2]);
				ans += (s == "FOX" || s == "XOF");
			}
			if (i < N - 2 && j < M - 2)
			{
				string s = "";
				s.push_back(C[i][j]);
				s.push_back(C[i + 1][j + 1]);
				s.push_back(C[i + 2][j + 2]);
				ans += (s == "FOX" || s == "XOF");
			}
			if (i < N - 2 && j >= 2)
			{
				string s = "";
				s.push_back(C[i][j]);
				s.push_back(C[i + 1][j - 1]);
				s.push_back(C[i + 2][j - 2]);
				ans += (s == "FOX" || s == "XOF");
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/34238