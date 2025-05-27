#include <iostream>

using namespace std;
int N, X, Y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> X >> Y;
		cout << X + Y << '\n';
	}
}

// https://www.acmicpc.net/problem/7891