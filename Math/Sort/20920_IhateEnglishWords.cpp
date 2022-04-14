#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
unordered_map<string, int> dic;
vector<string> arr;
string str;

bool cmp(string& s1, string& s2)
{
	int c1 = dic[s1], c2 = dic[s2];
	if (c1 == c2)
	{
		if (s1.size() == s2.size()) return s1 < s2;
		return s1.size() > s2.size();
	}
	return c1 > c2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str.size() < M) continue;
		if (dic.count(str) == 0)
		{
			dic[str] = 1;
			arr.push_back(str);
		}
		else
			dic[str]++;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (string s : arr) cout << s << '\n';
}

// https://www.acmicpc.net/problem/20920