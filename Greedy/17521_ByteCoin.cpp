#include <iostream>

using namespace std;

long long N, S[15], cnt = 0, W;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> S[i];
	for (int i = 0; i < N - 1; i++)
	{
		if (S[i] < S[i + 1] && cnt == 0)
		{
			cnt = (W / S[i]);
			W = W % S[i];
		}
		if (S[i] > S[i + 1] && cnt > 0)
		{
			W += S[i] * cnt;
			cnt = 0;
		}
	}
	if (cnt > 0) W += S[N - 1] * cnt;
	cout << W << '\n';
}

// https://www.acmicpc.net/problem/17521