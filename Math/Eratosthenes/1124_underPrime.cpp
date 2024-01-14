#include <iostream>
using namespace std;

bool P[100001];
int A, B, D[100001], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 2; i <= 100000; i++) D[i] = 1;
	cin >> A >> B;
	for (int i = 2; i * i <= 100000; i++)
	{
		if (D[i] > 1) continue;
		for (int j = i * i; j <= 100000; j += i)
		{
			D[j] = i;
		}
	}
	for (int n = A; n <= B; n++)
	{
		int tmp = n, cnt = 1;
		while (D[tmp] > 1)
		{
			tmp /= D[tmp];
			++cnt;
		}
		if (D[cnt] == 1) ++ans;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1124