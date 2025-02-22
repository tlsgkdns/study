#include <iostream>
#include <bitset>

using namespace std;

int N, Q, A, B;
char c;
bitset<2001> F[2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			F[i].set(j, (c - '0'));
		}
	cin >> Q;
	while (Q--)
	{
		cin >> A >> B;
		cout << (F[A] & F[B]).count() << '\n';
	}
}

// https://www.acmicpc.net/problem/20501