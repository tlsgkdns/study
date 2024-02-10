#include <iostream>
#include <set>

using namespace std;

set<int> S;
int N, Q, cmd, X, A, P = 1, I;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		if (A == 1) S.insert(i);
	}
	while (Q--)
	{
		cin >> cmd;
		if (cmd == 3)
		{
			if (S.empty()) cout << -1 << '\n';
			else if (S.find(P) != S.end()) cout << 0 << '\n';
			else
			{
				auto iter = S.upper_bound(P);
				if (iter != S.end()) cout << *iter - P << '\n';
				else cout << N - P + *S.begin() << '\n';
			}
		}
		if (cmd == 1)
		{
			cin >> I;
			if (S.find(I) == S.end()) S.insert(I);
			else S.erase(I);
		}
		if (cmd == 2)
		{
			cin >> X;
			P = ((P - 1 + X) % N) + 1;
		}
	}
}

// https://www.acmicpc.net/problem/23326