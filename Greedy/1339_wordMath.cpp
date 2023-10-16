#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string W[11];
int C[26], N, D[26], ans = 0, cnt[26];
vector<pair<int, char>> A;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> W[i];
		for (int idx = 0; idx < W[i].size(); idx++)
			C[W[i][idx] - 'A'] += pow(10, W[i].size() - idx);
	}
	for (int i = 0; i < 26; i++)
		if (C[i] > 0)
			A.push_back({ -C[i], (i + 'A') });
	sort(A.begin(), A.end());
	for (int n = 9, idx = 0; idx < A.size(); idx++, n--) D[A[idx].second - 'A'] = n;
	for (int i = 0; i < N; i++)
		for (int idx = W[i].size() - 1, d = 1; idx >= 0; idx--, d *= 10)
			ans += D[W[i][idx] - 'A'] * d;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1339