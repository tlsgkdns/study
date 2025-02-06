#include <iostream>
using namespace std;

int U, N, C, cnt[10001], ans = 0;
string S, M[10001], T[10001];
int main()
{
	cnt[0] = 1e9;
	cin >> U >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> C;
		cnt[C]++;
		if (T[C].empty())
			T[C] = S;
	}
	for (int i = 1; i <= U; i++)
		if (cnt[i] > 0 && cnt[ans] > cnt[i])
			ans = i;
	cout << T[ans] << " " << ans << '\n';
}

// https://www.acmicpc.net/problem/2238