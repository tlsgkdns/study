#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		getline(cin, L);
		if (L == "END") break;
		reverse(L.begin(), L.end());
		cout << L << '\n';
	}

}

// https://www.acmicpc.net/problem/11365