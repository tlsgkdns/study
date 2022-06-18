#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int N, A, B, P, Q;
const int MAX = 10;
vector<int> adj[MAX];
bool v[MAX];
ll ratio[MAX];
int gcd(ll a, ll b)
{
	if (a < b) swap(a, b);
	while (b > 0)
	{
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

void dfs(int here, int mul)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		ratio[there] *= mul;
		dfs(there, mul);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) ratio[i] = 1;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B >> P >> Q;
		ll m1 = (ratio[A] * Q); ll m2 = (ratio[B] * P);
		ratio[A] *= m2; ratio[B] *= m1;
		memset(v, false, sizeof(v));
		v[A] = true;  dfs(A, m2);
		memset(v, false, sizeof(v));
		v[B] = true;  dfs(B, m1);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	ll div = ratio[0];
	for (int i = 1; i < N; i++) div = gcd(div, ratio[i]);
	for (int i = 0; i < N; i++)
	{
		ratio[i] /= div;
		cout << ratio[i] << " ";
	}
	cout << '\n';
}

// https://www.acmicpc.net/problem/1033