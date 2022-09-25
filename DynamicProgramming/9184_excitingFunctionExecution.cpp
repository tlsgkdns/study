#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> ans;
int dp[21][21][21], A, B, C;

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	int& ret = dp[a][b][c];
	if (ret >= 0) return ret;
	if (a < b && b < c) return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	while (true)
	{
		cin >> A >> B >> C;
		if (A == -1 && B == -1 && C == -1) break;
		cout << "w(" << A << ", " << B << ", " << C << ") = " << w(A, B, C) << '\n';
	}
}

// https://www.acmicpc.net/problem/9184