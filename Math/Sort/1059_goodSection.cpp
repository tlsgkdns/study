#include <iostream>
#include <algorithm>
using namespace std;
int L, n, S[51], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	for (int i = 1; i <= L; i++) cin >> S[i];
	cin >> n;
	sort(S, S + L + 1);
	for (int i = 0; i < L; i++)
	{
		if (S[i] == n) break;
		if (S[i + 1] > n)
		{
			ans = (S[i + 1] - n) * (n - S[i]) - 1;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1059