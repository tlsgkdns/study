#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, X[10], P[20];
vector<int> ans;
bool f = false;
void solve()
{
	if (f) return;
	if (ans.size() == 2 * N)
	{
		f = true;
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (P[X[i]] == -1)
		{
			P[X[i]] = ans.size();
			ans.push_back(X[i]);
			solve();
			ans.pop_back();
			P[X[i]] = -1;
		}
		else if (P[X[i]] + X[i] + 1 == (int)ans.size())
		{
			ans.push_back(X[i]);
			solve();
			ans.pop_back();
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(P, -1, sizeof(P));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i];
	sort(X, X + N);
	solve();
	if (!f) cout << -1 << '\n';
}

// https://www.acmicpc.net/problem/1469