#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


void count(vector<int> arr, vector<bool>& v, int cur)
{
	int next = arr[cur];
	if (v[next]) return;
	v[next] = true;
	count(arr, v, next);
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);
	vector<bool> v(n + 1, false);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int k = 1; k <= n; k++)
	{
		vector<int> s;
		vector<bool> prev(v);
		count(arr, v, k);
		if (!v[k])
			v = prev;
	}

	cout << count_if(v.begin(), v.end(), [](bool b) {return b; }) << '\n';
	for (int l = 1; l <= n; l++)
		if (v[l]) cout << l << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/2668