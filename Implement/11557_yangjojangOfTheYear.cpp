#include <iostream>
#include <algorithm>

using namespace std;
int T, N, L;
string S, ans = "";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int p = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> S >> L;
			if (p < L)
			{
				p = L;
				ans = S;
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/11557