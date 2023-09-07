#include <iostream>

using namespace std;

int N, G[101], S[101], B[101], ans = 0;
bool cnt[101][11];
int getDigit(int num, int d)
{
	return (num % (d * 10)) / (d);
}
bool cmp(int num, int idx)
{
	int s = 0, b = 0;
	bool tmp[10] = { false, };
	for (int d = 1; d <= 100; d *= 10)
	{
		int n = getDigit(num, d);
		if (n == 0 || tmp[n]) return false;
		tmp[n] = true;
		if (n == getDigit(G[idx], d)) ++s;
		else if (cnt[idx][n]) ++b;
	}
	return (b == B[idx] && s == S[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> G[i] >> S[i] >> B[i];
		for (int d = 1; d <= 100; d *= 10)
			cnt[i][getDigit(G[i], d)] = true;
	}
	for (int n = 111; n < 1000; n++)
	{
		bool C = true;
		for (int i = 0; i < N; i++)
			if (!cmp(n, i))
			{
				C = false;
				break;
			}
		ans += C;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2503