#include <iostream>

using namespace std;

int N, T, C, P;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T >> C >> P;
	cout << ((N - 1) / T) * C * P << '\n';
}

// https://www.acmicpc.net/problem/17496