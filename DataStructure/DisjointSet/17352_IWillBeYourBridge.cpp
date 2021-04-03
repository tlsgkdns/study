#include <iostream>
#include <vector>
using namespace std;

struct dset
{
	vector<int> arr;
	vector<int> rank;

	int l;
	dset(int n)
	{
		l = n;
		arr.resize(n + 1);
		rank.resize(n + 1, 1);
		for (int i = 1; i <= n; i++)
			arr[i] = i;
	}
	int find(int a)
	{
		if (a == arr[a]) return a;

		return arr[a] = find(arr[a]);
	}
	void merge(int a, int b)
	{
		if (rank[a] < rank[b]) merge(b, a);

		int f1 = find(a);
		int f2 = find(b);
		arr[f2] = f1;
		if (rank[f1] == rank[f2]) rank[f2]++;
	}

	pair<int, int> solve()
	{
		int p = 1;
		for (int i = 1; i <= l; i++)
		{
			if (find(p) != find(i))
				return make_pair(p, i);
		}
		return make_pair(0, 0);
	}
};
int main()
{
	int n; cin >> n;
	dset s(n);
	for (int i = 0; i < n - 2; i++)
	{
		int b1, b2;
		cin >> b1 >> b2;
		s.merge(b1, b2);
	}
	pair<int, int> ans = s.solve();
	cout << ans.first << " " << ans.second << '\n';
}

//https://www.acmicpc.net/problem/17352

/*
easy Disjointset problem.
*/