#include <iostream>
#include <vector>
using namespace std;
bool v[100001];
int N;
vector<int> alp[27];
string str, s1 = "", s2 = "";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> str;
	for (int i = N - 1; i >= 0; i--) alp[str[i] - 'a'].push_back(i);
	int idx = N - 1, r = 0, c = 0;
	while (idx >= 0)
	{
		while (idx >= 0 && v[idx]) --idx;
		if (idx < 0) break;
		v[idx] = true;
		s1.push_back(str[idx]);
		while (r < 26)
		{
			while (alp[r].empty() || c == alp[r].size())
			{
				++r;
				c = 0;
			}
			if (v[alp[r][c]])
			{
				++c;
			}
			else
				break;
		}
		v[alp[r][c]] = true;
		s2.push_back(r + 'a');
	}
	bool lose = true;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] > s2[i]) lose = false;
		if (s1[i] == s2[i]) continue;
		break;
	}
	if (lose) cout << "NE\n";
	else cout << "DA\n";
	cout << s2 << '\n';
}

// https://www.acmicpc.net/problem/2871