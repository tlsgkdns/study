#include <iostream>
using namespace std;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i; j > 0; j--) cout << " ";
		for (int j = 0; j <= N - i - 1; j++)
			cout << "* ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/10991