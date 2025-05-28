#include <iostream>

using namespace std;
int N, F, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> F;
	for (int i = 0; i <= 99; i++)
	{
		N = (N / 100) * 100 + i;
		if (N % F == 0)
		{
			ans = i;
			break;
		}
	}
	if (ans < 10) cout << 0;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1075