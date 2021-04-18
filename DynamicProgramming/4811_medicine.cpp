#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <stack>

using namespace std;

vector<vector<long long>> c(61, vector<long long>(61, 0));

long long med(float n, stack<bool> s)
{
	int index = n * 2;
	long long& ret = c[index][s.size()];
	if (ret != 0) return ret;
	if (n == 1 || n * 2 == s.size()) return ret = 1;

	s.push(true);
	long long l = med(n - 0.5f, s);
	s.pop();
	long long r = 0;
	if (!s.empty())
	{
		s.pop();
		r = med(n - 0.5f, s);
	}

	return ret = l + r;
}
int main()
{
	float tmp = -1.0f;
	vector<float> input;
	vector<long long> result;
	while (tmp != 0)
	{
		cin >> tmp;
		input.push_back(tmp);
	}
	input.pop_back();
	stack<bool> s;
	for (float m : input)
	{
		long long r = med(m, s);
		result.push_back(r);
		while (!s.empty()) s.pop();
	}

	for (long long r : result)
		cout << r << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/4811