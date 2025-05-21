#include <iostream>
#include <algorithm>

using namespace std;
int N, K, E[100001], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> K;
	for (int i = 1; i <= 100000; i++) E[i] = i;
	for (int i = 2; i <= 100000; i++)
		if (E[i] == i)
			for (int j = 2 * i; j <= 100000; j += i)
				E[j] = i;
	for (int i = 1; i <= N; i++)
		ans += (E[i] <= K);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1418