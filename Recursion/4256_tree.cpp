#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int preOrder[1001], inOrder[1001], dic[1001];
int T, N;
vector<vector<int>> ans;
void solve(int sp, int ep, int si, int ei, int n)
{
	if (sp >= ep || si >= ei) return;
	int preSize = dic[preOrder[sp]] - si;
	solve(sp + 1, sp + preSize + 1, si, si + preSize, n);
	solve(sp + preSize + 1, ep, si + preSize + 1, ei, n);
	ans[n].push_back(preOrder[sp]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	ans.resize(T);
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> preOrder[i];
		for (int i = 0; i < N; i++)
		{
			cin >> inOrder[i];
			dic[inOrder[i]] = i;
		}
		solve(0, N, 0, N, t);
	}
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}
// https://www.acmicpc.net/problem/4256