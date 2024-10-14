#include <iostream>
#include <algorithm>

using namespace std;

int N, D, K, C, S[3000001], cnt = 1, E[3001], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++) cin >> S[i];
	E[C]++;
	for (int i = 0; i < K; i++)
	{
		if (E[S[i]] == 0) ++cnt;
		E[S[i]]++;
	}
	ans = max(ans, cnt);
	for (int l = 0; l < N; l++)
	{
		int r = (K + l) % N;
		E[S[l]]--;
		if (E[S[l]] == 0) --cnt;
		if (E[S[r]] == 0) ++cnt;
		E[S[r]]++;
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15961