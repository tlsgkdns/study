#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int R, N, v[1001], A;
int solve(const vector<int>& X, int idx)
{
	if (idx == X.size()) return 0;
	int i = idx + 1;
	while (i < X.size() && X[idx] + R >= X[i]) ++i;
	int i2 = i;
	while (i2 < X.size() && X[i - 1] + R >= X[i2]) ++i2;
	return solve(X, i2) + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> R >> N;
		if (R < 0 && N < 0) break;
		memset(v, false, sizeof(v));
		vector<int> X;
		for (int i = 0; i < N; i++)
		{
			cin >> A;
			if (v[A]) continue;
			X.push_back(A);
			v[A] = true;
		}
		sort(X.begin(), X.end());
		cout << solve(X, 0) << '\n';
	}
}

// https://www.acmicpc.net/problem/7676