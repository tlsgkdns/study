#include <iostream>

using namespace std;
int cnt[7], A, N, ans = -1, idx[7];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		cnt[A]++;
		idx[A] = i;
	}
	for (int i = 6; i >= 1; i--)
		if (cnt[i] == 1)
		{
			ans = idx[i] + 1;
			break;
		}
	if (ans < 0) cout << "none\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11213