#include <iostream>
#include <string>
using namespace std;

int N;
string ans = "";
bool isBad(string& str)
{
	int l = str.size();
	if (l == 1) return false;
	for (int i = 0; i < l; i++)
		for (int j = i; j < l; j++)
		{
			string cmp1(str.begin() + i, str.begin() + j + 1);
			int step = j - i + 1, s = j + 1;
			if (s + step <= l)
			{
				string cmp2(str.begin() + s, str.begin() + s + step);
				if (cmp1 == cmp2) return true;
			}
		}
	return false;
}
void solve(string& str)
{
	if (ans != "") return;
	if (str.size() == N)
	{
		ans = str;
		return;
	}
	for (int n = 1; n <= 3; n++)
	{
		str.push_back(n + '0');
		if (!isBad(str)) solve(str);
		str.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	string a = "";
	solve(a);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2661