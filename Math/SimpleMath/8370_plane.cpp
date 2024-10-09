#include <iostream>

using namespace std;

int a, b, c, d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c >> d;
	cout << (a * b) + (c * d) << '\n';
}

// https://www.acmicpc.net/problem/8370