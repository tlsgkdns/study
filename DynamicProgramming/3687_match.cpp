#include <iostream>
using namespace std;

int match[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string dp1[101][2], dp2[101][2];
int N, T;
bool cmp(string& s1, string& s2)
{
	if (s1.size() != s2.size()) return s1.size() < s2.size();
	for (int i = 0; i < (int)s1.size(); i++)
		if (s1[i] != s2[i])
			return s1[i] < s2[i];
	return false;
}
string solve1(int n, bool f)
{
	if (n == 0) return "";
	string& ret = dp1[n][f];
	if (!ret.empty()) return ret;
	for (int i = (f) ? 1 : 0; i < 10; i++)
	{
		if (n < match[i]) continue;
		char b = (i + '0');
		string s = b + solve1(n - match[i], false);
		if (ret.empty() || cmp(ret, s)) ret = s;
	}
	return ret;
}
string solve2(int n, bool f)
{
	if (n == 0) return "";
	if (n == 1) return "99";
	string& ret = dp2[n][f];
	if (!ret.empty()) return ret;
	for (int i = (f) ? 1 : 0; i < 10; i++)
	{
		if (n < match[i]) continue;
		char b = (i + '0');
		string s = b + solve2(n - match[i], false);
		if (ret.empty() || !cmp(ret, s)) ret = s;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << solve2(N, true) << " " << solve1(N, true) << '\n';
	}
}

// https://www.acmicpc.net/problem/3687