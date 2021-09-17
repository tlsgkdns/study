#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Dset
{
	vector<int> arr;
	Dset(int N)
	{
		arr.resize(N);
		for (int i = 0; i < N; i++)
			arr[i] = i;
	}
	int find(int a)
	{
		if (arr[a] == a) return a;
		return arr[a] = find(arr[a]);
	}
	void merge(int a, int b)
	{
		int p = find(a);
		int q = find(b);
		if (p < q) swap(p, q);
		arr[p] = q;
	}
};
int T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, M, a, b, s = 0;
		cin >> N >> M;
		vector<pair<int, int>> v;
		for (int m = 0; m < M; m++)
		{
			cin >> a >> b;
			v.push_back({ a, b });
		}
		Dset dset(N + 1);
		for (int i = 0; i < v.size(); i++)
		{
			if (dset.find(v[i].first) == dset.find(v[i].second)) continue;
			dset.merge(v[i].first, v[i].second);
			s++;
		}
		ans.push_back(s);
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/9372