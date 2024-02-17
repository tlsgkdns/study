#include <iostream>

using namespace std;

int N, ans = 0, v[1001], cnt = 0;
string S;

void dfs(int idx)
{
	int nxt = (S[idx] == 'E') ? idx + 1 : idx - 1;
	if (v[nxt] == v[idx]) return;
	if (v[nxt] > 0 && v[nxt] != v[idx])
	{
		--ans;
		return;
	}
	v[nxt] = v[idx];
	dfs(nxt);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> S;
	for (int i = 0; i < N; i++)
		if (v[i] == 0)
		{
			v[i] = ++cnt;
			dfs(i);
			++ans;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15886