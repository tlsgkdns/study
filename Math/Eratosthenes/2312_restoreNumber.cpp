#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 100001;
int T, N, D[MAX], ans[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(D, -1, sizeof(D));
	for (int i = 2; i * i < MAX; i++)
	{
		if (D[i] < 0)
		{
			for (int j = i + i; j <= MAX; j += i)
				D[j] = i;
		}
	}
	cin >> T;
	while (T--)
	{
		memset(ans, 0, sizeof(ans));
		cin >> N;
		while (D[N] > 0)
		{
			ans[D[N]]++;
			N /= D[N];
		}
		ans[N]++;
		for (int i = 2; i < MAX; i++)
			if (ans[i] > 0)
				cout << i << " " << ans[i] << '\n';
	}
}

// https://www.acmicpc.net/problem/2312