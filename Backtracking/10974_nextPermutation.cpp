#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
bool v[10];
int N;

void solve()
{
	if (ans.size() == N)
	{
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
		if (!v[i])
		{
			v[i] = true;
			ans.push_back(i);
			solve();
			v[i] = false;
			ans.pop_back();
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	solve();
}

// https://www.acmicpc.net/problem/10974