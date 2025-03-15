#include <iostream>
#include <algorithm>
using namespace std;
int N;
string S[1001];

bool cmp(string& s1, string& s2)
{
	string str1 = "", str2 = "";
	for (int i = 0; i < s1.size(); i++)
		str1.push_back(tolower(s1[i]));
	for (int i = 0; i < s2.size(); i++)
		str2.push_back(tolower(s2[i]));
	return str1 < str2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++)
		{
			cin >> S[i];
		}
		sort(S, S + N, cmp);
		cout << S[0] << '\n';
	}
}


// https://www.acmicpc.net/problem/2204