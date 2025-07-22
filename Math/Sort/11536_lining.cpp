#include <iostream>
#include <algorithm>

using namespace std;

int N;
string A[21], B[21];

bool chk()
{
	for (int i = 0; i < N; i++)
		if (A[i] != B[i])
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B, B + N);
	if (chk()) cout << "INCREASING\n";
	else
	{
		sort(B, B + N, greater<string>());
		if (chk()) cout << "DECREASING\n";
		else cout << "NEITHER\n";
	}
}

// https://www.acmicpc.net/problem/11536