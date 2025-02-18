#include <iostream>
#include <algorithm>

using namespace std;
int N, A, B, C, ans = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> A >> B >> C;
		if (A == B && B == C)
			ans = max(ans, A * 1000 + 10000);
		else if (A == B || A == C)
			ans = max(ans, A * 100 + 1000);
		else if (B == C)
			ans = max(ans, B * 100 + 1000);
		else
			ans = max(ans, max(A, max(B, C)) * 100);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2476