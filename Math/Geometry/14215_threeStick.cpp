#include <iostream>
#include <algorithm>

using namespace std;

int A[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	for (int i = 0; i < 3; i++) cin >> A[i];
	sort(A, A + 3);
	if (A[0] + A[1] > A[2]) cout << A[0] + A[1] + A[2] << '\n';
	else cout << 2 * A[0] + 2 * A[1] - 1 << '\n';
}

// https://www.acmicpc.net/problem/14215