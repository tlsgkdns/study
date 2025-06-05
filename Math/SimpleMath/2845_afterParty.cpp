#include <iostream>

using namespace std;
int L, P, N[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L >> P;
	for (int i = 0; i < 5; i++) cin >> N[i];
	L *= P;
	for (int i = 0; i < 5; i++) cout << N[i] - L << " ";
}

// https://www.acmicpc.net/problem/2845