#include <iostream>
#include <cstring>
using namespace std;

bool v[100001];
int N, M, P, A, B, H[100001], L[100001], ans = 0;

int dfs(int here)
{
	if (v[here]) return -1000000000;
	if (H[here] == -1) return 0;
	v[here] = true;
	return dfs(L[H[here]]) + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> P;
	memset(H, -1, sizeof(H));
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (H[B] < 0) H[B] = i;
		L[i] = A;
	}
	int ans = dfs(P);
	if (ans < 0) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10552