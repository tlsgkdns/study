#include <iostream>
#include <algorithm>

using namespace std;

int A[10], T;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 10; i++) cin >> A[i];
		sort(A, A + 10);
		cout << A[7] << '\n';
	}
}

// https://www.acmicpc.net/problem/2693