#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	long long n, m;
	vector<pair<long long, long long>> input;
	cin >> n >> m;

	while (n != 0 || m != 0)
	{
		input.push_back(make_pair(n, m));
		cin >> n >> m;
	}

	for (pair<long long, long long> p : input)
	{
		long long div = p.first / p.second;
		long long remain = p.first % p.second;
		cout << div << ' ' << remain << " / " << p.second << '\n';
	}

	return 0;
}

// https://www.acmicpc.net/problem/10474

/*
divide and mod
*/