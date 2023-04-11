#include <iostream>
#include <algorithm>
using namespace std;

int N, K, G, X, M = 0;
int B[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> G >> X;
		M = max(M, X);
		B[X] = G;
	}
	int idx1 = 0, idx2 = 0, s = 0;
	while (idx2 <= min(M, 2 * K))
		s += B[idx2++];
	int ans = s;
	while (idx2 <= M)
	{
		s -= B[idx1++];
		s += B[idx2++];
		ans = max(s, ans);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10025