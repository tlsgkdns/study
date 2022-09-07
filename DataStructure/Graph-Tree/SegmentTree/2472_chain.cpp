#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using pli = pair<ll, ll>;
const int MAX = 100001;
const ll INF = 1LL << 60;
int S[3], N, X, Y, Z, T, Q, M;
vector<pli> adj[MAX];
vector<ll> tree;
vector<vector<ll>> num(3);
ll dist[MAX][3];
bool chain[MAX];
class city
{
public:
	ll xDist = 0, yDist = 0, zDist = 0, idx = -1;
	bool operator<(const city& c) const
	{
		if (xDist == c.xDist)
		{
			if (yDist == c.yDist) return zDist > c.zDist;
			return yDist > c.yDist;
		}
		return xDist < c.xDist;
	}
};
ll update(int node, int target, int s, int e, ll val)
{
	if (target > e || target < s) return tree[node];
	if (s == e) return tree[node] = val;
	int m = (s + e) / 2;
	return tree[node] = min(update(node * 2, target, s, m, val), update(node * 2 + 1, target, m + 1, e, val));
}
ll query(int node, int l, int r, int s, int e)
{
	if (e < l || s > r) return INF;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return min(query(node * 2, l, r, s, m), query(node * 2 + 1, l, r, m + 1, e));
}
int getIdx(vector<ll>& vec, ll v)
{
	return lower_bound(vec.begin(), vec.end(), v) - vec.begin();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 3; i++)
		cin >> S[i];
	vector<city> arr(N + 1);
	cin >> M;
	tree.resize(N * 4 + 1, INF);
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> Z;
		adj[X].push_back({ Y, Z });
		adj[Y].push_back({ X, Z });
	}
	for (int idx = 0; idx < 3; idx++)
	{
		for (int i = 1; i <= N; i++)
			dist[i][idx] = INF;
		dist[S[idx]][idx] = 0;
		priority_queue<pli> pq;
		pq.push({ 0, S[idx] });
		while (!pq.empty())
		{
			ll cost = -pq.top().first;
			ll here = pq.top().second;
			pq.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				ll there = adj[here][i].first;
				ll nxtCost = cost + adj[here][i].second;
				if (dist[there][idx] <= nxtCost) continue;
				dist[there][idx] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
	}
	for (int idx = 0; idx < 3; idx++)
	{
		for (int i = 1; i <= N; i++) num[idx].push_back(dist[i][idx]);
		sort(num[idx].begin(), num[idx].end());
	}
	for (int i = 1; i <= N; i++)
	{
		arr[i].xDist = getIdx(num[0], dist[i][0]) + 1;
		arr[i].yDist = getIdx(num[1], dist[i][1]) + 1;
		arr[i].zDist = getIdx(num[2], dist[i][2]) + 1;
		arr[i].idx = i;
	}
	sort(arr.begin() + 1, arr.end());
	for (int i = 1; i <= N; i++)
	{
		ll y = arr[i].yDist;
		ll z = arr[i].zDist;
		ll q = query(1, 0, y - 1, 0, N - 1);
		chain[arr[i].idx] = (query(1, 1, y - 1, 1, N) >= z);
		update(1, y, 1, N, min(z, query(1, y, y, 1, N)));
	}
	cin >> T;
	vector<bool> ans;
	while (T--)
	{
		cin >> Q;
		ans.push_back(chain[Q]);
	}
	for (bool a : ans)
		if (a) cout << "YES\n";
		else cout << "NO\n";
}

// https://www.acmicpc.net/problem/2472