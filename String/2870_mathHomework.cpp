#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

vector<string> ans;
int N;
string str, tmp = "";

bool cmp(string& s1, string& s2)
{
	if (s1.size() == s2.size())
		for (int i = 0; i < s1.size(); i++)
			if (s1[i] != s2[i])
				return s1[i] < s2[i];
	return s1.size() < s2.size();
}
void pushAns()
{
	int j = 0;
	while (j < tmp.size() && tmp[j] == '0') ++j;
	if (j == tmp.size()) ans.push_back("0");
	else ans.push_back(string(tmp.begin() + j, tmp.end()));
	tmp = "";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int idx = 0; idx < str.size(); idx++)
		{
			if (isdigit(str[idx]))
			{
				tmp.push_back(str[idx]);
			}
			else if (!tmp.empty()) pushAns();
		}
		if (!tmp.empty()) pushAns();
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/2870