#include <iostream>

int A, B;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> A >> B;
		if (A == 0 && B == 0) break;
		if (B % A == 0) cout << "factor\n";
		else if (A % B == 0) cout << "multiple\n";
		else cout << "neither\n";
	}
}

// https://www.acmicpc.net/problem/5086