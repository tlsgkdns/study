#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<string> D[26];
int dp[101], N;
string S, A;

int solve(int idx)
{
	if (idx == S.size()) return 1;
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	int pos = S[idx] - 'a';
	ret = 0;
	for (int i = 0; i < D[pos].size(); ++i)
	{
		if (D[pos][i].size() > S.size() - idx) continue;
		string tmp(S.begin() + idx, S.begin() + idx + (int)D[pos][i].size());
		if (tmp == D[pos][i] && solve(idx + (int)D[pos][i].size()))
			ret = 1;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		D[A[0] - 'a'].push_back(A);
	}
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/16500