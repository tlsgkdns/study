#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	vector<string> input;
	vector<int> score;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	for (string s : input)
	{
		int ans = 0;
		int sc = 1;
		for (char c : s)
			if (c == 'O')
			{
				ans += sc;
				sc++;
			}
			else
				sc = 1;

		score.push_back(ans);
	}

	for (int a : score) cout << a << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/8958