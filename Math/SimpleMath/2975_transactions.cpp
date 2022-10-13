#include <iostream>

using namespace std;
int A, B;
char ch;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> A >> ch >> B;
		if (A == 0 && ch == 'W' && B == 0) break;
		if (ch == 'W') A -= B;
		else A += B;
		if (A < -200) cout << "Not allowed\n";
		else cout << A << '\n';
	}
}

// https://www.acmicpc.net/problem/2975