#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> anss;
struct seg
{
	vector<int> tree, dic;
	int sz = 0;
	seg(int n, int m)
	{
		sz = n + m;
		tree.resize(sz * 4);
		dic.resize(n);
	}
	int init(int node, int m, int s, int e)
	{
		if (s == e)
		{
			if (s >= m)
			{
				dic[s - m] = s;
				tree[node] = 1;
			}
			return tree[node];
		}
		int mid = (s + e) / 2;
		return tree[node] = init(node * 2, m, s, mid) + init(node * 2 + 1, m, mid + 1, e);
	}
	void init(int m)
	{
		init(1, m, 0, sz - 1);
	}
	int query(int node, int s, int e, int nL, int nR)
	{
		if (e < nL || nR < s) return 0;
		if (s <= nL && e >= nR) return tree[node];
		int mid = (nL + nR) / 2;
		return query(node * 2, s, e, nL, mid) + query(node * 2 + 1, s, e, mid + 1, nR);
	}
	int query(int l, int r)
	{
		return query(1, l, dic[r] - 1, 0, sz - 1);
	}
	int update(int idx, int node, int v, int l, int r)
	{
		if (idx < l || r < idx) return tree[node];
		if (l == r) return tree[node] = v;
		int mid = (l + r) / 2;
		return tree[node] = update(idx, node * 2, v, l, mid) + update(idx, node * 2 + 1, v, mid + 1, r);
	}
	int update(int idx, int val)
	{
		return update(dic[idx], 1, val, 0, sz - 1);
	}
	void change(int idx, int val)
	{
		dic[idx] = val;
	}
};
int T, N, M, num;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		vector<int> ans;
		seg sg(N, M);
		sg.init(M);
		int idx = M - 1;
		for (int i = 0; i < M; i++)
		{
			cin >> num;
			num--;
			ans.push_back(sg.query(0, num));
			sg.update(num, 0);
			sg.change(num, idx--);
			sg.update(num, 1);
		}
		anss.push_back(ans);
	}
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < anss[i].size(); j++)
			cout << anss[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/3653