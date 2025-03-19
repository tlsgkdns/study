#include <iostream>
using namespace std;

int N, A, B, ans1 = 100, ans2 = 100;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> A >> B;
		if (A == B) continue;
		if (A < B) ans1 -= B;
		else ans2 -= A;
	}
	cout << ans1 << '\n' << ans2 << '\n';
}

// https://www.acmicpc.net/problem/10103