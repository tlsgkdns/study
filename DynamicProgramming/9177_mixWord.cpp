#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
bool combine(string s1, string s2, string s3)
{
	int a = s1.length(), b = s2.length();
	queue<pair<int, int>> q;
	vector<vector<bool>> dp(a + 1, vector<bool>(b + 1, false));
	q.push({ 0, 0 });
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		if (s1.length() == p.first && s2.length() == p.second)
			return true;
		if (dp[p.first][p.second]) continue;
		dp[p.first][p.second] = true;
		int nxt = (p.first + p.second);
		if (s1[p.first] == s3[nxt])
			q.push(make_pair(p.first + 1, p.second));
		if (s2[p.second] == s3[nxt])
			q.push(make_pair(p.first, p.second + 1));
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<string> ans;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
		string r = combine(s1, s2, s3) ? "yes" : "no";
		ans.push_back("Data set " + to_string(i) + ": " + r + "\n");
	}
	for (string a : ans)
		cout << a;
}

// https://www.acmicpc.net/problem/9177