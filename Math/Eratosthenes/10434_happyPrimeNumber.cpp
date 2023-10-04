#include <iostream>
#include <cstring>

using namespace std;

int P, M, N;
bool v[10002], isPrime[10002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= 10001; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= 10001; j += i)
			isPrime[j] = false;
	}
	cin >> P;
	while (P--)
	{
		cin >> N >> M;
		string ans = " NO\n";
		if (isPrime[M])
		{
			int num = M;
			memset(v, false, sizeof(v));
			while (num != 1 && !v[num])
			{
				int nxt = 0;
				v[num] = true;
				int d = 1;
				while ((num / d) > 0)
				{
					int tmp = ((num / d) % (d * 10));
					tmp %= 10;
					nxt += tmp * tmp;
					d *= 10;
				}
				num = nxt;
			}
			if (num == 1) ans = " YES\n";
		}
		cout << N << " " << M << ans;
	}
}

// https://www.acmicpc.net/problem/10434