#include <iostream>
using namespace std;

char c1, c2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> c1 >> c2;
	if (c1 == c2) cout << "1\n";
	else cout << "0\n";
}

// https://www.acmicpc.net/problem/27324