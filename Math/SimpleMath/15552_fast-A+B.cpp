#include <iostream>
#include <vector>

using namespace std;

int cache[1000001];


int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> l;
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		l.push_back(a + b);
	}

	for (int e : l)
		cout << e << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/15552

/*
cin.tie(NULL); ios_base::sync_with_stdio(false);
magic for fast
*/