#include <iostream>
#include <algorithm>
using namespace std;
bool ans = true;
long long N, A[100001];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A + 1, A + N);
	for (int i = 1; i < N; i++)
	{
		if (A[0] <= A[i])
		{
			ans = false;
			break;
		}
		A[0] += A[i];
	}
	if (ans) cout << "Yes\n";
	else cout << "No\n";
}

// https://www.acmicpc.net/problem/22993