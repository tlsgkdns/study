#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N, arr[101], M = 0, a1 = 1, a2 = 0, cnt[101];
bool isPrime[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int n = 2; n * n <= 1000000; n++)
	{
		if (!isPrime[n]) continue;
		for (int i = n * n; i <= 1000000; i += n)
			isPrime[i] = false;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (M < arr[i]) M = arr[i];
	}
	for (int n = 2; n <= M; n++)
	{
		if (!isPrime[n]) continue;
		memset(cnt, 0, sizeof(cnt));
		int S = 0, c1 = 0, c2 = 0;
		for (int i = 0; i < N; i++)
		{
			int tmp = arr[i];
			while (tmp % n == 0)
			{
				tmp /= n;
				++cnt[i]; ++S;
			}
		}
		S /= N;
		if (S == 0) continue;
		a1 *= pow(n, S);
		for (int i = 0; i < N; i++)
		{
			if (cnt[i] > S) c1 += cnt[i] - S;
			else c2 += S - cnt[i];
		}
		a2 += (c1 > c2) ? c2 : c1;
	}
	cout << a1 << " " << a2 << '\n';
}

// https://www.acmicpc.net/problem/2904