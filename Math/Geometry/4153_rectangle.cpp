#include <iostream>
#include <algorithm>

using namespace std;

int A[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> A[0] >> A[1] >> A[2];
		if (A[0] == 0 && A[1] == 0 && A[2] == 0) break;
		sort(A, A + 3);
		if (A[0] * A[0] + A[1] * A[1] == A[2] * A[2]) cout << "right\n";
		else cout << "wrong\n";
	}
}

// https://www.acmicpc.net/problem/4153