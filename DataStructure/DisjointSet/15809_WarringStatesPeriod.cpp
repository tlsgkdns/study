#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ans;
int P[100001], S[100001], N, M, o, p, q;
bool v[100001];
int getParent(int a)
{
	if (P[a] == a) return a;

	return P[a] = getParent(P[a]);
}
void merge(int a, int b, bool war)
{
	if (a < b) swap(a, b);
	a = getParent(a); b = getParent(b);
	if (a != b)
	{
		if (war)
		{
			if (S[a] > S[b]) swap(a, b);
			S[b] -= S[a];
		}
		else
		{
			S[b] += S[a];
		}
	}
	P[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		P[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> o >> p >> q;
		merge(p, q, (o == 2));
	}
	for (int i = 1; i <= N; i++)
	{
		int idx = getParent(i);
		if (v[idx] || S[idx] == 0) continue;
		v[idx] = true;
		ans.push_back(S[idx]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/15809