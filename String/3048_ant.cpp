#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, int>> ants;
int N1, N2, T;
string g1, g2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N1 >> N2;
	cin >> g1;
	cin >> g2;
	cin >> T;
	for (int i = N1 - 1; i >= 0; i--)
		ants.push_back(make_pair(g1[i], 1));
	for (int i = 0; i < N2; i++)
		ants.push_back(make_pair(g2[i], -1));
	for (int t = 0; t < T; t++)
	{
		vector<bool> jumped(N1 + N2, false);
		for (int idx = 0; idx < ants.size(); idx++)
		{
			if (idx + ants[idx].second >= 0 && idx + ants[idx].second < ants.size()
				&& ants[idx].second != ants[idx + ants[idx].second].second &&
				!jumped[idx] && !jumped[idx + ants[idx].second])
			{
				jumped[idx] = true;
				jumped[idx + ants[idx].second] = true;
				swap(ants[idx], ants[idx + ants[idx].second]);
			}
		}
	}
	string ans;
	for (pair<char, int> a : ants)
		ans.push_back(a.first);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/3048