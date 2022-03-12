#include <iostream>

using namespace std;

int res[30], ans[30];
int N, idx = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> res[i];
	ans[0] = res[0];
	int val = res[0];
	for (int i = 1; i < N; i++)
	{
		idx = (idx + res[i - 1]) % N;
		val = ans[idx];
		while (val != 0)
		{
			idx = (idx + 1) % N;
			val = ans[idx];
		}
		ans[idx] = res[i];
	}
	cout << N << '\n';
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/8981