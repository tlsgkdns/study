#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<int> r;
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		r.push_back(a + b);
	}

	copy(r.begin(), r.end(), ostream_iterator<int>{cout, "\n"});
}

// https://www.acmicpc.net/problem/10950