#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, ans = 1000000;
string str;
bool v[10];
vector<int> order;
int S[10] = { 0 };
char B[10], F[10];
void solve(int d)
{
	if (d == N)
	{
		char p = F[order[0]];
		int a = 0;
		for (int i = 0; i < N; i++)
		{
			if (p != F[order[i]]) ++a;
			a += S[order[i]];
			p = B[order[i]];
		}
		ans = min(a, ans);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (v[i]) continue;
		v[i] = true;
		order.push_back(i);
		solve(d + 1);
		v[i] = false;
		order.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(S, 0, sizeof(S));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		char pr = str[0];
		F[i] = pr;
		for (int idx = 0; idx < (int)str.size(); idx++)
		{
			if (str[idx] != pr) ++S[i];
			pr = str[idx];
		}
		B[i] = pr;
	}
	solve(0); cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17359