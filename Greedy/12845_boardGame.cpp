#include <iostream>
#include <algorithm>

using namespace std;
int N, L[1001], M = 0, S = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> L[i];
		S += L[i];
		M = max(L[i], M);
	}
	S -= M;
	cout << S + M * (N - 1) << '\n';
}

// https://www.acmicpc.net/problem/12845