#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int c[11];

int main(void)
{
	string s;
	cin >> s;

	sort(s.begin(), s.end(), greater<char>());
	cout << s << endl;
	return 0;
}

// https://www.acmicpc.net/problem/1427