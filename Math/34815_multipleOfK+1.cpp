#include <iostream>
using namespace std;

int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> K;
	if (K % 2 == 1 && N == K) cout << "NO\n";
	else cout << "YES\n";
}

// https://www.acmicpc.net/problem/34815