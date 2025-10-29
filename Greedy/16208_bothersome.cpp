#include <iostream>
#include <algorithm>

using namespace std;
int N;
long long S = 0, ans = 0, A[500001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		S += A[i];
	}
	sort(A, A + N);
	for (int i = 0; i < N; i++)
	{
		S -= A[i];
		ans += (A[i] * S);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16208