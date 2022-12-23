#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
string str;
char f(char ch)
{
	if (isupper(ch)) return tolower(ch);
	return toupper(ch);
}
int main()
{
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), f);
	cout << str << '\n';
}

// https://www.acmicpc.net/problem/2744