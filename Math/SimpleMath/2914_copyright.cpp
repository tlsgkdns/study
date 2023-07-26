#include <iostream>
using namespace std;
int A, B;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	B = (A * B) - (A - 1);
	cout << B << '\n';
}

// https://www.acmicpc.net/problem/2914