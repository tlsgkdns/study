#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int turret(pair<int, int> pos1, int r1, pair<int, int> pos2, int r2)
{
	int big = (r1 > r2) ? r1 : r2;
	int small = (r1 > r2) ? r2 : r1;

	float dist = sqrt(pow(pos1.first - pos2.first, 2) + pow(pos1.second - pos2.second, 2));

	if (big > dist)
	{
		if (pos1 == pos2)
			if (r1 == r2) return -1;

		if (small + dist < big)
			return 0;
		if (small + dist == big)
			return 1;
		if (small + dist > big)
			return 2;
	}

	if (dist > r1 + r2)
		return 0;
	if (dist == r1 + r2)
		return 1;
	if (dist < r1 + r2)
		return 2;
}

int main(void)
{
	vector<vector<int>> input;
	int n;
	string line;

	cin >> n;
	getline(cin, line);
	for (int i = 0; i < n; i++)
	{
		getline(cin, line);
		istringstream ss(line);
		vector<int> tmp;
		string buffer;

		while (getline(ss, buffer, ' '))
		{
			tmp.push_back(atoi(buffer.c_str()));
		}

		input.push_back(tmp);
	}

	for (vector<int> e : input)
	{
		cout << turret(make_pair(e[0], e[1]), e[2], make_pair(e[3], e[4]), e[5]) << endl;
	}

	return 0;
}

// https://www.acmicpc.net/problem/1002