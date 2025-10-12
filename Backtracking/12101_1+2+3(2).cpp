#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ans;
int N, K, n = 1;
bool f = false;
void solve(int num)
{
	if (f) return;
	if (num == 0)
	{
		if (K == n++)
		{
			f = true;
			cout << ans[0];
			for (int i = 1; i < ans.size(); i++)
				cout << "+" << ans[i];
			cout << '\n';
		}
		return;
	}
	for (int i = 1; i <= min(num, 3); i++)
	{
		ans.push_back(i);
		solve(num - i);
		ans.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	solve(N);
	if (!f) cout << -1 << '\n';
}

// https://www.acmicpc.net/problem/12101