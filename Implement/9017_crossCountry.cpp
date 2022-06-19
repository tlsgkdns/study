#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1000000000;
int T, N, C, R[1001];
int M[201], F[201], S[201];
bool V[201];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		memset(M, 0, sizeof(M)); memset(V, false, sizeof(M));
		memset(F, 0, sizeof(F)); memset(S, 0, sizeof(S));
		cin >> N; C = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> R[i];
			C = (C < R[i]) ? R[i] : C;
			M[R[i]]++;
			if (M[R[i]] == 5) F[R[i]] = i;
		}
		for (int i = 1; i <= C; i++)
			V[i] = (M[i] >= 6);
		int score = 1, win = 0; S[win] = INF;
		for (int i = 0; i < N; i++)
		{
			if (!V[R[i]]) continue;
			if (M[R[i]] > 2) S[R[i]] += score;
			score++;
			M[R[i]]--;
		}
		for (int i = 1; i <= C; i++)
		{
			if (!V[i] || S[i] > S[win]) continue;
			if (S[i] == S[win] && F[i] > F[win]) continue;
			win = i;
		}
		cout << win << '\n';
	}
}