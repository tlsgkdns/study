#include <iostream>
#include <algorithm>

using namespace std;

int N, S[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 2 * N; i++) cin >> S[i];
	sort(S, S + 2 * N);
	int s = 1e9 + 7;
	for (int i = 0; i < N; i++)
		s = min(s, S[i] + S[2 * N - i - 1]);
	cout << s << '\n';
}

// https://www.acmicpc.net/problem/20044