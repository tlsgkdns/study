#include <iostream>
#include <cmath>

using namespace std;

int N;
char L[101][101];
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> S;
		int n = sqrt(S.size());
		for (int i = 0; i < S.size(); i++)
			L[i / n][i % n] = S[i];
		for (int j = n - 1; j >= 0; j--)
			for (int i = 0; i < n; i++)
				cout << L[i][j];
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/5426