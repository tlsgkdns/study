#include <iostream>
#include <algorithm>

using namespace std;

int N, M, r = 0, c = 0;
char ch;
bool R[51], C[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == 'X')
			{
				R[i] = true;
				C[j] = true;
			}
		}
	for (int i = 0; i < N; i++) r += !R[i];
	for (int i = 0; i < M; i++) c += !C[i];
	cout << max(r, c) << '\n';
}

// https://www.acmicpc.net/problem/1236