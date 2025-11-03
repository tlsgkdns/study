#include <iostream>

using namespace std;
int A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C; C *= 2;
	A += B;
	if (A < C) cout << A << '\n';
	else cout << A - C << '\n';
}

// https://www.acmicpc.net/problem/14489