#include <iostream>
#include <vector>
using namespace std;
int dp[30000][3000], N, M, K, P[30000], A, B, cnt[30000], C[30000];
bool v[30000];
vector<int> candy, group;

int find(int a)
{
	if (P[a] == a) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (a < b) swap(a, b);
	P[b] = a;
	cnt[a] += cnt[b];
	C[a] += C[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		P[i] = i;
		cnt[i] = 1;
		cin >> C[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		merge(A - 1, B - 1);
	}
	for (int i = 0; i < N; i++)
	{
		int p = find(i);
		if (!v[p])
		{
			v[p] = true;
			group.push_back(cnt[p]);
			candy.push_back(C[p]);
		}
	}
	for (int i = 0; i < group.size(); i++)
	{
		for (int j = 0; j < K; j++)
			if (group[i] > j) dp[i][j] = ((i == 0) ? 0 : dp[i - 1][j]);
			else dp[i][j] = max(((i == 0) ? 0 : dp[i - 1][j]), candy[i] + (i == 0 ? 0 : dp[i - 1][j - group[i]]));
	}
	cout << dp[group.size() - 1][K - 1] << '\n';
}

// https://www.acmicpc.net/problem/20303