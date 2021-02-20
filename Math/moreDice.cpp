#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	string t;
	vector<int> input;
	cin >> n;

	getline(cin, t);
	for (int i = 0; i < n; i++)
	{
		string tmp;
		getline(cin, tmp);
		input.push_back(stoi(tmp));
	}

	for (int cs = 1; cs <= n; cs++)
	{
		cout << "Case " << cs << ":" << endl;
		int in = input[cs - 1];
		for (int j = 1; j <= (in / 2); j++)
		{
			if ((in - j) > 6) continue;
			cout << "(" << j << ',' << (in - j) << ")" << endl;
		}
	}

	return 0;
}

// https://www.acmicpc.net/problem/9288

/*
simple math problem
*/