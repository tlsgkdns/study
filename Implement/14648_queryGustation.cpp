
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	vector<long long> ps(n + 1, 0);
	vector<long long> ans;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i == 0) ps[i + 1] = arr[i];
		else ps[i + 1] = ps[i] + arr[i];
	}

	for (int j = 0; j < q; j++)
	{
		int k, ret = 0;
		cin >> k;
		if (k == 1)
		{
			int a, b;
			cin >> a >> b;
			int m = arr[a - 1] - arr[b - 1];
			long long t = ps[b] - ps[a];
			ans.push_back(t + arr[a - 1]);
			for (int ind = a; ind < b; ind++)
				ps[ind] -= m;
			swap(arr[a - 1], arr[b - 1]);
		}
		else if (k == 2)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			ans.push_back((ps[b] - ps[a] + arr[a - 1]) - (ps[d] - ps[c] + arr[c - 1]));
		}
	}


	copy(ans.begin(), ans.end(), ostream_iterator<long long>{cout, "\n"});
}
// https://www.acmicpc.net/problem/14648