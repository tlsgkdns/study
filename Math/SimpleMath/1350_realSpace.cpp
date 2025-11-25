#include <iostream>
using namespace std;
int N;
long long F[51], cnt = 0, C;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> F[i];
	cin >> C;
	for (int i = 0; i < N; i++)
	{
		cnt += (F[i] / C) + (F[i] % C > 0);
	}
	cout << cnt * C << '\n';
}

// https://www.acmicpc.net/problem/1350