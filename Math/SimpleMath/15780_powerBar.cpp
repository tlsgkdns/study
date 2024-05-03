#include <iostream>

using namespace std;

int N, K, M[101], s = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> M[i];
		s += (M[i] / 2) + (M[i] % 2);
	}
	if (s >= N) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/15780