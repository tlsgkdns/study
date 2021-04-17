#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, v;
int bSearch(int val)
{
	int left = 0, right = v.size() - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (v[mid] >= val) right = mid;
		else left = mid + 1;
	}
	return left;
}
int main()
{
	int n; cin >> n;
	arr = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	v.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		if (v.back() < arr[i])
			v.push_back(arr[i]);
		else
		{
			int idx = bSearch(arr[i]);
			v[idx] = arr[i];
		}
	}
	cout << v.size() - 1 << '\n';
}

// https://www.acmicpc.net/problem/12015