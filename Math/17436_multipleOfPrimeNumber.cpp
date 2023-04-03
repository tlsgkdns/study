#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll M, ans = 0;
int N, P[11];
vector<int> S;
void calc()
{
	ll m = 1;
	for (int i = 0; i < S.size(); i++) m *= S[i];
	m = M / m;
	m = (S.size() % 2 == 0) ? -m : m;
	ans += m;
}
void solve(int idx, int d)
{
	if (S.size() == d)
	{
		calc();
		return;
	}
	if (S.size() + N - idx < d) return;
	solve(idx + 1, d);
	S.push_back(P[idx]);
	solve(idx + 1, d);
	S.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++) solve(0, i);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17436