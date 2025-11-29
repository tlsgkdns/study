#include <iostream>

using namespace std;
int A[3], C[3];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	for (int i = 0; i < 3; i++) cin >> A[i];
	for (int i = 0; i < 3; i++) cin >> C[i];
	cout << C[0] - A[2] << " " << C[1] / A[1] << " " << C[2] - A[0] << '\n';
}

// https://www.acmicpc.net/problem/17256