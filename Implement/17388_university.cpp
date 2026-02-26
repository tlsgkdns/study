#include <iostream>
using namespace std;

int S, K, H, s = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S >> K >> H;
	s = S + K + H;
	if (s >= 100) cout << "OK\n";
	else if (S < K && S < H) cout << "Soongsil\n";
	else if (K < S && K < H) cout << "Korea\n";
	else cout << "Hanyang\n";
}

// https://www.acmicpc.net/problem/17388