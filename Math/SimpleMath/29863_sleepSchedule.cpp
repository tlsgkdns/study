#include <iostream>

using namespace std;
int A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	if (A < B) cout << B - A << '\n';
	else cout << 24 + (B - A) << '\n';
}

// https://www.acmicpc.net/problem/29863