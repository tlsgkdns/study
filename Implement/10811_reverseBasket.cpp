#include <iostream>

using namespace std;
int N, M, B[101], L, R;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) B[i] = i;
	for (int i = 0; i < M; i++)
	{
		cin >> L >> R;
		for (int l = L, r = R; l < r; l++, r--)
		{
			int tmp = B[l];
			B[l] = B[r];
			B[r] = tmp;
		}
	}
	for (int i = 1; i <= N; i++) cout << B[i] << " ";
}

// https://www.acmicpc.net/problem/10811