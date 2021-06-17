#include <iostream>
#include <vector>
using namespace std;

int L;
string ad;

vector<int> getPi(string s)
{
	int j = 0;
	vector<int> pi(L, 0);
	for (int i = 1; i < L; i++)
	{
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = ++j;
	}
	return pi;
}

int main()
{
	cin >> L;
	cin >> ad;
	vector<int> pi = getPi(ad);
	cout << L - pi[L - 1] << '\n';
}

//https://www.acmicpc.net/problem/1305