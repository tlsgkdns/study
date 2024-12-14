#include <iostream>

using namespace std;

long long ans = 0, d[1000001];
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j += i)
			d[j] += i;
	}
	for (int i = 1; i <= N; i++) ans += d[i];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17427