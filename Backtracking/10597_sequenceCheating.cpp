#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ans;
string str;
bool v[51], f = false;
void solve(int idx)
{
	if (f) return;
	if (str.size() == idx)
	{
		int n = 1;
		while (v[n]) n++;
		if (ans.size() != n - 1) return;
		f = true;
		for (int i = 0; i < (int)ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	string num = "";
	num.push_back(str[idx]);
	int n1 = stoi(num);
	if (!v[n1])
	{
		v[n1] = true;
		ans.push_back(n1);
		solve(idx + 1);
		v[n1] = false;
		ans.pop_back();
	}
	if (idx < str.size() - 1)
	{
		num.push_back(str[idx + 1]);
		int n2 = stoi(num);
		if (n2 <= 50 && !v[n2])
		{
			v[n2] = true;
			ans.push_back(n2);
			solve(idx + 2);
			v[n2] = false;
			ans.pop_back();
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	solve(0);
}

// https://www.acmicpc.net/problem/10597