#include <iostream>
#include <cmath>

using namespace std;
int A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> A >> B; --A; --B;
	cout << abs((A % 4) - (B % 4)) + abs((A / 4) - (B / 4)) << '\n';
}

// https://www.acmicpc.net/problem/1598