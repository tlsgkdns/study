#include <iostream>

using namespace std;
string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (i > 0 && i % 10 == 0) cout << '\n';
		cout << str[i];
	}
}

// https://www.acmicpc.net/problem/11721