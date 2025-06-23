#include <iostream>

using namespace std;

int N;
string K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> K;
		int n = (K.back() - '0');
		if (n % 2 > 0) cout << "odd\n";
		else cout << "even\n";
	}
}

// https://www.acmicpc.net/problem/5988