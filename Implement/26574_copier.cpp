#include <iostream>

using namespace std;
int N, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> n;
		cout << n << " " << n << '\n';
	}
}

// https://www.acmicpc.net/problem/26574