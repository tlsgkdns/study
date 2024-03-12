#include <iostream>
#include <algorithm>

using namespace std;

int N, K, X[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> X[i];
	sort(X, X + N, greater<int>());
	cout << X[K - 1] << '\n';
}

// https://www.acmicpc.net/problem/25305