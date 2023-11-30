#include <iostream>

using namespace std;

int N, A[1000001], B[1000001], ans = 0;

void push(int idx)
{
	if (B[idx] == 1) B[idx] = 0;
	else B[idx] = 1;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++)
		if (A[i] != B[i])
		{
			push(i);
			if (i < N - 1) push(i + 1);
			if (i < N - 2) push(i + 2);
			++ans;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15729