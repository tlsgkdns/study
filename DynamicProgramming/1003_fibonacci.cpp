#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> cache;

pair<int, int> fib(int n)
{
	if (cache[n] == pair<int, int>(0, 0))
	{
		cache[n] = make_pair(fib(n - 1).first + fib(n - 2).first,
			fib(n - 1).second + fib(n - 2).second);
	}

	return cache[n];
}
int main(void)
{
	vector<int> v;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	cache = vector<pair<int, int>>(41, make_pair(0, 0));
	cache[0] = make_pair(1, 0);
	cache[1] = make_pair(0, 1);

	for (int e : v)
	{
		pair<int, int> p = fib(e);
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}

// https://www.acmicpc.net/problem/1003