#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
int N, A[27], ans = 0;
bool v[27], U[10];
string W[15], C;

ll getNum(int i)
{
	ll d = 1, ret = 0;
	for (int idx = W[i].size() - 1; idx >= 0; idx--)
	{
		ret += (A[W[i][idx] - 'A'] * d);
		d *= 10;
	}
	return ret;
}
bool calc()
{
	ll s = 0;
	if (A[W[N - 1][0] - 'A'] == 0 && W[N - 1].size() > 1) return false;
	for (int i = 0; i < N - 1; i++)
	{
		if (A[W[i][0] - 'A'] == 0 && W[i].size() > 1) return false;
		s += getNum(i);
	}
	return (s == getNum(N - 1));
}
void solve(int idx)
{
	if (idx == C.size())
	{
		ans += calc();
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (U[i]) continue;
		A[C[idx] - 'A'] = i;
		U[i] = true;
		solve(idx + 1);
		U[i] = false;
		A[C[idx] - 'A'] = -1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		memset(v, false, sizeof(v)); memset(A, -1, sizeof(A));
		memset(U, false, sizeof(U)); C = "";
		ans = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> W[i];
			for (int idx = 0; idx < W[i].size(); idx++)
			{
				if (v[W[i][idx] - 'A']) continue;
				v[W[i][idx] - 'A'] = true;
				C.push_back(W[i][idx]);
			}
		}
		solve(0);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/4964