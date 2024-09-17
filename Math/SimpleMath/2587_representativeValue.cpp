#include <iostream>
#include <algorithm>
using namespace std;

int A[5], S = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
	{
		cin >> A[i];
		S += A[i];
	}
	sort(A, A + 5);
	cout << (S / 5) << '\n';
	cout << A[2] << '\n';
}

// https://www.acmicpc.net/problem/2587