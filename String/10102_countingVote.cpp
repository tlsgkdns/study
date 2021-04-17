#include <iostream>

using namespace std;

int main()
{
	int n, a = 0, b = 0;
	cin >> n;
	string s;
	cin >> s;

	for (char c : s)
		if (c == 'A') a++;
		else b++;

	if (a == b) cout << "Tie";
	else if (a > b) cout << "A";
	else cout << "B";
	cout << endl;
}

// https://www.acmicpc.net/problem/10102