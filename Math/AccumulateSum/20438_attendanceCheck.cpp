#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
int N, K, Q, M, A, acc[5005], S, E;
bool D[5005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> Q >> M;
	for (int i = 0; i < K; i++)
	{
		cin >> A;
		D[A] = true;
	}
	N += 2;
	for (int i = 1; i <= N; i++) acc[i] = 1;
	for (int i = 0; i < Q; i++)
	{
		cin >> A;
		if (D[A]) continue;
		for (int n = A; n <= N; n += A)
		{
			if (D[n]) continue;
			acc[n] = 0;
		}
	}
	for (int i = 1; i <= N; i++)
		acc[i] += acc[i - 1];
	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;
		cout << (acc[E] - acc[S - 1]) << '\n';
	}
}

// https://www.acmicpc.net/problem/20438