#include <iostream>

using namespace std;
int A, S = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> A;
		if (cin.eof()) break;
		S += A;
	}
	cout << S << '\n';
}

// https://www.acmicpc.net/problem/11023