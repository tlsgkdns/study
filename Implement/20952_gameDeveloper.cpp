#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
ll A, B, s = 0;
int N, M;
vector<pair<int, ll>> S[7];
vector<pair<int, ll>> ans;
bool v[7];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		S[A % 7].push_back({ i, A });
	}
	for (int i = 0; i < M; i++)
	{
		cin >> B;
		int idx = (7 - ((s + B) % 7)) % 7;
		if (N == S[idx].size()) continue;
		s += B;
		if (v[idx]) continue;
		v[idx] = true;
		N -= S[idx].size();
	}
	for (int i = 0; i < 7; i++)
		if (!v[i])
			for (int j = 0; j < S[i].size(); j++)
				ans.push_back(S[i][j]);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << (ans[i].second + s) % 1000000007 << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/20952