#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;
vector<int> adj[300001];
ll v[300001][4];
int N, U, V;
ll D = 0, G = 0;
string ans = "DUDUDUNGA";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}
	for (int here = 1; here <= N; here++)
	{
		ll s = adj[here].size();
		if (s >= 3)
			G += (s * (s - 1) * (s - 2)) / 6;
		if (s >= 2)
		{
			for (int& there : adj[here])
				if (adj[there].size() >= 2)
					D += (s - 1) * (adj[there].size() - 1);
		}

	}
	D /= 2;
	if (D < 3 * G) ans = "G";
	if (D > 3 * G) ans = "D";
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/19535