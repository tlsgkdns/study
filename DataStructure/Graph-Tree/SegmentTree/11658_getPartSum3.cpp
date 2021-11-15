#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr, tree;

int N, M, h = 1;

void update(int x, int y, int v)
{
	int i = y + h - 1, j = x + h - 1;
	tree[i][j] = v;
	while (j > 1)
	{
		j /= 2;
		tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1];
	}

	while (i > 1)
	{
		j = x + h - 1;
		i /= 2;
		tree[i][j] = tree[i * 2][j] + tree[i * 2 + 1][j];
		while (j > 1)
		{
			j /= 2;
			tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1];
		}
	}
}

int xQuery(int y, int nl, int nr, int node, int l, int r)
{
	if (nl <= l && r <= nr) return tree[y][node];
	if (nr < l || r < nl) return 0;
	int m = (l + r) / 2;
	return xQuery(y, nl, nr, node * 2, l, m) + xQuery(y, nl, nr, node * 2 + 1, m + 1, r);
}
int yQuery(int nl, int nr, int node, int l, int r, int x1, int x2)
{
	if (nl <= l && r <= nr) return xQuery(node, x1, x2, 1, 1, h);
	if (nr < l || r < nl) return 0;
	int m = (l + r) / 2;
	return yQuery(nl, nr, node * 2, l, m, x1, x2) + yQuery(nl, nr, node * 2 + 1, m + 1, r, x1, x2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int w, c, x1, x2, y1, y2;
	cin >> N >> M;
	while (h < N) h = (h << 1);
	arr.resize(N + 1, vector<int>(N + 1));
	tree.resize(h * 2, vector<int>(h * 2));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			update(i, j, arr[i][j]);
		}
	vector<int> ans;
	for (int i = 0; i < M; i++)
	{
		cin >> w;
		if (w == 0)
		{
			cin >> x1 >> y1 >> c;
			update(x1, y1, c);
		}
		else
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2)swap(x1, x2);
			if (y1 > y2)swap(y1, y2);
			ans.push_back(yQuery(y1, y2, 1, 1, h, x1, x2));
		}
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/11658