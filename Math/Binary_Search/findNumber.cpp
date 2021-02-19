#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> st;
bool binary(int l, int r, long long a)
{
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (st[m] == a) return true;
		if (st[m] > a) r = m - 1;
		else l = m + 1;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n;
	st.resize(n);
	for (int i = 0; i < n; i++)
		cin >> st[i];
	sort(st.begin(), st.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		long long a;
		cin >> a;
		cout << binary(0, st.size() - 1, a) << '\n';
	}
}

// https://www.acmicpc.net/problem/1920

/*
sort and binary_search is the only solution.
But,recursion is not solution.
Only "Times out" will waiting for you
*/