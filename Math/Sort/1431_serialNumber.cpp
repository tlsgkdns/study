#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

bool cmp(string& s1, string& s2)
{
	if (s1.size() == s2.size())
	{
		int a1 = 0, a2 = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			if (isdigit(s1[i])) a1 += s1[i] - '0';
			if (isdigit(s2[i])) a2 += s2[i] - '0';
		}
		if (a1 == a2) return s1 < s2;
		return a1 < a2;
	}
	return s1.size() < s2.size();
}
string S;
vector<string> A;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		A.push_back(S);
	}
	sort(A.begin(), A.end(), cmp);
	for (int i = 0; i < N; i++) cout << A[i] << '\n';
}


// https://www.acmicpc.net/problem/1431