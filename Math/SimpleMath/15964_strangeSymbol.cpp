#include <iostream>

using namespace std;
long long A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	cout << (A + B) * (A - B) << '\n';
}

// https://www.acmicpc.net/problem/15964