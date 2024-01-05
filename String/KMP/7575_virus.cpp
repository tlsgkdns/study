#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, K, A;
vector<int> S[101];
string ans = "NO\n";
bool v[101];
vector<int> getPi(vector<int>& p)
{
	int m = p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
bool kmp(vector<int>& s, vector<int>& p)
{
	vector<int> pi = getPi(p);
	int n = s.size(), m = p.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1) return true;
			++j;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		while (M--)
		{
			cin >> A;
			S[i].push_back(A);
		}
	}
	for (int i = 0; i <= S[0].size() - K; i++)
	{
		memset(v, false, sizeof(v));
		int cnt = 0;
		vector<int> p(S[0].begin() + i, S[0].begin() + i + K);
		for (int idx = 1; idx < N; idx++)
			if (kmp(S[idx], p) && !v[idx])
			{
				v[idx] = true;
				++cnt;
			}
		reverse(p.begin(), p.end());
		for (int idx = 1; idx < N; idx++)
			if (kmp(S[idx], p) && !v[idx])
			{
				v[idx] = true;
				++cnt;
			}
		if (cnt == N - 1)
		{
			ans = "YES\n";
			break;
		}
	}
	cout << ans;
}

// https://www.acmicpc.net/problem/7575