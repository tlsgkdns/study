#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<long long> v(n);
	vector<long long> c(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int id = 0; id < n; id++)
	{
		if (id == 0) c[id] = v[id];
		else if (id == 1) c[id] = v[id - 1] + v[id];
		else if (id == 2) c[id] = max(c[id - 1], max(v[id - 1] + v[id], v[id] + v[id - 2]));
		else
			c[id] = max(c[id - 1], max(c[id - 3] + v[id] + v[id - 1], c[id - 2] + v[id]));
	}

	cout << c[n - 1] << endl;
	return 0;
}

// https://www.acmicpc.net/problem/2156

/*
little confusing problem
*/