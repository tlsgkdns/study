#include <iostream>
#include <vector>
using namespace std;
vector<int> book;
int main()
{
	int s = 1, n, floor = 0;
	cin >> n;
	book.resize(n);
	int nxt = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> book[i];
		if (book[i] == n) floor = i;
	}

	for (int i = floor - 1; i >= 0; i--)
	{
		if (book[i] == nxt) { s++; nxt--; }
	}

	cout << n - s << '\n';
}

// https://www.acmicpc.net/problem/2872
/*
little hard to came up.
*/