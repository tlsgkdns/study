#include <iostream>
#include <cstring>

using namespace std;

bool R[101];
int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		memset(R, true, sizeof(R));
		int ans = N;
		for (int i = 2; i <= N; i++)
			for (int j = i; j <= N; j += i)
			{
				ans += ((R[j]) ? -1 : 1);
				R[j] = !R[j];
			}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/6359