#include <iostream>

using namespace std;

int N, cnt[201], n, v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		cnt[n + 100]++;
	}
	cin >> v;
	cout << cnt[v + 100] << '\n';
}

// https://www.acmicpc.net/problem/10807