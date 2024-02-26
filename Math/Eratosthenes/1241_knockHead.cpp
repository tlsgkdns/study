#include <iostream>

using namespace std;

long long N, E[1000001], A[1000001], cnt[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		++cnt[A[i]];
	}
	for (int i = 1; i <= 1000000; i++)
		for (int j = i; j <= 1000000; j += i)
			E[j] += cnt[i];
	for (int i = 0; i < N; i++) cout << E[A[i]] - 1 << '\n';
}

// https://www.acmicpc.net/problem/1241