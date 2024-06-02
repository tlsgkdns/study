#include <iostream>
#include <set>
#include <vector>
using namespace std;
int N, X, Y, ans = 0;
set<pair<int, int>> pos;
vector<pair<int, int>> input;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		pos.insert({ X, Y });
		input.push_back({ X, Y });
	}
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (input[i].first == input[j].first || input[i].second == input[j].second) continue;
			if (pos.find({ input[i].first, input[j].second }) != pos.end()
				&& pos.find({ input[j].first, input[i].second }) != pos.end())
				++ans;
		}
	cout << ans / 2 << '\n';
}

// https://www.acmicpc.net/problem/2171