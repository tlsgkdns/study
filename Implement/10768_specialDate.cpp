#include <iostream>

using namespace std;
int M, D;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> D;
	if (M < 2) ans = -1;
	else if (M > 2) ans = 1;
	else if (D < 18) ans = -1;
	else if (D > 18) ans = 1;
	if (ans < 0) cout << "Before\n";
	else if (ans > 0) cout << "After\n";
	else cout << "Special\n";
}

// https://www.acmicpc.net/problem/10768