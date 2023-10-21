#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> S[101];
int N, ans = 0;
string str, W[101];
bool solve(int idx, int l)
{
	for (int i = 0; i < S[idx].size(); i++)
	{
		int idx1 = 0, idx2 = S[idx][i];
		while (idx1 < str.size() && idx2 < W[idx].size() && str[idx1] == W[idx][idx2])
		{
			idx2 += (l + 1);
			++idx1;
		}
		if (idx1 == str.size())
			return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		cin >> W[i];
		for (int idx = 0; idx < W[i].size(); idx++)
			if (W[i][idx] == str[0])
				S[i].push_back(idx);
	}
	for (int idx = 0; idx < N; idx++)
		for (int l = 0; l * (str.size() - 1) + str.size() <= W[idx].size(); l++)
			if (solve(idx, l))
			{
				++ans;
				break;
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5534