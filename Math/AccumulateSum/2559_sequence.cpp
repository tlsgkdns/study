#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr, psum, sub;
int main()
{
	int n, k; cin >> n >> k;
	arr.resize(n); psum.resize(n); sub.resize(n - (k - 1));
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i == 0) psum[i] = arr[i];
		else psum[i] = psum[i - 1] + arr[i];
	}
	for (int i = k - 1, j = 0; i < n; i++, j++)
	{
		if (i == k - 1)
			sub[j] = psum[i];
		else
			sub[j] = psum[i] - psum[j - 1];
	}
	cout << *max_element(sub.begin(), sub.end()) << endl;
}

// https://www.acmicpc.net/problem/2559