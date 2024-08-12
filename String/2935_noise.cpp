#include <iostream>
#include <algorithm>
using namespace std;

string A, B;
char ch;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A;
	cin >> ch;
	cin >> B;
	if (A.size() < B.size()) swap(A, B);
	if (ch == '+')
	{
		if (A.size() == B.size())
		{
			A[0] = '2';
			cout << A << '\n';
		}
		else
		{
			A[A.size() - B.size()] = '1';
			cout << A << '\n';
		}
	}
	else
	{
		string ans = "";
		for (int i = 0; i < A.size() - 1; i++) ans.push_back('0');
		for (int i = 0; i < B.size() - 1; i++) ans.push_back('0');
		if (A == "0" || B == "0") ans = "0";
		else ans.push_back('1');
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/2935