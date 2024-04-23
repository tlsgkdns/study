#include <iostream>
#include <set>

using namespace std;
set<int> S;
int T[100001], N, M, C, I, X;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> C;
		if (C <= 2)
		{
			cin >> I >> X;
			if (C == 1) T[I] = (T[I] | (1 << (X - 1)));
			else if (T[I] & (1 << (X - 1)))
				T[I] &= ~(1 << (X - 1));
		}
		else
		{
			cin >> I;
			if (C == 3) T[I] = (T[I] << 1);
			else T[I] = (T[I] >> 1);
			T[I] = (T[I] & 0xfffff);
		}
	}
	for (int i = 1; i <= N; i++) S.insert(T[i]);
	cout << S.size() << '\n';
}

// https://www.acmicpc.net/problem/15787