#include <iostream>

using namespace std;
int N, A, ans = 0;
bool P[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (P[A]) ++ans;
		else P[A] = true;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1453