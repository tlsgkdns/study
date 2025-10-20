#include <iostream>
#include <algorithm>

using namespace std;
int N, S[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	sort(S, S + N);
	cout << S[N - 1] - S[0] << '\n';
}

// https://www.acmicpc.net/problem/15969