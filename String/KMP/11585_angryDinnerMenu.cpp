#include <iostream>
#include <vector>
using namespace std;

string R = "", M = "";
int N, ans = 0;
char ch;

vector<int> getPi(string& str)
{
	int n = str.size();
	int idx = 0;
	vector<int> ret(n, 0);
	for (int i = 1; i < n; i++)
	{
		while (idx > 0 && str[i] != str[idx])
			idx = ret[idx - 1];
		if (str[idx] == str[i]) ret[i] = ++idx;
	}
	return ret;
}
void kmp(string& s1, string& s2)
{
	vector<int> table = getPi(s2);
	int idx = 0, n = s1.size(), m = s2.size();
	for (int i = 0; i < n; i++)
	{
		while (idx > 0 && s1[i] != s2[idx])
			idx = table[idx - 1];
		if (s1[i] == s2[idx])
		{
			if (idx == m - 1)
			{
				ans++;
				idx = table[idx];
			}
			else
				++idx;
		}
	}
}
int E(int a, int b)
{
	return ((a % b) ? E(b, a % b) : b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ch;
		R.push_back(ch);
	}
	R += R;
	R.pop_back();
	for (int i = 0; i < N; i++)
	{
		cin >> ch;
		M.push_back(ch);
	}
	kmp(R, M);
	int r = E(N, ans);
	cout << (ans / r) << "/" << (N / r) << '\n';
}

// https://www.acmicpc.net/problem/11585