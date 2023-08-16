#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> S;
int D, N, M, A;

bool solve(int s)
{
	int idx = 0, cnt = 0;
	while (idx < S.size())
	{
		int idx2 = idx + 1;
		while (idx2 < S.size() && S[idx] + s > S[idx2]) ++idx2;
		if (idx2 == S.size() - 1) break;
		if (idx2 == S.size()) return false;
		++cnt;
		idx = idx2;
	}
	return cnt >= N - M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D >> N >> M;
	S.push_back(0); S.push_back(D);
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		S.push_back(A);
	}
	sort(S.begin(), S.end());
	int l = 0, r = D + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) l = m;
		else r = m;
	}

	cout << l << '\n';
}

// https://www.acmicpc.net/problem/6209