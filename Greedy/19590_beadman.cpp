#include <iostream>
#include <algorithm>

using namespace std;

int N, X[100001];
long long S = 0, L = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		S += X[i];
	}
	sort(X, X + N, greater<int>());
	L = X[0]; S -= X[0];
	if (L > S) cout << L - S << '\n';
	else cout << (S + L) % 2 << '\n';
}

// https://www.acmicpc.net/problem/19590