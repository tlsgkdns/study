#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, m;
	vector<bool> p(10001, true);
	p[0] = p[1] = false;

	cin >> n;
	vector<int> inp;
	for (int c = 0; c < n; c++)
	{
		int tm;
		cin >> tm;
		inp.push_back(tm);
	}

	m = *max_element(inp.begin(), inp.end());

	int q = int(sqrt(m));
	for (int i = 2; i < q; i++)
		if (p[i])
			for (int j = i * i; j < m; j += i)
				p[j] = false;
	vector<int> g;
	for (int number : inp)
		for (int num = number / 2; num < number; num++)
		{
			if (p[num] && p[number - num])
			{
				g.push_back(num);
				break;
			}
		}

	for (int ind = 0; ind < inp.size(); ind++)
		cout << inp[ind] - g[ind] << " " << g[ind] << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/9020

/*
Eratosthenes to mark prime
half to n for divide
*/