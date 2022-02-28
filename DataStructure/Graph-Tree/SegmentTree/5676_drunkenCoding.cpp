#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, tree;
vector<vector<int>> ans;
int N, K;

int neg(int num)
{
	if (num > 0) return 1;
	if (num < 0) return -1;
	return 0;
}
int init(int node, int left, int right)
{
	if (left == right) return tree[node] = neg(arr[left]);
	int mid = (left + right) / 2;
	return tree[node] = init(node * 2, left, mid) * init(node * 2 + 1, mid + 1, right);
}
int query(int l, int r, int nl, int nr, int node)
{
	if (nl > r || nr < l) return 1;
	if (nr <= r && nl >= l) return tree[node];
	int mid = (nl + nr) / 2;
	return query(l, r, nl, mid, node * 2) * query(l, r, mid + 1, nr, node * 2 + 1);
}
int update(int id, int v, int node, int nl, int nr)
{
	if (id < nl || nr < id) return tree[node];
	if (nl == nr) return tree[node] = neg(v);
	int mid = (nl + nr) / 2;
	return tree[node] = update(id, v, node * 2, nl, mid) * update(id, v, node * 2 + 1, mid + 1, nr);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N >> K;
		if (cin.eof()) break;
		ans.push_back(vector<int>());
		arr = vector<int>(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		tree = vector<int>(N * 4);
		init(1, 0, N - 1);
		char cmd; int I, J;
		for (int i = 0; i < K; i++)
		{
			cin >> cmd >> I >> J;
			if (cmd == 'C')
				update(I - 1, J, 1, 0, N - 1);
			else
				ans.back().push_back(query(I - 1, J - 1, 0, N - 1, 1));
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			if (ans[i][j] == 0) cout << 0;
			else if (ans[i][j] > 0) cout << "+";
			else cout << "-";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/5676