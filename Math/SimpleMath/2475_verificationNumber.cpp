#include <iostream>
using namespace std;
int n, s = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		s += n * n;
	}
	cout << s % 10 << '\n';
}

// https://www.acmicpc.net/problem/2475