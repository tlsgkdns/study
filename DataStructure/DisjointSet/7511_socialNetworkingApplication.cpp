#include <iostream>
using namespace std;

int A, B, M, U, V, T, N, P[1000001], K;
int find(int a)
{
	if (P[a] == a) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a < b) swap(a, b);
	P[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++) P[i] = i;
		cin >> K;
		while (K--)
		{
			cin >> A >> B;
			merge(A, B);
		}
		cin >> M;
		cout << "Scenario " << t << ":\n";
		while (M--)
		{
			cin >> U >> V;
			cout << (find(U) == find(V)) << '\n';
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/7511