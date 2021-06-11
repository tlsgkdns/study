#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;
using ll = long long;
int parent[100003];
ll weight[100003];
void resize(int num)
{
	memset(weight, 0, sizeof(weight));
	for (int i = 1; i <= num; i++)
		parent[i] = i;
}
int find(ll u)
{
	if (u == parent[u]) return u;
	int tmp = find(parent[u]);
	weight[u] += weight[parent[u]];
	return parent[u] = tmp;
}

void merge(ll u, ll v, ll w)
{
	int p1 = find(u);
	int p2 = find(v);
	if (p1 == p2) return;

	parent[p2] = p1;
	weight[p2] = weight[u] - weight[v] + w;
}

ll getDiff(ll a, ll b)
{
	return weight[b] - weight[a];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n, m;
	vector<ll> ans;
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		resize(n);
		for (int i = 0; i < m; i++)
		{
			int a, b, w;
			char cmd;
			cin >> cmd;
			if (cmd == '!')
			{
				cin >> a >> b >> w;
				merge(a, b, w);
			}
			else
			{
				cin >> a >> b;
				if (find(a) == find(b))
					cout << getDiff(a, b) << '\n';
				else
					cout << "UNKNOWN\n";
			}
		}
	}
}

// https://www.acmicpc.net/problem/3830