#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cards;

int one(const vector<int> v, vector<bool> b, vector<int> c)
{
	if (c.size() == 3)
	{
		int s = 0;
		for (int n : c) s += n;
		return s % 10;
	}
	int m = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (!b[i])
		{
			c.push_back(v[i]);
			b[i] = true;
			m = max(m, one(v, b, c));
			b[i] = false;
			c.pop_back();
		}
	}
	return m;
}
int main()
{
	int n, m = -1, win = 0, id = 1;
	cin >> n;
	cards.resize(n, vector<int>(5));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> cards[i][j];
	}
	vector<int> e;
	vector<bool> b(5, false);
	for (vector<int> cd : cards)
	{
		int o = one(cd, b, e);
		if (o >= m) { win = id; m = o; }
		id++;
	}
	cout << win << endl;
}

// https://www.acmicpc.net/problem/2303

/*
bruteForce is bothersome.
but this is not
*/