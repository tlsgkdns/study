#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> ans;
int T, N;
int arr[1001];
bool v[1001];
void dfs(int n)
{
	v[n] = true;
	if (!v[arr[n]]) dfs(arr[n]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> arr[i];
		memset(v, false, sizeof(v));
		int a = 0;
		for (int i = 1; i <= N; i++)
			if (!v[i])
			{
				dfs(i); a++;
			}
		ans.push_back(a);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/10451