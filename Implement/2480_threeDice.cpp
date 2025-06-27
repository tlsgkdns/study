#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C;
	if (A == B && B == C) ans = 10000 + A * 1000;
	else if (A == B) ans = 1000 + A * 100;
	else if (B == C) ans = 1000 + B * 100;
	else if (A == C) ans = 1000 + C * 100;
	else ans = max(A, max(B, C)) * 100;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2480