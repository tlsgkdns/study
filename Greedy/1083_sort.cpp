#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

vector<int> sort(int s, vector<int>& arr)
{
	vector<int> v;

	while (s > 0 && !arr.empty())
	{
		int l = (s > arr.size() - 1) ? arr.size() - 1 : s;
		auto m = max_element(arr.begin(), arr.begin() + l + 1);
		int dt = m - arr.begin();
		s -= dt;
		v.push_back(*m);
		arr.erase(m);
	}

	for (int e : arr) v.push_back(e);
	return v;
}


int main(void)
{
	int n, s;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cin >> s;

	vector<int> ret = sort(s, v);
	copy(ret.begin(), ret.end(), ostream_iterator<int>{cout, " "});

	return 0;
}
// https://www.acmicpc.net/problem/1083