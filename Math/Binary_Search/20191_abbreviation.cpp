#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int ALP = 26;

vector<int> loc[ALP];
string S, T;
int idx = 0, ans = 0, aIdx = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	cin >> T;
	for (int i = 0; i < T.size(); i++) loc[T[i] - 'a'].push_back(i);
	idx = (int)T.size();
	for (int i = 0; i < S.size(); i++)
	{
		aIdx = S[i] - 'a';
		if (loc[aIdx].empty())
		{
			ans = -1;
			break;
		}
		auto iter = upper_bound(loc[aIdx].begin(), loc[aIdx].end(), idx);
		if (iter == loc[aIdx].end())
		{
			idx = loc[aIdx].front();
			ans++;
		}
		else
			idx = *iter;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20191