#include <iostream>
#include <algorithm>
using namespace std;
int N, D, K, C, cnt = 1, ans = 0;
int sushi[30001], sel[3001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++) cin >> sushi[i];
	sel[C]++;
	for (int i = 0; i < K; i++)
	{
		if (sel[sushi[i]] == 0) cnt++;
		sel[sushi[i]]++;
	}
	ans = cnt;
	int l = 0, r = K - 1;
	do
	{
		sel[sushi[l]]--;
		if (sel[sushi[l]] == 0) cnt--;
		l = (l + 1) % N; r = (r + 1) % N;
		if (sel[sushi[r]] == 0) cnt++;
		sel[sushi[r]]++;
		ans = max(ans, cnt);
	} while (l != 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2531