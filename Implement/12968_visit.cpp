#include <iostream>

using namespace std;

int R, C, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> K;
	if (K > 1 && (R * C) % 2 > 0) cout << 0 << '\n';
	else cout << 1 << '\n';
}

// https://www.acmicpc.net/problem/12968