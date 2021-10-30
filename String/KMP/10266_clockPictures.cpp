#include <iostream>
#include <vector>
using namespace std;

const int M = 360000;
int N, num;

vector<int> makeTable(string str)
{
	vector<int> table(str.size(), 0);
	int j = 0;
	for (int i = 1; i < str.size(); i++)
	{
		while (j > 0 && str[i] != str[j])
			j = table[j - 1];
		if (str[i] == str[j])
			table[i] = ++j;
	}
	return table;
}
bool kmp(string s1, string s2)
{
	vector<int> table = makeTable(s2);
	int j = 0;
	for (int i = 0; i < 2 * M - 1; i++)
	{
		while (j > 0 && s1[i] != s2[j])
			j = table[j - 1];
		if (s1[i] == s2[j])
		{
			if (j == s2.size() - 1)
				return true;
			else
				j++;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str1(2 * M - 1, '0'), str2(M - 1, '0');
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		str1[num] = '1';
		str1[num + M] = '1';
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		str2[num] = '1';
	}
	if (kmp(str1, str2)) cout << "possible\n";
	else cout << "impossible\n";
}
// https://www.acmicpc.net/problem/10266