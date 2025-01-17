#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 1000001;
int N, A, S[MAX], M[MAX], cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i < MAX; i++) S[i] = i;
	for (ll i = 2; i * i < MAX; i++)
		if (S[i] == i)
		{
			for (ll j = i + i; j < MAX; j += i)
				S[j] = i;
		}
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		while (S[A] > 1)
		{
			if (++M[S[A]] % 2 > 0) ++cnt;
			else if (cnt > 0) --cnt;
			A /= S[A];
		}
		if (cnt == 0) cout << "DA\n";
		else cout << "NE\n";
	}
}

// https://www.acmicpc.net/problem/3142