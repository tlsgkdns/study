#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> poss;
vector<vector<bool>> chess(6, vector<bool>(6, false));
int main()
{
	string pos;
	for (int i = 0; i < 36; i++)
	{
		cin >> pos;
		int y = pos[0] - 'A';
		int x = pos[1] - '1';
		poss.push_back({ y, x });
	}
	poss.push_back(poss[0]);
	int idx = 1;
	for (; idx < 37; idx++)
	{
		if (!((abs(poss[idx - 1].first - poss[idx].first) == 1 &&
			abs(poss[idx - 1].second - poss[idx].second) == 2) ||
			(abs(poss[idx - 1].first - poss[idx].first) == 2 &&
				abs(poss[idx - 1].second - poss[idx].second) == 1))
			|| chess[poss[idx].first][poss[idx].second])
			break;
		chess[poss[idx].first][poss[idx].second] = true;
	}
	if (idx == 37) cout << "Valid\n";
	else cout << "Invalid\n";
}
// https://www.acmicpc.net/problem/1331