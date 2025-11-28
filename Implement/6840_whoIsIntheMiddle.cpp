#include <iostream>
#include <algorithm>

using namespace std;
int A[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	for (int i = 0; i < 3; i++)cin >> A[i];
	sort(A, A + 3);
	cout << A[1] << '\n';
}

// https://www.acmicpc.net/problem/6840