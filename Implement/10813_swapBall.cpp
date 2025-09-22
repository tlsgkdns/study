#include <iostream>

using namespace std;

int N, M, ans[101], a, b;

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) ans[i] = i;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		swap(ans[a], ans[b]);
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/10813