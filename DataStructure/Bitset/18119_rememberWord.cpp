#include <iostream>
#include <cmath>

using namespace std;
int N, M, C, Q[10001];
string S;
char X;
long long B = pow(2, 26) - 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		for (int idx = 0; idx < S.size(); idx++)
			Q[i] |= (1 << (S[idx] - 'a'));
	}
	for (int i = 0; i < M; i++)
	{
		cin >> C >> X;
		if (C == 1) B ^= (1 << (X - 'a'));
		else B |= (1 << (X - 'a'));
		int ans = 0;
		for (int j = 0; j < N; j++)
			ans += (B & Q[j]) == Q[j];
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/18119