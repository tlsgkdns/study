#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, ans = 0;
string result[4] = { "Invalid", "Equilateral", "Isosceles", "Scalene" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0) break;
		int m = max(A, max(B, C));
		if (2 * m >= (A + B + C)) ans = 0;
		else if (A == B && B == C) ans = 1;
		else if (A == B || B == C || A == C) ans = 2;
		else ans = 3;
		cout << result[ans] << '\n';
	}
}

// https://www.acmicpc.net/problem/5073